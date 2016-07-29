/*
** ia_gauche.c for ia_gauche in /u/all/yurdus_y/cu/rendu/c/Zappy2009/server/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:24:15 2009 yavuz yurdusev
** Last update Fri Apr 24 20:15:21 2009 yavuz yurdusev
*/

#include "ia_command.h"

void	ia_gauche(t_world *world __attribute__((unused)),
		  t_cli *ia)
{
  putstr("\033[33mClient numero : ");
  print_nb(ia->numero);
  putstr(" gauche\n\033[39m");
  ia->pos.direction -= (ia->pos.direction == NORD) ? -3 : 1;
  save_cmd(ia, MSG_OK, LEN_OK, 'W');
  if (world->pgui != NULL)
    gui_ppo_serv(world, ia);
}
