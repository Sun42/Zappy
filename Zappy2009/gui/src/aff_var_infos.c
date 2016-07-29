/*
** aff_var_infos.c for aff_var_infos in /u/all/yurdus_y/cu/rendu/c/Zappy2009/gui/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:33:50 2009 yavuz yurdusev
** Last update Sun Apr 26 22:46:46 2009 yavuz yurdusev
*/

#include "map.h"
#include "inventaire.h"
#include "socket.h"
#include "x_func_sdl.h"
#include "command.h"

void	copy_str(char *dest, char *src, int size)
{
  int	i;

  i = 0;
  while (i < size)
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = '\0';
}

static void	display_values(t_on_screen *screen, SDL_Color textcolor)
{
  char	nb_res[4];

  nb_res[0] = '\0';
  nb_res[1] = '\0';
  nb_res[2] = '\0';
  nb_res[3] = '\0';
  if (n_strlen(screen->info_bag->translate, 1) > 3)
    screen->info_bag->bag = TTF_RenderUTF8_Solid(screen->info_bag->font,
						 "∞", textcolor);
  else
    {
      copy_str(nb_res, screen->info_bag->translate,
	       n_strlen(screen->info_bag->translate, 1));
      screen->info_bag->bag = TTF_RenderText_Solid(screen->info_bag->font,
						   nb_res,
						   textcolor);
    }
}

void	var_inventaire(t_on_screen *screen, SDL_Color textcolor)
{
  int	i;
  int	tricks;

  tricks = 300;
  i = 0;
  while (i < 7)
    {
      screen->info_bag->pos_bag.x = 30;
      screen->info_bag->pos_bag.y = i * 75 + tricks;
      atio(screen->info_bag->heros->invent.objet[i],
	   screen->info_bag->translate);
      if (screen->info_bag->font == NULL)
	perror("Erreur: font non charge --> var_inventaire()");
      display_values(screen, textcolor);
      if (screen->info_bag->bag == NULL)
	perror("Erreur: inventaire vide --> var_inventaire()");
      xsdl_blitsurface(screen->info_bag->bag, NULL, screen->window,
		   &screen->info_bag->pos_bag);
      SDL_FreeSurface(screen->info_bag->bag);
      i++;
    }
  screen->info_bag->bag = NULL;
}

void	var_team(t_on_screen *screen, SDL_Color textcolor)
{
  screen->info_bag->pos_team_name.x = 550;
  screen->info_bag->pos_team_name.y = 5;
  verif_team(screen, textcolor);
  if (screen->info_bag->bag == NULL)
    {
      perror("Erreur: inventaire vide --> var_inventaire()");
      return ;
    }
  xsdl_blitsurface(screen->info_bag->bag, NULL, screen->window,
		      &screen->info_bag->pos_team_name);
  SDL_FreeSurface(screen->info_bag->bag);
  screen->info_bag->bag = NULL;
}

void	var_level(t_on_screen *screen, SDL_Color textcolor)
{
  sprintf(screen->info_bag->translate, "%d", screen->info_bag->heros->lvl);
  screen->info_bag->pos_level.x = 935;
  screen->info_bag->pos_level.y = 5;
  screen->info_bag->bag = TTF_RenderText_Solid(screen->info_bag->font,
					       screen->info_bag->translate,
					       textcolor);
  if (screen->info_bag->bag == NULL)
    {
      perror("Erreur: inventaire vide --> var_inventaire()");
      return ;
    }
  xsdl_blitsurface(screen->info_bag->bag, NULL, screen->window,
		   &screen->info_bag->pos_level);
  SDL_FreeSurface(screen->info_bag->bag);
  screen->info_bag->bag = NULL;
}
