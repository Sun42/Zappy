/*
** gui_pbc.c for gui_pbc in /u/all/yurdus_y/cu/rendu/c/Zappy2009/server/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:29:05 2009 yavuz yurdusev
** Last update Thu Apr 23 20:29:05 2009 yavuz yurdusev
*/

#include <string.h>

#include "gui_command.h"

/*
** Un joueur fait un broadcast.
** envoie --> "pbc #n M\n"
** #n --> Numero de joueur sur le serveur
** M --> Message
*/
void	gui_pbc(t_world *world, int num, char *msg)
{
  char	nb[INT_LEN];
  int	len_nb;

  add_buffer_to_guis(world->pgui, "pbc ", 4);
  len_nb = atio(num, nb);
  add_buffer_to_guis(world->pgui, nb, len_nb);
  add_buffer_to_guis(world->pgui, msg, strlen(msg));
}
