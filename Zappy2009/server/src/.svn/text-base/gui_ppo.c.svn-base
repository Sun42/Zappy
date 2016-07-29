/*
** gui_ppo.c for gui_ppo in /u/all/yurdus_y/cu/rendu/c/Zappy2009/server/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:26:52 2009 yavuz yurdusev
** Last update Thu Apr 23 20:26:53 2009 yavuz yurdusev
*/

#include <string.h>

#include "buffer.h"
#include "ia_command.h"
#include "gui_command.h"

/*
** mis ds le buffer
** "ppo #n X Y O\n"
 */
static void	gui_ppo_bis(t_cli *gui, t_cli *ia_found)
{
  char		nb[INT_LEN];
  int		len_nb;

  save_cmd(gui, "ppo ", 4, 'W');
  len_nb = atio(ia_found->numero, nb);
  save_cmd(gui, nb, len_nb, 'W');
  save_cmd(gui, MSG_SEP, LEN_SEP, 'W');
  len_nb = atio(ia_found->pos.x, nb);
  save_cmd(gui, nb, len_nb, 'W');
  save_cmd(gui, MSG_SEP, LEN_SEP, 'W');
  len_nb = atio(ia_found->pos.y, nb);
  save_cmd(gui, nb, len_nb, 'W');
  save_cmd(gui, MSG_SEP, LEN_SEP, 'W');
  len_nb = atio(ia_found->pos.direction, nb);
  save_cmd(gui, nb, len_nb, 'W');
  save_cmd(gui, MSG_END, LEN_END, 'W');
}

/*
** Position d’un joueur.
** recu -->	"ppo #n\n"
** envoie -->	"ppo #n X Y O\n"
** #n --> Numero de joueur sur le serveur
** X --> Largeur ou position horizontale
** Y --> Hauteur ou position verticale
** O --> Orientation (N:1, E:2, S:3, O:4)
*/
void	gui_ppo(t_world *world, t_cli *gui, char *cmd)
{
  int	num_ia;
  t_cli	*ia_found;

  num_ia = char_to_int(get_argument(cmd, 2));
  if (num_ia >= 0)
    {
      ia_found = get_ia(world->client, num_ia);
      if (ia_found != NULL)
	{
	  gui_ppo_bis(gui, ia_found);
	  return ;
	}
    }
  save_cmd(gui, GUI_SBP, GUI_SBPL, 'W');
}

void	gui_ppo_serv(t_world *world, t_cli *ia_move)
{
  char	nb[INT_LEN];
  int	len_nb;

  add_buffer_to_guis(world->pgui, "ppo ", 4);
  len_nb = atio(ia_move->numero, nb);
  add_buffer_to_guis(world->pgui, nb, len_nb);
  add_buffer_to_guis(world->pgui, MSG_SEP, LEN_SEP);
  len_nb = atio(ia_move->pos.x, nb);
  add_buffer_to_guis(world->pgui, nb, len_nb);
  add_buffer_to_guis(world->pgui, MSG_SEP, LEN_SEP);
  len_nb = atio(ia_move->pos.y, nb);
  add_buffer_to_guis(world->pgui, nb, len_nb);
  add_buffer_to_guis(world->pgui, MSG_SEP, LEN_SEP);
  len_nb = atio(ia_move->pos.direction, nb);
  add_buffer_to_guis(world->pgui, nb, len_nb);
  add_buffer_to_guis(world->pgui, MSG_END, LEN_END);
}
