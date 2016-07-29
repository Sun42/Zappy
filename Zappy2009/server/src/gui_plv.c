/*
** gui_plv.c for gui_plv in /u/all/yurdus_y/cu/rendu/c/Zappy2009/server/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:27:06 2009 yavuz yurdusev
** Last update Thu Apr 23 20:27:08 2009 yavuz yurdusev
*/

#include <string.h>

#include "buffer.h"
#include "ia_command.h"
#include "gui_command.h"

/*
** Mis ds le buffer
** "plv #n L\n"
*/
static void	gui_plv_bis(t_cli *gui, t_cli *ia_found)
{
  char		nb[INT_LEN];
  int		len_nb;

  save_cmd(gui, "plv ", 4, 'W');
  len_nb = atio(ia_found->numero, nb);
  save_cmd(gui, nb, len_nb, 'W');
  save_cmd(gui, MSG_SEP, LEN_SEP, 'W');
  len_nb = atio((int)ia_found->lvl, nb);
  save_cmd(gui, nb, len_nb, 'W');
  save_cmd(gui, MSG_END, LEN_END, 'W');
}

/*
** Niveau d’un joueur.
** recu -->	"plv #n\n"
** envoie -->	"plv #n L\n"
** #n --> Numero de joueur sur le serveur
** L --> Niveau du joueur ou de l’incantation
*/
void	gui_plv(t_world *world, t_cli *gui, char *cmd)
{
  int	num_ia;
  t_cli	*ia_found;

  num_ia = char_to_int(get_argument(cmd, 2));
  if (num_ia >= 0)
    {
      ia_found = get_ia(world->client, num_ia);
      if (ia_found != NULL)
	{
	  gui_plv_bis(gui, ia_found);
	  return ;
	}
    }
  save_cmd(gui, GUI_SBP, GUI_SBPL, 'W');
}

void	gui_plv_serv(t_world *world, t_cli *ia_found)
{
  char	nb[INT_LEN];
  int	len_nb;

  add_buffer_to_guis(world->pgui, "plv ", 4);
  len_nb = atio(ia_found->numero, nb);
  add_buffer_to_guis(world->pgui, nb, len_nb);
  add_buffer_to_guis(world->pgui, MSG_SEP, LEN_SEP);
  len_nb = atio((int)ia_found->lvl, nb);
  add_buffer_to_guis(world->pgui, nb, len_nb);
  add_buffer_to_guis(world->pgui, MSG_END, LEN_END);
}
