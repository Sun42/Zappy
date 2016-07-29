/*
** gui_pie.c for gui_pie in /u/all/yurdus_y/cu/rendu/c/Zappy2009/server/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:28:16 2009 yavuz yurdusev
** Last update Thu Apr 23 20:28:16 2009 yavuz yurdusev
*/

#include "gui_command.h"

/*
** Fin de l’incantation sur la case donnée avec le résultat R (0 ou 1).
** envoie --> "pie X Y R\n"
** X --> Largeur ou position horizontale
** Y --> Hauteur ou position verticale
** R --> Résultat de l’incantation
*/
void	gui_pie(t_world *world, int y, int x, char res_inc)
{
  char	nb[INT_LEN];
  int	len_nb;

  add_buffer_to_guis(world->pgui, "pie ", 4);
  len_nb = atio(x, nb);
  add_buffer_to_guis(world->pgui, nb, len_nb);
  add_buffer_to_guis(world->pgui, MSG_SEP, LEN_SEP);
  len_nb = atio(y, nb);
  add_buffer_to_guis(world->pgui, nb, len_nb);
  add_buffer_to_guis(world->pgui, MSG_SEP, LEN_SEP);
  add_buffer_to_guis(world->pgui, &res_inc, 1);
  add_buffer_to_guis(world->pgui, MSG_END, LEN_END);
}
