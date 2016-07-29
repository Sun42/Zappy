/*
** buf_init.c for buf_init in /u/all/yurdus_y/cu/rendu/c/Zappy2009/gui/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:37:12 2009 yavuz yurdusev
** Last update Thu Apr 23 20:37:13 2009 yavuz yurdusev
*/

#include <stdlib.h>

#include "define.h"
#include "map.h"
#include "func_xmemory.h"
#include "buffer.h"

void	init_buf_msg(t_msg *my_msg)
{
  if ((my_msg->lcmdr = xmalloc(sizeof(*my_msg->lcmdr))) == NULL)
    return ;
  if ((my_msg->lcmdw = xmalloc(sizeof(*my_msg->lcmdw))) == NULL)
    return ;
  init_buf(&(my_msg->bufr));
  init_cmd(my_msg->lcmdr);
  my_msg->lcmdr->next = NULL;
  init_buf(&(my_msg->bufw));
  init_cmd(my_msg->lcmdw);
  my_msg->lcmdw->next = NULL;
}
