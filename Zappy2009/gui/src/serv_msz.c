/*
** serv_msz.c for serv_msz in /u/all/yurdus_y/cu/rendu/c/Zappy2009/gui/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:41:20 2009 yavuz yurdusev
** Last update Thu Apr 23 20:41:20 2009 yavuz yurdusev
*/

#include "command.h"
#include "inventaire.h"
#include "func_xy_max.h"

void	serv_msz(t_on_screen *screen, char *msg)
{
  int	x;
  int	y;

  if (screen->world->loading == 2)
    {
      x =  atoi(get_argument(msg, 2));
      y =  atoi(get_argument(msg, 3));
      screen->x = x * SQUARE;
      screen->y = y * SQUARE;
      screen->world->width = (x > 0 ? x : 0);
      screen->world->height = (y > 0 ? y : 0);
      init_map_value(screen);
      screen->world->loading = 1;
      screen->coor_max.x = get_x_max(screen);
      screen->coor_max.y = get_y_max(screen);
    }
}
