/*
** gui_pdi.c for gui_pdi in /u/all/yurdus_y/cu/rendu/c/Zappy2009/server/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:28:58 2009 yavuz yurdusev
** Last update Thu Apr 23 20:28:59 2009 yavuz yurdusev
*/

#include "gui_command.h"

/*
** Le joueur est mort de faim.
** envoie --> "pdi #n\n"
** #n --> Numero de joueur sur le serveur
*/
void	gui_pdi(t_world *world, int num_dead)
{
  char	nb[INT_LEN];
  int	len_nb;

  add_buffer_to_guis(world->pgui, "pdi ", 4);
  len_nb = atio(num_dead, nb);
  add_buffer_to_guis(world->pgui, nb, len_nb);
  add_buffer_to_guis(world->pgui, MSG_END, LEN_END);
}
