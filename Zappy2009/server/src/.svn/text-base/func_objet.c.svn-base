/*
** func_objet.c for func_objet in /u/all/yurdus_y/cu/rendu/c/Zappy2009/server/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:31:19 2009 yavuz yurdusev
** Last update Sat Apr 25 15:41:40 2009 yavuz yurdusev
*/

#include "ia_command.h"

static const t_objet	gl_objet[NB_OBJETS + 2] =
  {
    {"nourriture", FOOD, 10},
    {"linemate", LINEMATE, 8},
    {"deraumere", DERAUMERE, 9},
    {"sibur", SIBUR, 5},
    {"mendiane", MENDIANE, 8},
    {"phiras", PHIRAS, 6},
    {"thystame", THYSTAME, 8},
    {NULL, 0, 0},
    {"joueur", PLAYER, 6}
  };

int	get_num_objet(const char *name_obj)
{
  int	i;

  i = 0;
  while (gl_objet[i].name != NULL)
    {
      if (cmd_cmp(name_obj, gl_objet[i].name))
	return (i);
      i++;
    }
  return (-1);
}

char	*get_name_objet(int num_objet, int *len)
{
  *len = gl_objet[num_objet].len;
  return (gl_objet[num_objet].name);
}

void	init_inventaire(t_res *res)
{
  res->objet[FOOD] = 0;
  res->objet[LINEMATE] = 0;
  res->objet[DERAUMERE] = 0;
  res->objet[SIBUR] = 0;
  res->objet[MENDIANE] = 0;
  res->objet[PHIRAS] = 0;
  res->objet[THYSTAME] = 0;
  res->nb_joueur = 0;
  res->elevation = 0;
}
