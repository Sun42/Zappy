/*
** func_init_object.c for func_init_object in /u/all/yurdus_y/cu/rendu/c/Zappy2009/gui/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:40:54 2009 yavuz yurdusev
** Last update Thu Apr 23 22:02:17 2009 yavuz yurdusev
*/

#include "map.h"
#include "func_xmemory.h"
#include "func_init_ghost.h"
#include "func_init_perso.h"
#include "x_func_sdl.h"
#include "wood.h"

static const t_init	gl_init[] =
  {
    {0, "images/pomme.png"},
    {1, "images/melanite.png"},
    {2, "images/emeraude.png"},
    {3, "images/rubis.png"},
    {4, "images/diamand.png"},
    {5, "images/saphir.png"},
    {6, "images/amethyst.png"},
    {7, "images/oeuf.png"},
    {8, "images/incantation.png"},
    {9, NULL}
  };

void	init_ressources(t_on_screen *screen)
{
  int	i;

  screen->world->ressources = xmalloc(sizeof(SDL_Surface *) * NB_OBJETS);
  if (screen->world->ressources == NULL)
    gui_exit(screen, EXIT_FAILURE);
  i = 0;
  while (gl_init[i].id != 9)
    {
      screen->world->ressources[i] = img_load(gl_init[i].imagefile);
      i++;
    }
  screen->world->portal = img_load("images/portal.png");
  screen->world->ghost.player = NULL;
  init_player(screen);
  init_ghost(screen);
  init_wood_img(screen);
}
