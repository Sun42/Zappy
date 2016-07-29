/*
** blit_and_verif.c for blit_and_verif in /u/all/yurdus_y/cu/rendu/c/Zappy2009/gui/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Sun Apr 26 22:24:09 2009 yavuz yurdusev
** Last update Sun Apr 26 22:24:09 2009 yavuz yurdusev
*/

#include "map.h"
#include "inventaire.h"
#include "move_map.h"
#include "x_func_sdl.h"

void	verif_for_blit(t_on_screen *screen)
{
  if (screen->info_bag != NULL)
    {
      if (screen->info_bag->bag != NULL && screen->info_bag->font != NULL &&
	  screen->info_bag->heros != NULL)
	aff_bag(screen, screen->info_bag->textcolor);
    }
}

void		blit_click(t_on_screen *screen, int herosX, int herosY)
{
  t_point	pos;

  xsdl_blitsurface(screen->info_bag->play, NULL,
		   screen->window, &screen->info_bag->pos_play);
  xsdl_blitsurface(screen->info_bag->info_invent, NULL,
		   screen->window, &screen->info_bag->pos_invent);
  aff_bag(screen, screen->info_bag->textcolor);
  pos.x = screen->info_bag->heros->pos.pos_player.x;
  pos.y = screen->info_bag->heros->pos.pos_player.y;
  if (check_in_camera(screen, &pos, 0))
    {
      color_line(screen, herosX, herosY, screen->info_bag->heros);
      color_column(screen, herosX, herosY, screen->info_bag->heros);
    }
}
