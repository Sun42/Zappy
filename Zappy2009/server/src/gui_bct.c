/*
** gui_bct.c for gui_bct in /u/all/yurdus_y/cu/rendu/c/Zappy2009/server/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:30:00 2009 yavuz yurdusev
** Last update Thu Apr 23 20:30:01 2009 yavuz yurdusev
*/

#include <string.h>

#include "buffer.h"
#include "ia_command.h"
#include "gui_command.h"

/*
** mis ds le buffer
** " q q q q q q q"
*/
void	gui_print_ressource(t_cli *gui, t_res *caz, char nb[INT_LEN])
{
  int	i;

  i = 0;
  while (i < NB_OBJETS)
    {
      save_cmd(gui, MSG_SEP, LEN_SEP, 'W');
      atio(caz->objet[i], nb);
      save_cmd(gui, nb, strlen(nb), 'W');
      i++;
    }
}

/*
** mis ds le buffer
** "bct X Y...\n"
*/
void	gui_bct_bis(t_world *world, t_cli *gui, int y, int x)
{
  char	nb[INT_LEN];
  int	len_nb;

  save_cmd(gui, "bct ", 4, 'W');
  len_nb = atio(x, nb);
  save_cmd(gui, nb, len_nb, 'W');
  save_cmd(gui, MSG_SEP, LEN_SEP, 'W');
  len_nb = atio(y, nb);
  save_cmd(gui, nb, len_nb, 'W');
  gui_print_ressource(gui, &(world->map[y][x]), nb);
  save_cmd(gui, MSG_END, LEN_SEP, 'W');
}

/*
** contenu d une case
** recu -->	"bct X Y\n"
** envoie -->	"bct X Y q q q q q q q\n"
** X --> Largeur ou position horizontale
** Y --> Hauteur ou position verticale
** q --> quantite
*/
void	gui_bct(t_world *world, t_cli *gui, char *cmd)
{
  int	x;
  int	y;

  x = char_to_int(get_argument(cmd, 2));
  if (x >= 0 && x < world->width)
    {
      y = char_to_int(get_argument(cmd, 3));
      if (y >= 0 && y < world->height)
	{
	  gui_bct_bis(world, gui, y, x);
	  return ;
	}
    }
  save_cmd(gui, GUI_SBP, GUI_SBPL, 'W');
}

void	gui_print_ressource_serv(t_world *world, t_res *caz, char nb[INT_LEN])
{
  int	i;
  int	len_nb;

  i = 0;
  while (i < NB_OBJETS)
    {
      add_buffer_to_guis(world->pgui, MSG_SEP, LEN_SEP);
      len_nb = atio(caz->objet[i], nb);
      add_buffer_to_guis(world->pgui, nb, len_nb);
      i++;
    }
}

void	gui_bct_serv(t_world *world, int y, int x)
{
  char	nb[INT_LEN];
  int	len_nb;

  add_buffer_to_guis(world->pgui, "bct ", 4);
  len_nb = atio(x, nb);
  add_buffer_to_guis(world->pgui, nb, len_nb);
  add_buffer_to_guis(world->pgui, MSG_SEP, LEN_SEP);
  len_nb = atio(y, nb);
  add_buffer_to_guis(world->pgui, nb, len_nb);
  gui_print_ressource_serv(world, &(world->map[y][x]), nb);
  add_buffer_to_guis(world->pgui, MSG_END, LEN_END);
}
