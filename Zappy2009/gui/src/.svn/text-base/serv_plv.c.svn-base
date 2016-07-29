/*
** serv_plv.c for serv_plv in /u/all/yurdus_y/cu/rendu/c/Zappy2009/gui/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:39:48 2009 yavuz yurdusev
** Last update Thu Apr 23 20:39:48 2009 yavuz yurdusev
*/

#include "command.h"
#include "func_init_perso.h"

void	serv_plv(t_on_screen *screen, char *msg)
{
  int	num_cli;
  int	lvl;
  t_cli	*list_cli;

  num_cli = atoi(get_argument(msg, 2));
  lvl = atoi(get_argument(msg, 3));
  list_cli = screen->world->client;
  while (list_cli != NULL)
    {
      if (num_cli == list_cli->num)
	{
	  list_cli->lvl = lvl;
	  init_perso(screen, list_cli);
	  screen->world->loading = 0;
	  return ;
	}
      list_cli = list_cli->next;
    }
}
