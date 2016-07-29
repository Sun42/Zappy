/*
** ia_prend.c for ia_prend in /u/all/yurdus_y/cu/rendu/c/Zappy2009/server/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:23:09 2009 yavuz yurdusev
** Last update Fri Apr 24 20:18:04 2009 yavuz yurdusev
*/

#include "ia_command.h"

static void	ia_prend_bis(t_world *world, t_cli *ia, int num_obj)
{
  world->map[ia->pos.y][ia->pos.x].objet[num_obj] -= 1;
  ia->invent.objet[num_obj] += 1;
  if (num_obj == FOOD)
    timeadd(world, &(ia->t_alive), FOOD_RATION, &(ia->t_alive));
  save_cmd(ia, MSG_OK, LEN_OK, 'W');
  if (world->pgui != NULL)
    {
      gui_pgt(world, ia->numero, num_obj);
      gui_pin_serv(world, ia);
      gui_bct_serv(world, ia->pos.y, ia->pos.x);
    }
}

void	ia_prend(t_world *world, t_cli *ia)
{
  char	*cmd;
  char	*objet;
  int	num_obj;

  putstr("\033[33mClient numero : ");
  print_nb(ia->numero);
  putstr(" prend\n\033[39m");
  cmd = access_cmd(ia, 'R');
  if (cmd != NULL)
    {
      objet = get_argument(cmd, 2);
      if (objet != NULL)
	{
	  num_obj = get_num_objet(objet);
	  if (num_obj != -1)
	    if (world->map[ia->pos.y][ia->pos.x].objet[num_obj])
	      {
		ia_prend_bis(world, ia, num_obj);
		return ;
	      }
	}
    }
  save_cmd(ia, MSG_KO, LEN_KO, 'W');
}
