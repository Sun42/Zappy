/*
** buf_init.c for buf_init in /u/all/yurdus_y/cu/rendu/c/Zappy2009/server/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:35:17 2009 yavuz yurdusev
** Last update Sat Apr 25 12:15:51 2009 yavuz yurdusev
*/

#include <stdlib.h>

#include "buffer.h"

static void	purge_buf(t_cmd *my_list)
{
  int		indice;
  t_cmd		*cur_cmd;
  t_cmd		*prev_cmd;

  indice = my_list_size(my_list) - 1;
  while (indice > 0)
    {
      prev_cmd = get_cmd(my_list, indice - 1);
      cur_cmd = get_cmd(my_list, indice);
      free_cmd(cur_cmd);
      prev_cmd->next = NULL;
      indice--;
    }
}

void	init_buf_cli(t_cli *my_cli)
{
  init_buf(&(my_cli->bufr));
  init_cmd(my_cli->lcmdr);
  my_cli->lcmdr->next = NULL;
  init_buf(&(my_cli->bufw));
  init_cmd(my_cli->lcmdw);
  my_cli->lcmdw->next = NULL;
}

void	reinit_buf_cli(t_cli *my_cli)
{
  purge_buf(my_cli->lcmdr);
  purge_buf(my_cli->lcmdw);
}
