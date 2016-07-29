/*
** gui_msz.c for gui_msz in /u/all/yurdus_y/cu/rendu/c/Zappy2009/server/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:29:11 2009 yavuz yurdusev
** Last update Thu Apr 23 20:29:12 2009 yavuz yurdusev
*/

#include <string.h>

#include "buffer.h"
#include "gui_command.h"

/*
** taille de la carte
** recu -->	"msz\n"
** envoie -->	"msz X Y\n"
** X --> Largeur ou position horizontale
** Y --> Hauteur ou position verticale
*/
void	gui_msz(t_world *world,
		t_cli *gui,
		char *cmd __attribute__((unused)))
{
  char	nb[INT_LEN];
  int	len_nb;

  save_cmd(gui, "msz ", 4, 'W');
  len_nb = atio(world->width, nb);
  save_cmd(gui, nb, len_nb, 'W');
  save_cmd(gui, MSG_SEP, LEN_SEP, 'W');
  len_nb = atio(world->height, nb);
  save_cmd(gui, nb, len_nb, 'W');
  save_cmd(gui, MSG_END, LEN_END, 'W');
}
