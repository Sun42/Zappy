/*
** serv_pgt.c for serv_pgt in /u/all/yurdus_y/cu/rendu/c/Zappy2009/gui/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:40:42 2009 yavuz yurdusev
** Last update Thu Apr 23 20:40:43 2009 yavuz yurdusev
*/

#include "command.h"

static void	check_case_sub(t_on_screen *screen, int x, int y, int num_res)
{
  screen->world->map[y][x].objet[num_res] -= 1;
}

void	serv_pgt(t_on_screen *screen, char *msg)
{
  int	num_cli;
  int	num_res;
  t_cli	*list_cli;

  num_cli = atoi(get_argument(msg, 2));
  num_res = atoi(get_argument(msg, 3));
  if (num_res < NB_OBJETS - 2)
    {
      list_cli = screen->world->client;
      while (list_cli != NULL)
	{
	  if (num_cli == list_cli->num)
	    {
	      check_case_sub(screen, list_cli->pos.pos_player.x,
			 list_cli->pos.pos_player.y, num_res);
	      screen->world->loading = 0;
	      return ;
	    }
	  list_cli = list_cli->next;
	}
    }
}
