/*
** func_init_perso.c for func_init_perso in /u/all/yurdus_y/cu/rendu/c/Zappy2009/gui/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:41:07 2009 yavuz yurdusev
** Last update Thu Apr 23 22:04:10 2009 yavuz yurdusev
*/

#include "map.h"
#include "func_xmemory.h"
#include "x_func_sdl.h"

static const t_init	gl_init[] =
  {
    {1, "images/link_purple.png"},
    {2, "images/link_green.png"},
    {3, "images/link_blue.png"},
    {4, "images/link_red.png"},
    {5, "images/link_black.png"},
    {6, "images/link_dark.png"},
    {7, "images/link_blood.png"},
    {8, "images/link_fire.png"},
    {0, NULL}
  };

void	init_player(t_on_screen *screen)
{
  int	i;

  screen->world->player = xmalloc(sizeof(SDL_Surface *) * 8);
  if (screen->world->player == NULL)
    gui_exit(screen, EXIT_FAILURE);
  i = 0;
  while (gl_init[i].id != 0)
    {
      screen->world->player[i] = img_load(gl_init[i].imagefile);
      i++;
    }
}

void	init_perso(t_on_screen *screen, t_cli *client)
{
  client->mob.player = screen->world->player[client->lvl - 1];
}

void	init_face(t_cli *client)
{
  if (client->pos.direction == NORD)
    client->mob.i_clip = 0 + 1;
  else if (client->pos.direction == SUD)
    client->mob.i_clip = 6 + 1;
  else if (client->pos.direction == EST)
    client->mob.i_clip = 3 + 1;
  else
    client->mob.i_clip = 9 + 1;
}
