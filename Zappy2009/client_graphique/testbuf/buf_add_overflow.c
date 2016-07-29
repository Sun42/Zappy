#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "buffer.h"

static int	add_overflow_new(t_cmd *my_cmd, char *text, int len);


/*
** ajoute la cmd sur le tas
*/
int	add_overflow_r(t_msg *my_msg, t_cmd *my_cmd, char *text, int len)
{
  if (is_new(my_cmd))
    return (add_overflow_new(my_cmd, text, len));
  else
    {
      if (is_onbuf(my_cmd))
	{
	  if ((my_cmd->cmd = malloc(sizeof(char) * (my_cmd->len + len + 1))) == NULL)
	    return (-1);
	  bufncpy(my_cmd->cmd , my_msg->bufr.buf, my_cmd->indice_buf, my_cmd->len);
	  my_cmd->cmd[my_cmd->len] = '\0';
	  strncat(my_cmd->cmd, text, len);
	  bufmemset(my_msg->bufr.buf, my_cmd->indice_buf, my_cmd->len, FREED);
	  if (my_msg->bufr.begin == my_cmd->indice_buf)
	    my_msg->bufr.begin += my_cmd->len;
	  my_cmd->indice_buf = -1;
	}
      else
	return (add_overflow_old(my_cmd, text, len));
    }
  return (1);
}

int	add_overflow_w(t_msg *my_msg, t_cmd *my_cmd, char *text, int len)
{
  if (is_new(my_cmd))
    return (add_overflow_new(my_cmd, text, len));
  else
    {
      if (is_onbuf(my_cmd))
	{
	  if ((my_cmd->cmd = malloc(sizeof(char) * (my_cmd->len + len + 1))) == NULL)
	    return (-1);
	  bufncpy(my_cmd->cmd , my_msg->bufw.buf, my_cmd->indice_buf, my_cmd->len);
	  my_cmd->cmd[my_cmd->len] = '\0';
	  strncat(my_cmd->cmd, text, len);
	  bufmemset(my_msg->bufw.buf, my_cmd->indice_buf, my_cmd->len, FREED);
	  if (my_msg->bufw.begin == my_cmd->indice_buf)
	    my_msg->bufw.begin += my_cmd->len;
	  my_cmd->indice_buf = -1;
	}
      else
	return (add_overflow_old(my_cmd, text, len));
    }
  return (1);
}

int	add_overflow_old(t_cmd *my_cmd, char *text, int len)
{
  if ((my_cmd->cmd = realloc(my_cmd->cmd, sizeof(char) * (len + my_cmd->len + 1))) == NULL)
    return (-1);
  my_cmd->cmd[my_cmd->len] = '\0';
  strncat(my_cmd->cmd, text, len);
  return (1);
}

static int	add_overflow_new(t_cmd *my_cmd, char *text, int len)
{
  if ((my_cmd->cmd = malloc(sizeof(char) * (len + 1))) == NULL)
    return (-1);
  strncpy(my_cmd->cmd, text, len);
  return (1);
}
