/*
** ia_broadcast.c for ia_broadcast in /u/all/yurdus_y/cu/rendu/c/Zappy2009/server/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:25:26 2009 yavuz yurdusev
** Last update Sun Apr 26 22:25:21 2009 yavuz yurdusev
*/

#include <string.h>

#include "ia_command.h"
#include "broadcast.h"

static char	calc_broadcast(t_world *world, t_cli *ia_dest, t_cli *ia_src)
{
  t_broadcast	broadcast;

  broadcast.j1 = &(ia_src->pos);
  broadcast.j2 = &(ia_dest->pos);
  broadcast.droite.x = calc_fastpath(world->width - 1,
				     broadcast.j1->x,
				     broadcast.j2->x);
  broadcast.droite.y = calc_fastpath(world->height - 1,
				     broadcast.j1->y,
				     broadcast.j2->y);
  get_angle(&broadcast);
  broadcast.reception = calc_case_reception(&broadcast);
  add_direction(&broadcast);
  return ((char)48 + broadcast.reception);
}

static void	ia_broadcast_ia(t_world *world, t_cli *ia_src, t_cli *ia_dest)
{
  char		direction[3];

  if (ia_dest != ia_src)
    {
      save_cmd(ia_dest, "message ", 8, 'W');
      if (!memcmp(&(ia_src->pos.x), &(ia_dest->pos.x), sizeof(int) * 2))
	  save_cmd(ia_dest, "0,", 2, 'W');
      else
	{
	  direction[0] = calc_broadcast(world, ia_dest, ia_src);
	  direction[1] = ',';
	  direction[2] = '\0';
	  save_cmd(ia_dest, direction, 2, 'W');
	}

    }
  else
    save_cmd(ia_dest, MSG_OK, LEN_OK, 'W');
}

static void	ia_broadcast_gui(t_cli *gui, char nb[INT_LEN], int len_nb)
{
  save_cmd(gui, "pbc ", 4, 'W');
  save_cmd(gui, nb, len_nb, 'W');
  save_cmd(gui, MSG_SEP, LEN_SEP, 'W');
}

static void	ia_broadcast_bis(t_world *world,
				 t_cli *ia,
				 char *msg,
				 int len_msg)
{
  char		nb[INT_LEN];
  int		len_nb;
  t_cli		*list_ia;

  len_nb = atio(ia->numero, nb);
  list_ia = world->client;
  while (list_ia != NULL)
    {
      if (list_ia->statut == ACTION || list_ia->statut == NOACTION ||
	  list_ia->statut == WILL_DIE || list_ia->statut == GUI)
	{
	  if (list_ia->statut != GUI)
	    ia_broadcast_ia(world, ia, list_ia);
	  else
	    ia_broadcast_gui(list_ia, nb, len_nb);
	  if (list_ia != ia)
	    save_cmd(list_ia, msg, len_msg, 'W');
	}
      list_ia = list_ia->next;
    }
}

void	ia_broadcast(t_world *world, t_cli *ia)
{
  char	*msg;
  int	len_msg;

  putstr("\033[33mClient numero : ");
  print_nb(ia->numero);
  putstr(" broadcast\n\033[39m");
  len_msg = access_cmdlen(ia, 'R');
  if (len_msg > 0)
    {
      msg = access_cmd(ia, 'R') + 10;
      ia_broadcast_bis(world, ia, msg, len_msg - 10);
    }
}
