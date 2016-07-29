/*
** gui_eht.c for gui_eht in /u/all/yurdus_y/cu/rendu/c/Zappy2009/server/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:29:40 2009 yavuz yurdusev
** Last update Thu Apr 23 20:29:40 2009 yavuz yurdusev
*/

#include "gui_command.h"

/*
** L’oeuf eclot.
** envoie --> "eht #e\n"
** #e --> Numero d’oeuf sur le serveur
*/
void	gui_eht(t_world *world, int num_egg)
{
  char	nb[INT_LEN];
  int	len_nb;

  add_buffer_to_guis(world->pgui, "eht ", 4);
  len_nb = atio(num_egg, nb);
  add_buffer_to_guis(world->pgui, nb, len_nb);
  add_buffer_to_guis(world->pgui, MSG_END, LEN_END);
}
