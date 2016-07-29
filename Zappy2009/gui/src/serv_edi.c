/*
** serv_edi.c for serv_edi in /u/all/yurdus_y/cu/rendu/c/Zappy2009/gui/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:41:46 2009 yavuz yurdusev
** Last update Thu Apr 23 20:41:47 2009 yavuz yurdusev
*/

#include "command.h"
#include "func_egg.h"
#include "func_init_ghost.h"

void		serv_edi(t_on_screen *screen, char *msg)
{
  int		ghost_num;
  t_point	pos;

  ghost_num = atoi(get_argument(msg, 2));
  pos = ghost_killer(screen, ghost_num);
  if (pos.x != -1)
    {
      screen->world->map[pos.y][pos.x].nb_ghost -= 1;
      screen->world->loading = 0;
    }
}
