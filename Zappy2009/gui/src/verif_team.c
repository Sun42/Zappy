/*
** verif_team.c for verif_team in /u/all/yurdus_y/cu/rendu/c/Zappy2009/gui/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Sun Apr 26 22:24:22 2009 yavuz yurdusev
** Last update Sun Apr 26 22:24:23 2009 yavuz yurdusev
*/

#include "map.h"
#include "inventaire.h"
#include "command.h"

void	verif_team(t_on_screen *screen, SDL_Color textColor)
{
  char	name_team[20];

  name_team[0] = '\0';
  if (n_strlen(screen->info_bag->heros->team, 1) > 16)
    {
      copy_str(name_team, screen->info_bag->heros->team, 15);
      strcat(name_team, "...");
      screen->info_bag->bag = TTF_RenderText_Solid(screen->info_bag->font,
						   name_team, textColor);
    }
  else
    {
      copy_str(name_team, screen->info_bag->heros->team,
	       n_strlen(screen->info_bag->heros->team, 1));
      screen->info_bag->bag = TTF_RenderText_Solid(screen->info_bag->font,
						   name_team, textColor);
    }
}
