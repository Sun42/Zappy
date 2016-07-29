/*
** gui_pin.c for gui_pin in /u/all/yurdus_y/cu/rendu/c/Zappy2009/server/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:28:03 2009 yavuz yurdusev
** Last update Thu Apr 23 20:28:04 2009 yavuz yurdusev
*/

#include <string.h>

#include "buffer.h"
#include "ia_command.h"
#include "gui_command.h"

/*
** Mis ds le buffer
** "pin #n X Y...\n"
*/
void	gui_pin_bis(t_world *world, t_cli *gui, t_cli *ia_found)
{
  char	nb[INT_LEN];
  int	len_nb;

  update_food(world, ia_found);
  save_cmd(gui, "pin ", 4, 'W');
  len_nb = atio(ia_found->numero, nb);
  save_cmd(gui, nb, len_nb, 'W');
  save_cmd(gui, MSG_SEP, LEN_SEP, 'W');
  len_nb = atio(ia_found->pos.x, nb);
  save_cmd(gui, nb, len_nb, 'W');
  save_cmd(gui, MSG_SEP, LEN_SEP, 'W');
  len_nb = atio(ia_found->pos.y, nb);
  save_cmd(gui, nb, len_nb, 'W');
  gui_print_ressource(gui, &(ia_found->invent), nb);
  save_cmd(gui, MSG_END, LEN_END, 'W');
}

/*
** Inventaire d un joueur
** recu -->	"pin #n\n"
** envoie -->	"pin #n X Y q q q q q q q\n"
** #n --> Numero de joueur sur le serveur
** X --> Largeur ou position horizontale
** Y --> Hauteur ou position verticale
** q --> Quantite
*/
void	gui_pin(t_world *world, t_cli *gui, char *cmd)
{
  int	num_ia;
  t_cli	*ia_found;

  num_ia = char_to_int(get_argument(cmd, 2));
  if (num_ia >= 0)
    {
      ia_found = get_ia(world->client, num_ia);
      if (ia_found != NULL)
	{
	  gui_pin_bis(world, gui, ia_found);
	  return ;
	}
    }
  save_cmd(gui, GUI_SBP, GUI_SBPL, 'W');
}

void	gui_pin_serv(t_world *world, t_cli *ia_found)
{
  char	nb[INT_LEN];
  int	len_nb;

  update_food(world, ia_found);
  add_buffer_to_guis(world->pgui, "pin ", 4);
  len_nb = atio(ia_found->numero, nb);
  add_buffer_to_guis(world->pgui, nb, len_nb);
  add_buffer_to_guis(world->pgui, MSG_SEP, LEN_SEP);
  len_nb = atio(ia_found->pos.x, nb);
  add_buffer_to_guis(world->pgui, nb, len_nb);
  add_buffer_to_guis(world->pgui, MSG_SEP, LEN_SEP);
  len_nb = atio(ia_found->pos.y, nb);
  add_buffer_to_guis(world->pgui, nb, len_nb);
  gui_print_ressource_serv(world, &(ia_found->invent), nb);
  add_buffer_to_guis(world->pgui, MSG_END, LEN_END);
}
