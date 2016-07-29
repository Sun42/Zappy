/*
** func_create_cli.c for func_create_cli in /u/all/yurdus_y/cu/rendu/c/Zappy2009/server/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:32:55 2009 yavuz yurdusev
** Last update Thu Apr 23 20:32:56 2009 yavuz yurdusev
*/

#include <stdio.h>
#include <stdlib.h>

#include "buffer.h"
#include "serv_connexion.h"

/*
** malloc une nouvelle structure t_cli
*/
static t_cli	*create_client(t_world *world)
{
  t_cli		*new_client;

  if ((new_client = xmalloc(sizeof(*new_client))) == NULL)
    return (NULL);
  if ((new_client->lcmdr = xmalloc(sizeof(*new_client->lcmdr))) == NULL)
    return (NULL);
  if ((new_client->lcmdw = xmalloc(sizeof(*new_client->lcmdw))) == NULL)
    return (NULL);
  new_client->next = world->client;
  world->client = new_client;
  new_client->pcli = new_pcli(new_client);
  new_client->numero = (new_client->next == NULL) ?
    0 : new_client->next->numero + 1;
  return (new_client);
}

/*
** cree les premier clients
*/
void	create_all_clients(t_world *world)
{
  int	total_clients;
  t_cli	*new_client;

  total_clients = world->max_client * get_nb_teams(world->team,
					   world->max_client);
  if (total_clients > MAX_INIT_CLIENT)
    total_clients = MAX_INIT_CLIENT;
  world->client = NULL;
  while (total_clients--)
    {
      new_client = create_client(world);
      if (new_client == NULL)
	{
	  perror("create_all_clients() --> Impossible de creer tous les clients");
	  exit(EXIT_FAILURE);
	}
      init_buf_cli(new_client);      new_client->team = NULL;
      new_client->sock = DEAD;
      new_client->statut = DEAD;
    }
}

/*
** Apelle lors d'un fork
** cree un oeuf
*/
t_cli	*create_egg(t_world *world, t_cli *ia)
{
  t_cli	*egg;

  egg = find_dead_cli(world);
  if (egg == NULL)
    {
      egg = create_client(world);
      if (!egg)
	return (NULL);
    }
  init_buf_cli(egg);
  egg->pos.y = ia->pos.y;
  egg->pos.x = ia->pos.x;
  egg->pos.direction = ia->pos.direction;
  egg->statut = EGG;
  egg->team = ia->team;
  set_timeval(world, &(egg->t_cur_cmd), TIME_BIRTH);
  set_timeval(world, &(egg->t_alive), EGG);
  return (egg);
}

/*
** On cherche une structure client libre sinon on l'a cree
** On fait ensuite le accept pour creer une socket avec le client
*/
void	connect_new_client(t_world *world)
{
  t_cli	*new_client;
  int	tmp_sock;

  if ((tmp_sock = new_connexion(world->sock_serv)) < 0)
    return ;
  new_client = find_dead_cli(world);
  if (new_client == NULL)
    {
      new_client = create_client(world);
      if (new_client == NULL)
	return ;
    }
  init_buf_cli(new_client);
  new_client->team = NULL;
  new_client->sock = tmp_sock;
  new_client->statut = NOTEAM;
  save_cmd(new_client, MSG_WECLOME, 10, 'W');
}
