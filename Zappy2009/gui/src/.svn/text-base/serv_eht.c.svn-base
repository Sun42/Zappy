/*
** serv_eht.c for serv_eht in /u/all/yurdus_y/cu/rendu/c/Zappy2009/gui/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:41:39 2009 yavuz yurdusev
** Last update Thu Apr 23 20:41:39 2009 yavuz yurdusev
*/

#include "map.h"
#include "func_xmemory.h"
#include "func_egg.h"
#include "command.h"

static void	add_ghost_num(t_on_screen *screen,
			      int ghost_num,
			      int y,
			      int x)
{
  int		nb_ghost;

  if (screen->world->map[y][x].ghost_num == NULL)
    screen->world->map[y][x].ghost_num = xmalloc(sizeof(int));
  else
    screen->world->map[y][x].ghost_num =
      xrealloc(screen->world->map[y][x].ghost_num, sizeof(int) *
	       (screen->world->map[y][x].nb_ghost));
  nb_ghost = screen->world->map[y][x].nb_ghost - 1;
  screen->world->map[y][x].ghost_num[nb_ghost] = ghost_num;
}

void		serv_eht(t_on_screen *screen, char *msg)
{
  int		oeuf_num;
  t_point	pos;

  oeuf_num = atoi(get_argument(msg, 2));
  pos = oeuf_killer(screen, oeuf_num);
  if (pos.x != screen->world->width)
    {
      screen->world->map[pos.y][pos.x].objet[OEUF] -= 1;
      screen->world->map[pos.y][pos.x].nb_ghost += 1;
      add_ghost_num(screen, oeuf_num, pos.y, pos.x);
      screen->world->loading = 0;
    }
}
