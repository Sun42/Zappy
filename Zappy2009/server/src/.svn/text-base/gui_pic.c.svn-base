/*
** gui_pic.c for gui_pic in /u/all/yurdus_y/cu/rendu/c/Zappy2009/server/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:28:23 2009 yavuz yurdusev
** Last update Sat Apr 25 21:24:12 2009 yavuz yurdusev
*/

#include "buffer.h"
#include "gui_command.h"

/*
** Ajout ds le buffer
** " #n #n\n"
*/
static void	gui_pic_bis(t_world *world, t_cli *gui, int x, int y)
{
  t_pcli	*list_ia;
  char		nb[INT_LEN];
  int		len_nb;

  list_ia = world->map[y][x].pcli;
  while (list_ia != NULL)
    {
      save_cmd(gui, MSG_SEP, LEN_SEP, 'W');
      len_nb = atio(list_ia->lcli->numero, nb);
      save_cmd(gui, nb, len_nb, 'W');
      list_ia = list_ia->next;
    }
}

/*
** Premier joueur lance l’incantation pour tous les suivants sur la case.
** envoie --> "pic X Y L #n #n ...\n"
** X --> Largeur ou position horizontale
** Y --> Hauteur ou position verticale
** L --> Niveau du joueur ou de l’incantation
** #n --> Numero de joueur sur le serveur
** ajout ds le buffer
** "pic X Y L...\n"
*/
void	gui_pic(t_world *world, t_cli *gui, t_cli *ia)
{
  char	nb[INT_LEN];
  int	len_nb;

  save_cmd(gui, "pic ", 4, 'W');
  len_nb = atio(ia->pos.x, nb);
  save_cmd(gui, nb, len_nb, 'W');
  save_cmd(gui, MSG_SEP, LEN_SEP, 'W');
  len_nb = atio(ia->pos.y, nb);
  save_cmd(gui, nb, len_nb, 'W');
  save_cmd(gui, MSG_SEP, LEN_SEP, 'W');
  len_nb = atio(ia->lvl + 1, nb);
  save_cmd(gui, nb, len_nb, 'W');
  gui_pic_bis(world, gui, ia->pos.x, ia->pos.y);
  save_cmd(gui, MSG_END, LEN_END, 'W');
}

static void	gui_pic_serv_bis(t_world *world, t_cli *ia, char nb[INT_LEN])
{
  t_pcli	*list_ia;
  int		len_nb;

  list_ia = world->map[ia->pos.y][ia->pos.x].pcli;
  while (list_ia != NULL)
    {
      add_buffer_to_guis(world->pgui, MSG_SEP, LEN_SEP);
      len_nb = atio(list_ia->lcli->numero, nb);
      add_buffer_to_guis(world->pgui, nb, len_nb);
      list_ia = list_ia->next;
    }
}

void	gui_pic_serv(t_world *world, t_cli *ia)
{
  char	nb[INT_LEN];
  int	len_nb;

  add_buffer_to_guis(world->pgui, "pic ", 4);
  len_nb = atio(ia->pos.x, nb);
  add_buffer_to_guis(world->pgui, nb, len_nb);
  add_buffer_to_guis(world->pgui, MSG_SEP, LEN_SEP);
  len_nb = atio(ia->pos.y, nb);
  add_buffer_to_guis(world->pgui, nb, len_nb);
  add_buffer_to_guis(world->pgui, MSG_SEP, LEN_SEP);
  len_nb = atio(ia->lvl + 1, nb);
  add_buffer_to_guis(world->pgui, nb, len_nb);
  gui_pic_serv_bis(world, ia, nb);
  add_buffer_to_guis(world->pgui, MSG_END, LEN_END);
}
