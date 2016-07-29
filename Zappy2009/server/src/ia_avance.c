/*
** ia_avance.c for ia_avance in /u/all/yurdus_y/cu/rendu/c/Zappy2009/server/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:25:41 2009 yavuz yurdusev
** Last update Fri Apr 24 20:13:28 2009 yavuz yurdusev
*/

#include "ia_command.h"

/*
** Decremente le nb de joueur de la case
** Annule incantation
** Supprime le pcli de l'ancienne case
** Bouge
** Incrementation du nb de joueur sur la nouvelle case
** Annule incantation
** Ajoute le pcli ds la nouvelle case
*/
void	ia_avance(t_world *world, t_cli *ia)
{
  putstr("\033[33mClient numero : ");
  print_nb(ia->numero);
  putstr(" avance\n\033[39m");
  world->map[ia->pos.y][ia->pos.x].nb_joueur -= 1;
  world->map[ia->pos.y][ia->pos.x].elevation = 0;
  remove_pcli(&(world->map[ia->pos.y][ia->pos.x].pcli), ia->pcli);
  if (ia->pos.direction % 2)
    ia->pos.y += (ia->pos.direction == NORD) ?
      (!ia->pos.y) ? world->height - 1 : -1 :
      (ia->pos.y == (world->height - 1)) ? -ia->pos.y : 1;
  else
    ia->pos.x += (ia->pos.direction == OUEST) ?
      (!ia->pos.x) ? world->width - 1 : -1 :
      (ia->pos.x == (world->width - 1)) ? -ia->pos.x : 1;
  if (world->map[ia->pos.y][ia->pos.x].elevation && world->pgui != NULL)
    gui_pie(world, ia->pos.y, ia->pos.x, '0');
  world->map[ia->pos.y][ia->pos.x].nb_joueur += 1;
  world->map[ia->pos.y][ia->pos.x].elevation = 0;
  add_pcli(&(world->map[ia->pos.y][ia->pos.x].pcli), ia->pcli);
  save_cmd(ia, MSG_OK, LEN_OK, 'W');
  if (world->pgui != NULL)
    gui_ppo_serv(world, ia);
}
