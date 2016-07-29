/*
** serv_tna.c for serv_tna in /u/all/yurdus_y/cu/rendu/c/Zappy2009/gui/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:38:47 2009 yavuz yurdusev
** Last update Thu Apr 23 20:38:47 2009 yavuz yurdusev
*/

#include "command.h"
#include "inventaire.h"

void	serv_tna(t_on_screen *screen,
		 char *msg __attribute__((unused)))
{
  if (screen->world->loading)
    screen->world->loading = 0;
}
