/*
** ia_incantation.c for ia_incantation in /u/all/yurdus_y/cu/rendu/c/Zappy2009/server/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:24:07 2009 yavuz yurdusev
** Last update Sat Apr 25 12:03:20 2009 yavuz yurdusev
*/

#include <string.h>

#include "ia_command.h"

static void	victory(t_world *world)
{
  putstr("VICTOIRE de l'equipe :");
  putstr(world->victory_team->name);
  my_putchar('\n');
  if (world->pgui)
    gui_seg(world, world->victory_team->name);
}

static void	manage_victory(t_world *world, t_cli *ia)
{
  ia->team->nb_lvl_max++;
  if (ia->team->nb_lvl_max >= NB_LVL_MAX)
    world->victory_team = ia->team;
}

/*
** Incremente de 1 le level de tous les joueurs sur la case a
** la fin de l'incantation
*/
static void	level_up_players(t_world *world, t_cli *ia)
{
  t_pcli	*list;
  char		new_lvl[INT_LEN];

  list = world->map[ia->pos.y][ia->pos.x].pcli;
  while (list != NULL)
    {
      list->lcli->lvl += 1;
      list->lcli->elevation = 0;
      atio(list->lcli->lvl, new_lvl);
      save_cmd(list->lcli, MSG_ELEV, strlen(MSG_ELEV), 'W');
      save_cmd(list->lcli, new_lvl, strlen(new_lvl), 'W');
      save_cmd(list->lcli, "\n", 1, 'W');
      if (list->lcli != ia)
	reinit_statut(world, list->lcli);
      if (world->pgui != NULL)
	gui_plv_serv(world, list->lcli);
      if (list->lcli->lvl == LVL_MAX)
	manage_victory(world, ia);
      list = list->next;
    }
  if (world->victory_team)
    victory(world);
}

static void	error_incantation(t_world *world, t_cli *ia)
{
  t_pcli	*list;

  list = world->map[ia->pos.y][ia->pos.x].pcli;
  while (list != NULL)
    {
      if (list->lcli->elevation == 1)
	{
	  if (world->pgui != NULL)
	    gui_plv_serv(world, list->lcli);
	  save_cmd(list->lcli, MSG_KO, LEN_KO, 'W');
	  if (list->lcli != ia)
	    reinit_statut(world, list->lcli);
	  list->lcli->elevation = 0;
	}
      list = list->next;
    }
}

/*
** Fin de l'incantation
** verifier que le champs incantation de la case est
** toujours vrai
*/
void	ia_incantation(t_world *world, t_cli *ia)
{
  putstr("\033[33mClient numero : ");
  print_nb(ia->numero);
  putstr(" incantation\n\033[39m");
  if (world->map[ia->pos.y][ia->pos.x].elevation)
    {
      if (world->pgui != NULL)
	gui_pie(world, ia->pos.y, ia->pos.x, '1');
      world->map[ia->pos.y][ia->pos.x].elevation = 0;
      level_up_players(world, ia);
      move_ressource(world, ia->pos.y, ia->pos.x);
    }
  else
    error_incantation(world, ia);
}
