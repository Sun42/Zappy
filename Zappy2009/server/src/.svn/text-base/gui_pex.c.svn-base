/*
** gui_pex.c for gui_pex in /u/all/yurdus_y/cu/rendu/c/Zappy2009/server/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:28:42 2009 yavuz yurdusev
** Last update Thu Apr 23 20:28:43 2009 yavuz yurdusev
*/

#include "gui_command.h"

/*
** Un joueur expulse.
** "pex #n\n"
** #n --> Numero de joueur sur le serveur
*/
void	gui_pex(t_world *world, int num)
{
  char	nb[INT_LEN];
  int	len_nb;

  add_buffer_to_guis(world->pgui, "pex ", 4);
  len_nb = atio(num, nb);
  add_buffer_to_guis(world->pgui, nb, len_nb);
  add_buffer_to_guis(world->pgui, MSG_END, LEN_END);
}
