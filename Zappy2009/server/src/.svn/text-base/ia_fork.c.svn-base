/*
** ia_fork.c for ia_fork in /u/all/yurdus_y/cu/rendu/c/Zappy2009/server/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:24:25 2009 yavuz yurdusev
** Last update Sat Apr 25 16:49:57 2009 yavuz yurdusev
*/

#include "ia_command.h"

void	ia_birth(t_world *world, t_cli *egg)
{
  putstr("\033[33mClient numero : ");
  print_nb(egg->numero);
  putstr(" born\n\033[39m");
  gen_ressource(world);
  world->map[egg->pos.y][egg->pos.x].elevation = 0;
  world->map[egg->pos.y][egg->pos.x].nb_joueur += 1;
  egg->team->nb_client++;
  add_pcli(&(world->map[egg->pos.y][egg->pos.x].pcli), egg->pcli);
  egg->sock = GHOST;
  egg->statut = GHOST;
  egg->lvl = 1;
  init_inventaire(&(egg->invent));
  egg->invent.objet[FOOD] = DEFAULT_FOOD;
  egg->elevation = 0;
  if (world->map[egg->pos.y][egg->pos.x].elevation && world->pgui != NULL)
    gui_pie(world, egg->pos.y, egg->pos.x, '0');
  set_timeval(world, &(egg->t_cur_cmd), NOACTION);
  set_timeval(world, &(egg->t_alive), LIFETIME);
  if (world->pgui != NULL)
    gui_eht(world, egg->numero);
}

void	ia_fork(t_world *world, t_cli *ia)
{
  t_cli	*egg;

  putstr("\033[33mClient numero : ");
  print_nb(ia->numero);
  putstr(" fork\n\033[39m");
  egg = create_egg(world, ia);
  if (egg == NULL)
    save_cmd(ia, MSG_KO, LEN_KO, 'W');
  else
    {
      save_cmd(ia, MSG_OK, LEN_KO, 'W');
      if (world->pgui != NULL)
	{
	  gui_pfk(world, ia->numero);
	  gui_enw_serv(world, egg, ia->numero);
	}
    }
}
