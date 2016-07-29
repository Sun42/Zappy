/*
** func_egg.c for func_egg in /u/all/yurdus_y/cu/rendu/c/Zappy2009/gui/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:40:10 2009 yavuz yurdusev
** Last update Thu Apr 23 20:40:12 2009 yavuz yurdusev
*/

#include "map.h"

static void	del_oeuf(t_on_screen *screen, t_point *pos, int i)
{
  int		nb_oeuf;

  nb_oeuf = screen->world->map[pos->y][pos->x].objet[OEUF];
  if (nb_oeuf > 1)
    {
      nb_oeuf -= 1;
      screen->world->map[pos->y][pos->x].oeuf_num[i] =
	screen->world->map[pos->y][pos->x].oeuf_num[nb_oeuf];
    }
  else
    {
      free(screen->world->map[pos->y][pos->x].oeuf_num);
      screen->world->map[pos->y][pos->x].oeuf_num = NULL;
    }
}

t_point		oeuf_killer(t_on_screen *screen, int oeuf_num)
{
  int		i;
  t_point	pos;

  pos.x = 0;
  pos.y = 0;
  while (pos.y < screen->world->height)
    {
      pos.x = 0;
      while (pos.x < screen->world->width)
	{
	  i = 0;
	  while (i < screen->world->map[pos.y][pos.x].objet[OEUF])
	    {
	      if (screen->world->map[pos.y][pos.x].oeuf_num[i] == oeuf_num)
		{
		  del_oeuf(screen, &pos, i);
		  return (pos);
		}
	      i++;
	    }
	  pos.x += 1;
	}
      pos.y += 1;
    }
  return (pos);
}
