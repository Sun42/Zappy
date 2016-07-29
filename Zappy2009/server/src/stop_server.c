/*
** stop_server.c for stop_server in /u/all/yurdus_y/cu/rendu/c/Zappy2009/server/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:21:30 2009 yavuz yurdusev
** Last update Sat Apr 25 14:49:11 2009 yavuz yurdusev
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "buffer.h"

static void	free_map(t_world *world)
{
  int		y;

  y = 0;
  while (y < world->height)
    {
      free(world->map[y]);
      y++;
    }
  free(world->map);
}

static void	free_ia(t_cli *ia)
{
  t_cli		*temp;

  while (ia != NULL)
    {
      temp = ia->next;
      if (ia->sock > 0 && close(ia->sock) == -1)
	perror("Erreur close() --> free_ia()");
      else
	putstr("free_ia() : Socket deja fermee\n");
      free(ia->pcli);
      free_allcmd(ia->lcmdr);
      free_allcmd(ia->lcmdw);
      free(ia);
      ia = temp;
    }
}

static void	free_team(t_team *teams)
{
  t_team	*temp;

  while (teams != NULL)
    {
      temp = teams->next;
      free(teams);
      teams = temp;
    }
}

void	stop_server(t_world *world)
{
  free_ia(world->client);
  free_team(world->team);
  free_map(world);
  if (close(world->sock_serv) == -1)
    perror("Erreur close() --> stop_server()");
  exit(EXIT_SUCCESS);
}
