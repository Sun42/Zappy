/*
** ia_expulse.c for ia_expulse in /u/all/yurdus_y/cu/rendu/c/Zappy2009/server/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:24:33 2009 yavuz yurdusev
** Last update Sat Apr 25 12:01:26 2009 yavuz yurdusev
*/

#include "ia_command.h"

static void	move_player(t_world *world, t_cli *videur, t_cli *vide)
{
  world->map[vide->pos.y][vide->pos.x].nb_joueur -= 1;
  world->map[vide->pos.y][vide->pos.x].elevation = 0;
  remove_pcli(&(world->map[vide->pos.y][vide->pos.x].pcli), vide->pcli);
  if (videur->pos.direction % 2)
    vide->pos.y += (videur->pos.direction == NORD) ?
      (!videur->pos.y) ? world->height - 1 : -1 :
      (videur->pos.y == (world->height - 1)) ? -videur->pos.y : 1;
  else
    vide->pos.x += (videur->pos.direction == OUEST) ?
      (!videur->pos.x) ? world->width - 1 : -1 :
      (videur->pos.x == (world->width - 1)) ? -videur->pos.x : 1;
  world->map[vide->pos.y][vide->pos.x].nb_joueur += 1;
  world->map[vide->pos.y][vide->pos.x].elevation = 0;
  add_pcli(&(world->map[vide->pos.y][vide->pos.x].pcli), vide->pcli);
}

static void	expluse_player(t_world *world, t_cli *videur, t_cli *vide)
{
  char		*k;

  if (videur->pos.direction == vide->pos.direction)
    k = "5";
  else if (videur->pos.direction + 1 == vide->pos.direction ||
	   (videur->pos.direction == OUEST && vide->pos.direction == NORD))
    k = "7";
  else if (videur->pos.direction - 1 == vide->pos.direction ||
	   (videur->pos.direction == NORD && vide->pos.direction == OUEST))
    k = "3";
  else
    k = "1";
  save_cmd(vide, MSG_EXPULSE, LEN_EXPULSE, 'W');
  save_cmd(vide, k, 1, 'W');
  save_cmd(vide, MSG_END, LEN_END, 'W');
  move_player(world, videur, vide);
  if (world->pgui != NULL)
    gui_ppo_serv(world, vide);
}

void		ia_expulse(t_world *world, t_cli *ia)
{
  t_pcli	*list;
  t_pcli	*save;

  putstr("\033[33mClient numero : ");
  print_nb(ia->numero);
  putstr(" expulse\n\033[39m");
  if (world->map[ia->pos.y][ia->pos.x].nb_joueur > 1)
    {
      if (world->map[ia->pos.y][ia->pos.x].elevation && world->pgui != NULL)
        gui_pie(world, ia->pos.y, ia->pos.x, '0');
      if (world->pgui != NULL)
	gui_pex(world, ia->numero);
      list = world->map[ia->pos.y][ia->pos.x].pcli;
      while (list != NULL)
	{
	  save = list->next;
	  if (list != ia->pcli)
	    expluse_player(world, ia, list->lcli);
	  list = save;
	}
      save_cmd(ia, MSG_OK, LEN_OK, 'W');
    }
  else
    save_cmd(ia, MSG_KO, LEN_KO, 'W');
}
