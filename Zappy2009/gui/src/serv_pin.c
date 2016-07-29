/*
** serv_pin.c for serv_pin in /u/all/yurdus_y/cu/rendu/c/Zappy2009/gui/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:40:20 2009 yavuz yurdusev
** Last update Thu Apr 23 20:40:21 2009 yavuz yurdusev
*/

#include "command.h"

static void	fill_perso(t_cli *client, char *msg)
{
  client->invent.objet[FOOD] = atoi(get_argument(msg, 5));
  client->invent.objet[LINEMATE] = atoi(get_argument(msg, 6));
  client->invent.objet[DERAUMERE] = atoi(get_argument(msg, 7));
  client->invent.objet[SIBUR] = atoi(get_argument(msg, 8));
  client->invent.objet[MENDIANE] = atoi(get_argument(msg, 9));
  client->invent.objet[PHIRAS] = atoi(get_argument(msg, 10));
  client->invent.objet[THYSTAME] = atoi(get_argument(msg, 11));
}

void		serv_pin(t_on_screen *screen, char *msg)
{
  int		num_cli;
  t_cli		*list_cli;

  num_cli = atoi(get_argument(msg, 2));
  list_cli = screen->world->client;
  while (list_cli != NULL)
    {
      if (list_cli->num == num_cli)
	fill_perso(list_cli, msg);
      list_cli = list_cli->next;
    }
  screen->world->loading = 0;
}
