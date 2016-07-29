/*
** gui_enw.c for gui_enw in /u/all/yurdus_y/cu/rendu/c/Zappy2009/server/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:29:33 2009 yavuz yurdusev
** Last update Thu Apr 23 20:29:33 2009 yavuz yurdusev
*/

#include <string.h>

#include "buffer.h"
#include "gui_command.h"

/*
** L’oeuf a ete pondu sur la case par le joueur.
** envoie --> "enw #e #n X Y\n"
** #e --> Numero d’oeuf sur le serveur
** #n --> Numero de joueur sur le serveur
** X --> Largeur ou position horizontale
** Y --> Hauteur ou position verticale
*/
void	gui_enw(t_cli *gui, t_cli *egg, int num_hen)
{
  char	nb[INT_LEN];
  int	len_nb;

  save_cmd(gui, "enw ", 4, 'W');
  len_nb = atio(egg->numero, nb);
  save_cmd(gui, nb, len_nb, 'W');
  save_cmd(gui, MSG_SEP, LEN_SEP, 'W');
  len_nb = atio(num_hen, nb);
  save_cmd(gui, nb, len_nb, 'W');
  save_cmd(gui, MSG_SEP, LEN_SEP, 'W');
  len_nb = atio(egg->pos.x, nb);
  save_cmd(gui, nb, len_nb, 'W');
  save_cmd(gui, MSG_SEP, LEN_SEP, 'W');
  len_nb = atio(egg->pos.y, nb);
  save_cmd(gui, nb, len_nb, 'W');
  save_cmd(gui, MSG_END, LEN_END, 'W');
}

void	gui_enw_serv(t_world *world, t_cli *egg, int num_hen)
{
  char	nb[INT_LEN];
  int	len_nb;

  add_buffer_to_guis(world->pgui, "enw ", 4);
  len_nb = atio(egg->numero, nb);
  add_buffer_to_guis(world->pgui, nb, len_nb);
  add_buffer_to_guis(world->pgui, MSG_SEP, LEN_SEP);
  len_nb = atio(num_hen, nb);
  add_buffer_to_guis(world->pgui, nb, len_nb);
  add_buffer_to_guis(world->pgui, MSG_SEP, LEN_SEP);
  len_nb = atio(egg->pos.x, nb);
  add_buffer_to_guis(world->pgui, nb, len_nb);
  add_buffer_to_guis(world->pgui, MSG_SEP, LEN_SEP);
  len_nb = atio(egg->pos.y, nb);
  add_buffer_to_guis(world->pgui, nb, len_nb);
  add_buffer_to_guis(world->pgui, MSG_END, LEN_END);
}
