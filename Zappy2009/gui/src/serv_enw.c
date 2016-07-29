/*
** serv_enw.c for serv_enw in /u/all/yurdus_y/cu/rendu/c/Zappy2009/gui/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:41:27 2009 yavuz yurdusev
** Last update Thu Apr 23 20:41:31 2009 yavuz yurdusev
*/

#include "map.h"
#include "func_xmemory.h"
#include "command.h"

void	serv_enw(t_on_screen *screen, char *msg)
{
  int	x;
  int	y;
  int	nb_oeuf;

  x = atoi(get_argument(msg, 4));
  y = atoi(get_argument(msg, 5));
  if (!is_valid_case(x, y, screen))
    return ;
  if (screen->world->map[y][x].oeuf_num == NULL)
    screen->world->map[y][x].oeuf_num = xmalloc(sizeof(int));
  else
    screen->world->map[y][x].oeuf_num =
      xrealloc(screen->world->map[y][x].oeuf_num, sizeof(int) *
	       (screen->world->map[y][x].objet[OEUF] + 1));
  screen->world->map[y][x].objet[OEUF] += 1;
  nb_oeuf = screen->world->map[y][x].objet[OEUF] - 1;
  screen->world->map[y][x].oeuf_num[nb_oeuf] = atoi(get_argument(msg, 2));
  screen->world->loading = 0;
}
