/*
** select_init.c for select_init in /u/all/yurdus_y/cu/rendu/c/Zappy2009/server/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:21:57 2009 yavuz yurdusev
** Last update Sat Apr 25 16:25:59 2009 yavuz yurdusev
*/

#if defined(sun) || defined(__sun) || defined(__sun__)
# include <string.h>
#endif

#include "buffer.h"
#include "serv_connexion.h"

static char	init_set(t_world *world,
			 fd_set fd_rw[],
			 int *max,
			 t_cli *cli)
{
  char		write;

  write = 0;
  if (cli->statut != DEAD && cli->statut != EGG && cli->statut != GHOST)
    {
      if (access_cmdlen(cli, 'W') > 0)
	{
	  FD_SET(cli->sock, &fd_rw[WFD]);
	  write = 1;
	}
      if (cli->statut != WILL_DIE && !world->victory_team)
	FD_SET(cli->sock, &fd_rw[RFD]);
      if (cli->sock > *max)
	*max = cli->sock;
    }
  return (write);
}

static t_cli	*init_timeout(t_world *world,
			      struct timeval **timesave,
			      t_cli *cli)
{
  t_cli		*save;

  if (world->victory_team)
    return (NULL);
  save = NULL;
  if ((cli->statut == ACTION || cli->statut == EGG)
      && timecmp(&(cli->t_cur_cmd), *timesave))
    {
      save = cli;
      *timesave = &(cli->t_cur_cmd);
    }
  if ((cli->statut == ACTION || cli->statut == NOACTION ||
       cli->statut == GHOST) && timecmp(&(cli->t_alive), *timesave))
    {
      save = cli;
      *timesave = &(cli->t_alive);
    }
  return (save);
}

static void	init_init_select(t_world *world,
				 fd_set fd_rw[],
				 struct timeval *timesave)
{
  timesave->tv_sec = 2147483647;
  timesave->tv_usec = 2147483647;
  FD_ZERO(&fd_rw[WFD]);
  FD_ZERO(&fd_rw[RFD]);
  FD_SET(world->sock_serv, &fd_rw[RFD]);
}

t_cli			*init_select(t_world *world,
				     fd_set fd_rw[],
				     int *max,
				     struct timeval *timev)
{
  t_cli			*cli;
  t_cli			*tmp;
  t_cli			*save;
  struct timeval	*timesave;
  int			write;

  timesave = timev;
  init_init_select(world, fd_rw, timesave);
  save = NULL;
  cli = world->client;
  write = 0;
  while (cli != NULL)
    {
      if (init_set(world, fd_rw, max, cli))
	write = 1;
      tmp = init_timeout(world, &timesave, cli);
      if (tmp != NULL)
	save = tmp;
      cli = cli->next;
    }
  if (write == 0 && world->victory_team)
    stop_server(world);
  if (save)
    setdifftime(timesave, timev);
  return (save);
}
