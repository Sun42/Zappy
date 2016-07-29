/*
** gui_sgt.c for gui_sgt in /u/all/yurdus_y/cu/rendu/c/Zappy2009/server/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:26:03 2009 yavuz yurdusev
** Last update Thu Apr 23 20:26:03 2009 yavuz yurdusev
*/

#include <string.h>

#include "buffer.h"
#include "gui_command.h"

/*
** Demande de l’unité de temps courante sur le serveur.
** recu -->	"sgt\n"
** envoie -->	"sgt T\n"
** T --> Unite de temps
*/
void	gui_sgt(t_world *world,
		t_cli *gui,
		char *cmd __attribute__((unused)))
{
  char	nb[INT_LEN];
  int	len_nb;

  save_cmd(gui, "sgt ", 4, 'W');
  len_nb = atio(1000000 / world->speed, nb);
  save_cmd(gui, nb, len_nb, 'W');
  save_cmd(gui, MSG_END, LEN_END, 'W');
}
