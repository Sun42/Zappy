/*
** buf_add.c for buf_add in /u/all/yurdus_y/cu/rendu/c/Zappy2009/gui/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:36:18 2009 yavuz yurdusev
** Last update Thu Apr 23 20:36:19 2009 yavuz yurdusev
*/

#include "define.h"
#include "buffer.h"
#include "map.h"
#include "func_xmemory.h"

/*
** ajoute dans le buffer et retourne l'indice_buf
** return values(my_cli->indice_buf)
** -42 error
** indice_buf added on endbuf
** 0 added on begin
** -1 added on heap
*/
int	add_bufr(t_msg*my_msg, t_cmd *my_cmd, char *text, int len)
{
  int	indice_buf;

  rewind_buf(&(my_msg->bufr));
  if (!is_new(my_cmd) && !is_onbuf(my_cmd))
    {
      if (add_overflow_old(my_cmd, text, len) == -1)
	return (-42);
      return (-1);
    }
  if (can_add_endbuf(&(my_msg->bufr), len))
    {
      indice_buf = add_endbuf(&(my_msg->bufr), text, len);
      return (indice_buf);
    }
  if (can_add_begbuf(&(my_msg->bufr), len))
    {
      indice_buf = add_begbuf(&(my_msg->bufr), text, len);
      return (indice_buf);
    }
  if (add_overflow_r(my_msg, my_cmd, text, len) == -1)
    return (-42);
  else
    return (-1);
}

int	add_bufw(t_msg *my_msg, t_cmd *my_cmd, char *text, int len)
{
  int	indice_buf;

  rewind_buf(&(my_msg->bufw));
  if (!is_new(my_cmd) && !is_onbuf(my_cmd))
    {
      if (add_overflow_old(my_cmd, text, len) == -1)
	return (-42);
      return (-1);
    }
  if (can_add_endbuf(&(my_msg->bufw), len))
    {
      indice_buf = add_endbuf(&(my_msg->bufw), text, len);
      return (indice_buf);
    }
  if (can_add_begbuf(&(my_msg->bufw), len))
    {
      indice_buf = add_begbuf(&(my_msg->bufw), text, len);
      return (indice_buf);
    }
  if (add_overflow_w(my_msg, my_cmd, text, len) == -1)
    return (-42);
  else
    return (-1);
}
