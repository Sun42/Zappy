/*
** serv_pex.c for serv_pex in /u/all/yurdus_y/cu/rendu/c/Zappy2009/gui/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:40:55 2009 yavuz yurdusev
** Last update Thu Apr 23 20:40:55 2009 yavuz yurdusev
*/

#include "command.h"
#include "x_func_sdl.h"

void		serv_pex(t_on_screen *screen, char *msg)
{
  int		num_cli;
  t_cli		*my_cli;

  num_cli = atoi(get_argument(msg, 2));
  my_cli = screen->world->client;
  while (my_cli != NULL)
    {
      if (my_cli->num == num_cli)
	{
	  screen->world->pos_expulse.x = CENTER_X(screen->coor_max.x) +
	    (my_cli->pos.pos_player.x - screen->world->x_begin)
	    * SQUARE;
	  screen->world->pos_expulse.y = CENTER_Y(screen->coor_max.y) +
	    ((my_cli->pos.pos_player.y - screen->world->y_begin)
	     * SQUARE);
	  screen->world->time_expulse = 4;
	}
      my_cli = my_cli->next;
    }
}
