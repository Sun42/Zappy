/*
** gui_edi.c for gui_edi in /u/all/yurdus_y/cu/rendu/c/Zappy2009/server/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:29:46 2009 yavuz yurdusev
** Last update Thu Apr 23 20:29:47 2009 yavuz yurdusev
*/

#include "gui_command.h"

/*
** L’oeuf eclos est mort de faim.
** envoie --> "edi #e\n"
** #e --> Numero d’oeuf sur le serveur
*/
void	gui_edi(t_world *world, int num_ghost)
{
  char	nb[INT_LEN];
  int	len_nb;

  add_buffer_to_guis(world->pgui, "edi ", 4);
  len_nb = atio(num_ghost, nb);
  add_buffer_to_guis(world->pgui, nb, len_nb);
  add_buffer_to_guis(world->pgui, MSG_END, LEN_END);
}
