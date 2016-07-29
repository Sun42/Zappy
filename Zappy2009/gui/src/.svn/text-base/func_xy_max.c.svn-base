/*
** func_xy_max.c for func_xy_max in /u/all/yurdus_y/cu/rendu/c/Zappy2009/gui/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:42:09 2009 yavuz yurdusev
** Last update Thu Apr 23 20:42:10 2009 yavuz yurdusev
*/

#include "map.h"

int	get_x_max(t_on_screen *screen)
{
  int	x_max;

  x_max = NB_MAX_CASE_X;
  if ((screen->world->width - screen->world->x_begin) < NB_MAX_CASE_X)
    x_max = (screen->world->width - screen->world->x_begin);
  return (x_max);
}

int	get_y_max(t_on_screen *screen)
{
  int	y_max;

  y_max = NB_MAX_CASE_Y;
  if ((screen->world->height - screen->world->y_begin) < NB_MAX_CASE_Y)
    y_max = (screen->world->height - screen->world->y_begin);
  return (y_max);
}
