#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include "buffer.h"


char *strndup(const char *s, size_t n);

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
      add_overflow_old(my_cmd, text, len);
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
      add_overflow_old(my_cmd, text, len);
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
