/*
** ia_pose.c for ia_pose in /u/all/yurdus_y/cu/rendu/c/Zappy2009/server/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:23:36 2009 yavuz yurdusev
** Last update Fri Apr 24 20:17:47 2009 yavuz yurdusev
*/

#include "ia_command.h"

static void	ia_pose_bis(t_world *world, t_cli *ia, int num_obj)
{
  world->map[ia->pos.y][ia->pos.x].objet[num_obj] += 1;
  ia->invent.objet[num_obj] -= 1;
  if (num_obj == FOOD)
    timeadd(world, &(ia->t_alive), - FOOD_RATION, &(ia->t_alive));
  save_cmd(ia, MSG_OK, LEN_OK, 'W');
  if (world->pgui != NULL)
    {
      gui_pdr(world, ia->numero, num_obj);
      gui_pin_serv(world, ia);
      gui_bct_serv(world, ia->pos.y, ia->pos.x);
    }
}

void	ia_pose(t_world *world, t_cli *ia)
{
  char	*cmd;
  char	*objet;
  int	num_obj;

  putstr("\033[33mClient numero : ");
  print_nb(ia->numero);
  putstr(" pose\n\033[39m");
  cmd = access_cmd(ia, 'R');
  if (cmd != NULL)
    {
      objet = get_argument(cmd, 2);
      if (objet != NULL)
	{
	  num_obj = get_num_objet(objet);
	  if (num_obj != -1)
	    if (ia->invent.objet[num_obj])
	      {
		ia_pose_bis(world, ia, num_obj);
		return ;
	      }
	}
    }
  save_cmd(ia, MSG_KO, LEN_KO, 'W');
}
