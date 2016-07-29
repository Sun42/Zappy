/*
** free_all.c for free_all in /u/all/yurdus_y/cu/rendu/c/Zappy2009/gui/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:41:59 2009 yavuz yurdusev
** Last update Sun Apr 26 12:28:56 2009 yavuz yurdusev
*/

#include <stdio.h>
#include <stdlib.h>

#include "map.h"
#include "func_xmemory.h"
#include "command.h"

void	free_gui(t_on_screen *screen)
{
  free_allcmd(screen->my_msg.lcmdr);
  free_allcmd(screen->my_msg.lcmdw);
  if (screen->info_bag != NULL)
    {
      if (screen->info_bag->bag != NULL)
	SDL_FreeSurface(screen->info_bag->bag);
      if (screen->info_bag->play != NULL)
	SDL_FreeSurface(screen->info_bag->play);
      if (screen->info_bag->info_invent != NULL)
	SDL_FreeSurface(screen->info_bag->info_invent);
    }
  free_client(screen);
  free_map(screen);
  free_ressources(screen);
  free_player(screen);
  free_wood(screen);
}

static void	exec_lastcmd(t_on_screen *screen)
{
  int		len;

  len = access_cmdlen(&(screen->my_msg), 'R');
  while (len > 0)
    {
      read_command(screen);
      len = access_cmdlen(&(screen->my_msg), 'R');
    }
}

void	gui_exit(t_on_screen *screen, const int type_exit)
{
  exec_lastcmd(screen);
  free_gui(screen);
  SDLNet_Quit();
  SDL_Quit();
  exit(type_exit);
}
