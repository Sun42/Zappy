/*
** serv_bvn.c for serv_bvn in /u/all/yurdus_y/cu/rendu/c/Zappy2009/gui/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:42:10 2009 yavuz yurdusev
** Last update Thu Apr 23 20:42:11 2009 yavuz yurdusev
*/

#include "define.h"
#include "buffer.h"
#include "map.h"
#include "socket.h"
#include "command.h"

void	serv_bvn(t_on_screen *screen,
		 char *msg __attribute__((unused)))
{
  save_cmd(&(screen->my_msg), "GRAPHIC\n", 8, 'W');
  do_write(screen);
}
