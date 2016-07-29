/*
** infos_inventaire.c for infos_inventaire in /u/all/yurdus_y/cu/rendu/c/Zappy2009/gui/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:42:22 2009 yavuz yurdusev
** Last update Thu Apr 23 22:05:20 2009 yavuz yurdusev
*/

#include "map.h"
#include "move_map.h"
#include "inventaire.h"
#include "x_func_sdl.h"
#include "func_xy_max.h"

void	aff_bag(t_on_screen *screen, SDL_Color textcolor)
{
  screen->info_bag->font = NULL;
  if (TTF_Init() == -1)
    perror("Erreur : TTF_Init() --> aff_bag()");
  screen->info_bag->font = TTF_OpenFont("images/CaslonBold.ttf", 28);
  if (screen->info_bag->font == NULL)
    perror("Erreur: TTF_OpenFont() --> aff_bag()");
  var_inventaire(screen, textcolor);
  var_team(screen, textcolor);
  var_level(screen, textcolor);
  TTF_CloseFont(screen->info_bag->font);
  TTF_Quit();
}

void	right_click(t_on_screen *screen)
{
  if (screen->info_bag != NULL)
    {
      if (screen->info_bag->info_invent != NULL)
	SDL_FreeSurface(screen->info_bag->info_invent);
      if (screen->info_bag->play != NULL)
	SDL_FreeSurface(screen->info_bag->play);
      screen->info_bag->info_invent = NULL;
      screen->info_bag->play = NULL;
      screen->info_bag->bag = NULL;
      screen->info_bag->font = NULL;
      screen->world->loading = 0;
      screen->info_bag->have_invent = 0;
    }
}

void	left_click(t_on_screen *screen)
{
  screen->info_bag->textcolor.r = 0;
  screen->info_bag->textcolor.g = 0;
  screen->info_bag->textcolor.b = 0;
  screen->info_bag->bag = NULL;
  screen->info_bag->pos_invent.x = 0;
  screen->info_bag->pos_invent.y = 100;
  screen->info_bag->pos_play.x = 300;
  screen->info_bag->pos_play.y = 0;
  screen->info_bag->have_invent = 1;
}

/* print_map dans 1er while (map.c) */
void		blit_invent(t_on_screen *screen)
{
  int		herosX;
  int		herosY;

  herosX = CENTER_X(get_x_max(screen));
  herosY = CENTER_Y(get_y_max(screen));
  if (screen->info_bag->have_invent)
    {
      if (screen->info_bag->heros != NULL)
	{
	  if (screen->info_bag->play == NULL)
	    screen->info_bag->play = img_load("images/play.png");
	  if (screen->info_bag->info_invent == NULL)
	    screen->info_bag->info_invent = img_load("images/inventaire_hero.png");
	  blit_click(screen, herosX, herosY);
	}
      verif_for_blit(screen);
    }
  else
    {
      right_click(screen);
      screen->world->loading = 0;
    }
}
