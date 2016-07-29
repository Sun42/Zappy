/*
** ia_inventaire.c for ia_inventaire in /u/all/yurdus_y/cu/rendu/c/Zappy2009/server/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:23:57 2009 yavuz yurdusev
** Last update Fri Apr 24 20:17:34 2009 yavuz yurdusev
*/

#include <sys/time.h>

#include "ia_command.h"

void			update_food(t_world *world, t_cli *ia)
{
  struct timeval	time_food;
  long int		time_sec;
  long int		time_usec;

  setdifftime(&(ia->t_alive), &time_food);
  time_sec = 1000000 / world->speed;
  time_usec = time_food.tv_usec / world->speed;
  ia->invent.objet[FOOD] = (time_sec * time_food.tv_sec + time_usec)
    / 126;
}

static void	ia_inventaire_bis(t_cli *ia, char nb[INT_LEN])
{
  int		len_nb;

  save_cmd(ia, ", sibur ", 8, 'W');
  len_nb = atio(ia->invent.objet[SIBUR], nb);
  save_cmd(ia, nb, len_nb, 'W');
  save_cmd(ia, ", mendiane ", 11, 'W');
  len_nb = atio(ia->invent.objet[MENDIANE], nb);
  save_cmd(ia, nb, len_nb, 'W');
  save_cmd(ia, ", phiras ", 9, 'W');
  len_nb = atio(ia->invent.objet[PHIRAS], nb);
  save_cmd(ia, nb, len_nb, 'W');
  save_cmd(ia, ", thystame ", 11, 'W');
  len_nb = atio(ia->invent.objet[THYSTAME], nb);
  save_cmd(ia, nb, len_nb, 'W');
  save_cmd(ia, "}\n", 2, 'W');
}

void	ia_inventaire(t_world *world __attribute__((unused)),
		      t_cli *ia)
{
  char	nb[INT_LEN];
  int	len_nb;

  putstr("\033[33mClient numero : ");
  print_nb(ia->numero);
  putstr(" inventaire\n\033[39m");
  update_food(world, ia);
  save_cmd(ia, "{nourriture ", 12, 'W');
  len_nb = atio(ia->invent.objet[FOOD], nb);
  save_cmd(ia, nb, len_nb, 'W');
  save_cmd(ia, ", linemate ", 11, 'W');
  len_nb = atio(ia->invent.objet[LINEMATE], nb);
  save_cmd(ia, nb, len_nb, 'W');
  save_cmd(ia, ", deraumere ", 12, 'W');
  len_nb = atio(ia->invent.objet[DERAUMERE], nb);
  save_cmd(ia, nb, len_nb, 'W');
  ia_inventaire_bis(ia, nb);
}
