/*
** serv_pie.c for serv_pie in /u/all/yurdus_y/cu/rendu/c/Zappy2009/gui/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:40:28 2009 yavuz yurdusev
** Last update Thu Apr 23 20:40:29 2009 yavuz yurdusev
*/

#include "command.h"

void	serv_pie(t_on_screen *screen, char *msg)
{
  int	x;
  int	y;
  int	lvlup;

  x = atoi(get_argument(msg, 2));
  y = atoi(get_argument(msg, 3));
  lvlup = atoi(get_argument(msg, 4));
  if (x >= 0 && x < screen->world->width &&
      y >= 0 && y < screen->world->height)
    if (screen->world->map[y][x].objet[INCANTATION])
      screen->world->map[y][x].objet[INCANTATION] -= 1;
  screen->world->loading = 0;
}
