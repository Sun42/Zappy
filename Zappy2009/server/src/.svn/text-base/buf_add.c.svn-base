/*
** buf_add.c for buf_add in /u/all/yurdus_y/cu/rendu/c/Zappy2009/server/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:36:23 2009 yavuz yurdusev
** Last update Thu Apr 23 20:36:23 2009 yavuz yurdusev
*/

#include "buffer.h"

/*
** ajoute dans le buffer et retourne l'indice_buf
** return values(my_cli->indice_buf)
** -42 error
** indice_buf added on endbuf
** 0 added on begin
** -1 added on heap
*/
int	add_bufr(t_cli *my_cli, t_cmd *my_cmd, char *text, int len)
{
  int	indice_buf;

  rewind_buf(&(my_cli->bufr));
  if (!is_new(my_cmd) && !is_onbuf(my_cmd))
    {
      if (add_overflow_old(my_cmd, text, len) == -1)
	return (-42);
      return (-1);
    }
  if (can_add_endbuf(&(my_cli->bufr), len))
    {
      indice_buf = add_endbuf(&(my_cli->bufr), text, len);
      return (indice_buf);
    }
  if (can_add_begbuf(&(my_cli->bufr), len))
    {
      indice_buf = add_begbuf(&(my_cli->bufr), text, len);
      return (indice_buf);
    }
  if (add_overflow_r(my_cli, my_cmd, text, len) == -1)
    return (-42);
  else
    return (-1);
}

int	add_bufw(t_cli *my_cli, t_cmd *my_cmd, char *text, int len)
{
  int	indice_buf;

  rewind_buf(&(my_cli->bufw));
  if (!is_new(my_cmd) && !is_onbuf(my_cmd))
    {
      if (add_overflow_old(my_cmd, text, len) == -1)
	return (-42);
      return (-1);
    }
  if (can_add_endbuf(&(my_cli->bufw), len))
    {
      indice_buf = add_endbuf(&(my_cli->bufw), text, len);
      return (indice_buf);
    }
  if (can_add_begbuf(&(my_cli->bufw), len))
    {
      indice_buf = add_begbuf(&(my_cli->bufw), text, len);
      return (indice_buf);
    }
  if (add_overflow_w(my_cli, my_cmd, text, len) == -1)
    return (-42);
  else
    return (-1);
}
