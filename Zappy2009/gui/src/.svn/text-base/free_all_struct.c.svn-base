/*
** free_all.c for free_all in /u/all/yurdus_y/cu/rendu/c/Zappy2009/gui/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:41:59 2009 yavuz yurdusev
** Last update Thu Apr 23 20:42:01 2009 yavuz yurdusev
*/

#include <stdio.h>
#include <stdlib.h>

#include "map.h"
#include "func_xmemory.h"
#include "command.h"

void	free_map(t_on_screen *screen)
{
  int	y;

  if (screen->world != NULL)
    {
      if (screen->world->map != NULL)
	{
	  y = 0;
	  while (y < screen->world->height)
	    {
	      if (screen->world->map[y] != NULL)
		free(screen->world->map[y]);
	      ++y;
	    }
	  free(screen->world->map);
	}
    }
}

void	free_player(t_on_screen *screen)
{
  int	i;

  if (screen->world != NULL && screen->world->ghost.player != NULL)
    SDL_FreeSurface(screen->world->ghost.player);
  if (screen->world != NULL && screen->world->player != NULL)
    {
      i = 0;
      while (i < 8)
	{
	  SDL_FreeSurface(screen->world->player[i]);
	  i++;
	}
      free(screen->world->player);
    }
}

void	free_ressources(t_on_screen *screen)
{
  int	i;

  if (screen->world != NULL && screen->world->ressources != NULL)
    {
      i = 0;
      while (i < NB_OBJETS)
	{
	  SDL_FreeSurface(screen->world->ressources[i]);
	  i++;
	}
      free(screen->world->ressources);
    }
  if (screen->world->portal != NULL)
    SDL_FreeSurface(screen->world->portal);
}

void	free_wood(t_on_screen *screen)
{
  int	i;

  if (screen->world != NULL && screen->world->wood != NULL)
    {
      i = 0;
      while (i < 5)
	{
	  SDL_FreeSurface(screen->world->wood[i]);
	  i++;
	}
      free(screen->world->wood);
    }
}

void	free_client(t_on_screen *screen)
{
  t_cli	*oldcli;

  if (screen->world != NULL && screen->world->client != NULL)
    {
      while (screen->world->client != NULL)
	{
	  free(screen->world->client->team);
	  oldcli = screen->world->client;
	  screen->world->client = screen->world->client->next;
	  free(oldcli);
	}

    }
  if (screen->brdcast.broadcast != NULL)
    free(screen->brdcast.broadcast);
}
