/*
** cmd_unsave.c for cmd_unsave in /u/all/yurdus_y/cu/rendu/c/Zappy2009/gui/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:39:12 2009 yavuz yurdusev
** Last update Thu Apr 23 20:39:14 2009 yavuz yurdusev
*/

#include <stdlib.h>

#include "define.h"
#include "buffer.h"

/*
** reinitialise le premier element de la liste
*/
static void	reinit_firstelem(t_cmd **my_list)
{
  (*my_list)->next = NULL;
  (*my_list)->len = -1;
  (*my_list)->is_complet = 0;
  (*my_list)->indice_buf = -1;
  if ((*my_list)->cmd != NULL)
    {
      free((*my_list)->cmd);
      (*my_list)->cmd = NULL;
    }
  (*my_list)->sended = 0;
}

static void	remove_firstelem(t_cmd **my_list, t_cmd *cur_cmd, int max)
{
  if (max > 0)
    {
      *my_list = cur_cmd->next;
      free_cmd(cur_cmd);
    }
  else
    {
      reinit_firstelem(my_list);
    }
}

static void	unsave_cmd2(t_cmd *my_listcmd, t_buf *buf, int len)
{
  int		ifirst;
  t_cmd		*my_cmd;

  ifirst = my_list_size(my_listcmd) - 1;
  my_cmd = get_cmd(my_listcmd, ifirst);
  len = MIN(len, my_cmd->len);
  if (my_cmd->len == -1 || my_cmd->len == 0)
    return ;
  my_cmd->sended += len;
  my_cmd->len -= len;
  if (my_cmd->cmd == NULL)
    {
      if (my_cmd->indice_buf == buf->begin)
	{
	  turn_my_buf(buf, my_cmd->indice_buf, len);
	  my_cmd->indice_buf = buf->begin;
	}
    }
  if (my_cmd->len <= 0)
    remove_cmd(&my_listcmd, ifirst);
  rewind_buf(buf);
}

void	unsave_cmd(t_msg *my_msg, int len, char mode)
{
  if (len < 1)
    return ;
  if (mode == 'R')
    unsave_cmd2(my_msg->lcmdr, &(my_msg->bufr), len);
  if (mode == 'W')
    unsave_cmd2(my_msg->lcmdw, &(my_msg->bufw), len);
}

/*
** delete un element de la liste selon lindice
*/
void	remove_cmd(t_cmd **my_list, int indice)
{
  int	max;
  t_cmd	*cur_cmd;
  t_cmd	*prev_cmd;

  max = my_list_size(*my_list) - 1;
  if ((indice > max) || (indice < 0))
    return ;
  cur_cmd = get_cmd(*my_list, indice);
  if (indice == 0)
    remove_firstelem(my_list, cur_cmd, max);
  else
    {
      if (indice > 0 && indice < max)
	{
	  prev_cmd = get_cmd(*my_list, indice - 1);
	  prev_cmd->next = cur_cmd->next;
	}
      else if (indice == max)
	{
	  prev_cmd = get_cmd(*my_list, indice - 1);
	  prev_cmd->next = NULL;
	}
      free_cmd(cur_cmd);
    }
}
