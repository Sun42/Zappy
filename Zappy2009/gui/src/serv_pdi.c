/*
** serv_pdi.c for serv_pdi in /u/all/yurdus_y/cu/rendu/c/Zappy2009/gui/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:41:07 2009 yavuz yurdusev
** Last update Thu Apr 23 20:41:07 2009 yavuz yurdusev
*/

#include "command.h"
#include "inventaire.h"

static void	del_client(t_on_screen *screen,
			   t_cli *save_cli,
			   t_cli *list_cli)
{
  if (screen->info_bag->heros != NULL)
    if (list_cli == screen->info_bag->heros)
      {
	screen->info_bag->heros = NULL;
	right_click(screen);
      }
  if (screen->info_bag->heros != NULL)
    if (list_cli == screen->info_bag->heros)
      {
	screen->info_bag->heros = NULL;
	right_click(screen);
      }
  if (save_cli == NULL)
    screen->world->client = list_cli->next;
  else
    save_cli->next = list_cli->next;
  free(list_cli->team);
  free(list_cli);
}

void		serv_pdi(t_on_screen *screen, char *msg)
{
  int		num_cli;
  t_cli		*list_cli;
  t_cli		*save_cli;
  int		cli_exist;

  num_cli = atoi(get_argument(msg, 2));
  list_cli = screen->world->client;
  save_cli = NULL;
  cli_exist = 0;
  while (list_cli != NULL)
    {
      if (list_cli->num == num_cli)
	{
	  cli_exist = 1;
	  break;
	}
      save_cli = list_cli;
      list_cli = list_cli->next;
    }
  if (cli_exist)
    del_client(screen, save_cli, list_cli);
  screen->world->loading = 0;
}
