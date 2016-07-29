/*
** func_gen_obj.c for func_gen_obj in /u/all/yurdus_y/cu/rendu/c/Zappy2009/server/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:32:47 2009 yavuz yurdusev
** Last update Fri Apr 24 22:58:41 2009 yavuz yurdusev
*/

#include <stdlib.h>

#include "gui_send.h"

/*
** Ajoute une ressource sur une case aleatoire de la map
*/
static void	add_rand_ressource(t_world *world, int type)
{
  int		x;
  int		y;
  int		i;

  i = 0;
  x = rand() % world->width;
  y = rand() % world->height;
  while (i < 5 && world->map[y][x].elevation)
    {
      x = rand() % world->width;
      y = rand() % world->height;
      i++;
    }
  if (world->map[y][x].elevation && world->pgui != NULL)
    gui_pie(world, y, x, '0');
  world->map[y][x].elevation = 0;
  world->map[y][x].objet[type]++;
  if (world->pgui != NULL)
    gui_bct_serv(world, y, x);
}

/*
** Deplace les ressources a la fin d'une incantation reussie
*/
void	move_ressource(t_world *world, int y, int x)
{
  int	type;
  t_res	*caz;

  caz = &(world->map[y][x]);
  type = LINEMATE;
  while (type <= THYSTAME)
    {
      while (caz->objet[type])
	{
	  add_rand_ressource(world, type);
	  caz->objet[type]--;
	}
      type++;
    }
  if (world->pgui != NULL)
    gui_bct_serv(world, y, x);
}

static void	gen_nb_res(t_world *world, int type, int nb_ressource)
{
  int		i;

  i = 0;
  while (i < nb_ressource)
    {
      add_rand_ressource(world, type);
      i++;
    }
}

/*
** Genere les ressources lors de la connexion d'un joueur
*/
void	gen_ressource(t_world *world)
{
  float	mult_world;

  mult_world = (world->height * world->width) / COEF_DIV;
  if (mult_world < 1)
    mult_world = 1;
  gen_nb_res(world, FOOD, COEF_FOOD * mult_world);
  gen_nb_res(world, LINEMATE, COEF_LINEMATE * mult_world);
  gen_nb_res(world, DERAUMERE, COEF_DERAUMERE * mult_world);
  gen_nb_res(world, SIBUR, COEF_SIBUR * mult_world);
  gen_nb_res(world, MENDIANE, COEF_MENDIANE * mult_world);
  gen_nb_res(world, PHIRAS, COEF_PHIRAS * mult_world);
  gen_nb_res(world, THYSTAME, COEF_THYSTAME * mult_world);
}
