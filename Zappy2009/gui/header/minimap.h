/*
** minimap.h for minimap in /u/all/yurdus_y/cu/rendu/c/Zappy2009/gui/header
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:29:31 2009 yavuz yurdusev
** Last update Thu Apr 23 20:29:33 2009 yavuz yurdusev
*/

#ifndef MINIMAP_H_
# define MINIMAP_H_

void	init_minimap(t_on_screen *screen);
void	aff_link(t_on_screen *screen, int width, int height);
void	aff_egg(t_on_screen *screen, int width, int height);
int	display_mini(t_on_screen *screen, int i);
void	aff_ghost(t_on_screen *screen, int width, int height);

#endif /*! MINIMAP_H_ !*/
