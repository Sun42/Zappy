/*
** buf_add_overflow.c for buf_add_overflow in /u/all/yurdus_y/cu/rendu/c/Zappy2009/server/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:36:08 2009 yavuz yurdusev
** Last update Thu Apr 23 20:36:08 2009 yavuz yurdusev
*/

#include <string.h>

#include "buffer.h"

static int	add_overflow_new(t_cmd *my_cmd, char *text, int len)
{
  if ((my_cmd->cmd = xmalloc(sizeof(char) * (len + 1))) == NULL)
    return (-1);
  strncpy(my_cmd->cmd, text, len);
  return (1);
}

/*
** ajoute la cmd sur le tas
*/
int	add_overflow_r(t_cli *my_cli, t_cmd *my_cmd, char *text, int len)
{
  if (is_new(my_cmd))
    return (add_overflow_new(my_cmd, text, len));
  else
    {
      if (is_onbuf(my_cmd))
	{
	  my_cmd->cmd = xmalloc(sizeof(char) * (my_cmd->len + len + 1));
	  if (my_cmd->cmd == NULL)
	    return (-1);
	  bufncpy(my_cmd->cmd, my_cli->bufr.buf, my_cmd->indice_buf,
		  my_cmd->len);
	  my_cmd->cmd[my_cmd->len] = '\0';
	  strncat(my_cmd->cmd, text, len);
	  bufmemset(my_cli->bufr.buf, my_cmd->indice_buf, my_cmd->len, FREED);
	  if (my_cli->bufr.begin == my_cmd->indice_buf)
	    my_cli->bufr.begin += my_cmd->len;
	  my_cmd->indice_buf = -1;
	}
      else
	return (add_overflow_old(my_cmd, text, len));
    }
  return (1);
}

int	add_overflow_w(t_cli *my_cli, t_cmd *my_cmd, char *text, int len)
{
  if (is_new(my_cmd))
    return (add_overflow_new(my_cmd, text, len));
  else
    {
      if (is_onbuf(my_cmd))
	{
	  my_cmd->cmd = xmalloc(sizeof(char) * (my_cmd->len + len + 1));
	  if (my_cmd->cmd == NULL)
	    return (-1);
	  bufncpy(my_cmd->cmd, my_cli->bufw.buf, my_cmd->indice_buf,
		  my_cmd->len);
	  my_cmd->cmd[my_cmd->len] = '\0';
	  strncat(my_cmd->cmd, text, len);
	  bufmemset(my_cli->bufw.buf, my_cmd->indice_buf, my_cmd->len, FREED);
	  if (my_cli->bufw.begin == my_cmd->indice_buf)
	    my_cli->bufw.begin += my_cmd->len;
	  my_cmd->indice_buf = -1;
	}
      else
	return (add_overflow_old(my_cmd, text, len));
    }
  return (1);
}

int	add_overflow_old(t_cmd *my_cmd, char *text, int len)
{
  my_cmd->cmd = xrealloc(my_cmd->cmd, sizeof(char) * (len + my_cmd->len + 1));
  if (my_cmd->cmd == NULL)
      return (-1);
  my_cmd->cmd[my_cmd->len] = '\0';
  strncat(my_cmd->cmd, text, len);
  return (1);
}
