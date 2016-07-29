/*
** gui_pnw.c for gui_pnw in /u/all/yurdus_y/cu/rendu/c/Zappy2009/server/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:26:59 2009 yavuz yurdusev
** Last update Thu Apr 23 20:27:00 2009 yavuz yurdusev
*/

#include <string.h>

#include "buffer.h"
#include "gui_command.h"

/*
** Connexion d’un nouveau joueur.
** "pnw #n X Y O L N\n"
** #n --> Numero de joueur sur le serveur
** X --> Largeur ou position horizontale
** Y --> Hauteur ou position verticale
** O --> Orientation (N:1, E:2, S:3, O:4)
** L --> Niveau du joueur ou de l’incantation
** N --> nom equipe
*/
void	gui_pnw(t_cli *gui, t_cli *ia)
{
  char	nb[INT_LEN];
  int	len_nb;

  save_cmd(gui, "pnw ", 4, 'W');
  len_nb = atio(ia->numero, nb);
  save_cmd(gui, nb, len_nb, 'W');
  save_cmd(gui, MSG_SEP, LEN_SEP, 'W');
  len_nb = atio(ia->pos.x, nb);
  save_cmd(gui, nb, len_nb, 'W');
  save_cmd(gui, MSG_SEP, LEN_SEP, 'W');
  len_nb = atio(ia->pos.y, nb);
  save_cmd(gui, nb, len_nb, 'W');
  save_cmd(gui, MSG_SEP, LEN_SEP, 'W');
  len_nb = atio(ia->pos.direction, nb);
  save_cmd(gui, nb, len_nb, 'W');
  save_cmd(gui, MSG_SEP, LEN_SEP, 'W');
  len_nb = atio((int)ia->lvl, nb);
  save_cmd(gui, nb, len_nb, 'W');
  save_cmd(gui, MSG_SEP, LEN_SEP, 'W');
  save_cmd(gui, ia->team->name, strlen(ia->team->name), 'W');
  save_cmd(gui, MSG_END, LEN_END, 'W');
}

void	gui_pnw_serv(t_world *world, t_cli *ia)
{
  char	nb[INT_LEN];
  int	len_nb;

  add_buffer_to_guis(world->pgui, "pnw ", 4);
  len_nb = atio(ia->numero, nb);
  add_buffer_to_guis(world->pgui, nb, len_nb);
  add_buffer_to_guis(world->pgui, MSG_SEP, LEN_SEP);
  len_nb = atio(ia->pos.x, nb);
  add_buffer_to_guis(world->pgui, nb, len_nb);
  add_buffer_to_guis(world->pgui, MSG_SEP, LEN_SEP);
  len_nb = atio(ia->pos.y, nb);
  add_buffer_to_guis(world->pgui, nb, len_nb);
  add_buffer_to_guis(world->pgui, MSG_SEP, LEN_SEP);
  len_nb = atio(ia->pos.direction, nb);
  add_buffer_to_guis(world->pgui, nb, len_nb);
  add_buffer_to_guis(world->pgui, MSG_SEP, LEN_SEP);
  len_nb = atio((int)ia->lvl, nb);
  add_buffer_to_guis(world->pgui, nb, len_nb);
  add_buffer_to_guis(world->pgui, MSG_SEP, LEN_SEP);
  add_buffer_to_guis(world->pgui, ia->team->name, strlen(ia->team->name));
  add_buffer_to_guis(world->pgui, MSG_END, LEN_END);
}
