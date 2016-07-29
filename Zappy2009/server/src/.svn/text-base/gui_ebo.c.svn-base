/*
** gui_ebo.c for gui_ebo in /u/all/yurdus_y/cu/rendu/c/Zappy2009/server/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:29:53 2009 yavuz yurdusev
** Last update Thu Apr 23 20:29:54 2009 yavuz yurdusev
*/

#include "gui_command.h"

/*
** Un joueur s’est connecte pour l’oeuf.
** envoie --> "ebo #e\n"
** #e --> Numero d’oeuf sur le serveur
*/
void	gui_ebo(t_world *world, int num_egg)
{
  char	nb[INT_LEN];
  int	len_nb;

  add_buffer_to_guis(world->pgui, "ebo ", 4);
  len_nb = atio(num_egg, nb);
  add_buffer_to_guis(world->pgui, nb, len_nb);
  add_buffer_to_guis(world->pgui, MSG_END, LEN_END);
}
