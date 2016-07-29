/*
** move_map.c for move_map in /u/all/yurdus_y/cu/rendu/c/Zappy2009/gui/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:42:38 2009 yavuz yurdusev
** Last update Thu Apr 23 20:42:39 2009 yavuz yurdusev
*/

#include "map.h"
#include "event.h"

int	move_map(t_on_screen *screen, int cmd)
{
  if (cmd == 0)
    if (screen->world->y_begin > 0)
      screen->world->y_begin -= 1;
  if (cmd == 1)
    if (screen->world->y_begin < (screen->world->height - NB_MAX_CASE_Y))
      screen->world->y_begin += 1;
  if (cmd == 2)
    if (screen->world->x_begin < (screen->world->width - NB_MAX_CASE_X))
      screen->world->x_begin += 1;
  if (cmd == 3)
    if (screen->world->x_begin > 0)
      screen->world->x_begin -= 1;
  return (1);
}

int	check_in_camera(t_on_screen *screen,
			t_point *coor,
			int is_camera)
{
  int	y_max;
  int	x_max;
  int	cur_x;
  int	cur_y;

  x_max = screen->coor_max.x + screen->world->x_begin;
  y_max = screen->coor_max.y + screen->world->y_begin;
  cur_x = coor->x +  (is_camera ? screen->world->x_begin : 0);
  cur_y = coor->y + (is_camera ? screen->world->y_begin : 0);
  if ((cur_x < x_max) && (cur_y < y_max))
    if (cur_x >= screen->world->x_begin && cur_y >= screen->world->y_begin)
      {
	return (1);
      }
  return (0);
}
