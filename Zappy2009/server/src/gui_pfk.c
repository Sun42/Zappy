/*
** gui_pfk.c for gui_pfk in /u/all/yurdus_y/cu/rendu/c/Zappy2009/server/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:28:35 2009 yavuz yurdusev
** Last update Thu Apr 23 20:28:36 2009 yavuz yurdusev
*/

#include "gui_command.h"

/*
** Le joueur pond un oeuf.
** envoie --> "pfk #n\n"
** #n --> Numero de joueur sur le serveur
*/
void	gui_pfk(t_world *world, int num)
{
  char	nb[INT_LEN];
  int	len_nb;

  add_buffer_to_guis(world->pgui, "pfk ", 4);
  len_nb = atio(num, nb);
  add_buffer_to_guis(world->pgui, nb, len_nb);
  add_buffer_to_guis(world->pgui, MSG_END, LEN_END);
}
