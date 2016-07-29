/*
** func_ia.c for func_ia in /u/all/yurdus_y/cu/rendu/c/Zappy2009/server/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:31:26 2009 yavuz yurdusev
** Last update Sun Apr 26 19:38:12 2009 yavuz yurdusev
*/

#include <string.h>
#include <sys/time.h>

#include "buffer.h"
#include "ia_command.h"

static void	welcome_ia(t_world *world, t_team *team, t_cli *ia)
{
  char		nb[INT_LEN];
  int		len_nb;

  len_nb = atio(team->nb_client, nb);
  save_cmd(ia, nb, len_nb, 'W');
  save_cmd(ia, MSG_END, LEN_END, 'W');
  len_nb = atio(world->width, nb);
  save_cmd(ia, nb, len_nb, 'W');
  save_cmd(ia, MSG_SEP, LEN_SEP, 'W');
  len_nb = atio(world->height, nb);
  save_cmd(ia, nb, len_nb, 'W');
  save_cmd(ia, MSG_END, LEN_END, 'W');
  putstr("\033[35mNew ia connected on socket :");
  print_nb(ia->sock);
  putstr("\033[39m\n");
}

/*
** connexion d un nouveau joueur et utilisation d une structure ghost
*/
static void	transfer_ghost(t_world *world,
			       t_team *team,
			       t_cli *ia,
			       t_cli *ghost)
{
  ia->statut = NOACTION;
  ia->lvl = ghost->lvl;
  ia->team = ghost->team;
  init_inventaire(&(ia->invent));
  ia->invent.objet[FOOD] = DEFAULT_FOOD;
  ia->elevation = 0;
  ia->t_cur_cmd.tv_sec = ghost->t_cur_cmd.tv_sec;
  ia->t_cur_cmd.tv_usec = ghost->t_cur_cmd.tv_usec;
  ia->t_alive.tv_sec = ghost->t_alive.tv_sec;
  ia->t_alive.tv_usec = ghost->t_alive.tv_usec;
  ia->pos.direction = ghost->pos.direction;
  ia->pos.x = ghost->pos.x;
  ia->pos.y = ghost->pos.y;
  remove_pcli(&(world->map[ghost->pos.y][ghost->pos.x].pcli), ghost->pcli);
  add_pcli(&(world->map[ia->pos.y][ia->pos.x].pcli), ia->pcli);
  welcome_ia(world, team, ghost);
  if (world->pgui != NULL)
    {
      gui_ebo(world, ghost->numero);
      gui_pnw_serv(world, ghost);
    }
  ghost->sock = DEAD;
  ghost->statut = DEAD;
}

/*
** Connexion d un nouveau joueur
*/
static void	set_new_ia(t_world *world, t_cli *ia, t_team *team)
{
  init_position(world, ia);
  gen_ressource(world);
  ia->statut = NOACTION;
  ia->lvl = 1;
  ia->team = team;
  init_inventaire(&(ia->invent));
  ia->invent.objet[FOOD] = DEFAULT_FOOD;
  ia->elevation = 0;
  set_timeval(world, &(ia->t_cur_cmd), NOACTION);
  set_timeval(world, &(ia->t_alive), LIFETIME);
  welcome_ia(world, team, ia);
  if (world->pgui != NULL)
    gui_pnw_serv(world, ia);
}

void		set_ia_team(t_world *world, t_cli *ia, char *cmd)
{
  t_team	*team;
  t_cli		*ghost;

  team = world->team;
  while (team)
    {
      if (cmd_cmp(cmd, team->name))
	{
	  if (team->nb_client)
	    {
	      team->nb_client--;
	      ghost = find_egg(world, team);
	      if (ghost)
		transfer_ghost(world, team, ia, ghost);
	      else
		set_new_ia(world, ia, team);
	      return ;
	    }
	  break;
	}
      team = team->next;
    }
  ultra_kill(world, ia);
}

/*
** Retourne un pointeur sur la structure du client qui a le num_search
** ou NULL si le statut n'est pas bon ou le num_search n'existe pas
*/
t_cli	*get_ia(t_cli *cli_list, int num_search)
{
  while (cli_list != NULL)
    {
      if (cli_list->numero == num_search)
	{
	  if (cli_list->statut == ACTION ||
	      cli_list->statut == NOACTION ||
	      cli_list->statut == GHOST)
	    return (cli_list);
	  return (NULL);
	}
      cli_list = cli_list->next;
    }
  return (NULL);
}
