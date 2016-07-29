/*
** gui_pdr.c for gui_pdr in /u/all/yurdus_y/cu/rendu/c/Zappy2009/server/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:28:51 2009 yavuz yurdusev
** Last update Thu Apr 23 20:28:52 2009 yavuz yurdusev
*/

#include "gui_command.h"

/*
** Le joueur jette une ressource.
** envoie --> "pdr #n i\n"
** #n --> Numero de joueur sur le serveur
** i --> Numero de ressource
*/
void	gui_pdr(t_world *world, int num_ia, int num_res)
{
  char	nb[INT_LEN];
  int	len_nb;

  add_buffer_to_guis(world->pgui, "pdr ", 4);
  len_nb = atio(num_ia, nb);
  add_buffer_to_guis(world->pgui, nb, len_nb);
  add_buffer_to_guis(world->pgui, MSG_SEP, LEN_SEP);
  len_nb = atio(num_res, nb);
  add_buffer_to_guis(world->pgui, nb, len_nb);
  add_buffer_to_guis(world->pgui, MSG_END, LEN_END);
}
