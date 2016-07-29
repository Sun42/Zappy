/*
** serv_bct.c for serv_bct in /u/all/yurdus_y/cu/rendu/c/Zappy2009/gui/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:42:17 2009 yavuz yurdusev
** Last update Thu Apr 23 20:42:18 2009 yavuz yurdusev
*/

#include "map.h"
#include "func_object.h"
#include "command.h"
#include "inventaire.h"

void		serv_bct(t_on_screen *screen, char *msg)
{
  t_point	coor;
  int		i;
  int		max;
  t_res		caze;

  i = 0;
  coor.x = atoi(get_argument(msg, 2));
  coor.y = atoi(get_argument(msg, 3));
  if (!is_valid_case(coor.x, coor.y, screen))
    return ;
  max = get_nb_arg(msg);
  while (i < (max - 3))
    {
      if (i < NB_OBJETS)
	caze.objet[i] = atoi(get_argument(msg, i + 4));
      i++;
    }
  caze.objet[i] = 0;
  caze.objet[i + 1] = 0;
  fill_case(screen, &coor, &caze);
  print_object_on_case(screen, &coor, 0);
  screen->world->loading = 1;
}
