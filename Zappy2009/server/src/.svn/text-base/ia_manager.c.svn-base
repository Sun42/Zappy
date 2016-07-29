/*
** ia_manager.c for ia_manager in /u/all/yurdus_y/cu/rendu/c/Zappy2009/server/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:23:48 2009 yavuz yurdusev
** Last update Sat Apr 25 12:05:00 2009 yavuz yurdusev
*/

#include "ia_command.h"
#include "struct_ptr_func.h"

static const t_cmd_func	gl_cmd_func[] =
  {
    {"avance", ia_avance, 7, 1},
    {"droite", ia_droite, 7, 1},
    {"gauche", ia_gauche, 7, 1},
    {"voir", ia_voir, 7, 1},
    {"inventaire", ia_inventaire, 1, 1},
    {"prend", ia_prend, 7, 2},
    {"pose", ia_pose, 7, 2},
    {"expulse", ia_expulse, 7, 1},
    {"broadcast", ia_broadcast, 7, 0},
    {"incantation", ia_incantation, 300, 1},
    {"fork", ia_fork, 42, 1},
    {"connect_nbr", ia_connect_nbr, 0, 1},
    {NULL, NULL, 0, 0}
  };

void	reinit_statut(t_world *world, t_cli *ia)
{
  ia->statut = NOACTION;
  if (access_cmdlen(ia, 'R') > 0)
    select_action(world, ia, access_cmd(ia, 'R'));
  else
    set_timeval(world, &(ia->t_cur_cmd), NOACTION);
}

void	ia_manager(t_world *world, t_cli *ia)
{
  if (ia->statut == EGG)
    {
      ia_birth(world, ia);
      return ;
    }
  gl_cmd_func[ia->func_act].f(world, ia);
  unsave_cmd(ia, access_cmdlen(ia, 'R'), 'R');
  reinit_statut(world, ia);
}

void	select_action(t_world *world, t_cli *ia, char *cmd)
{
  int	i;

  i = 0;
  while (gl_cmd_func[i].name_func != NULL)
    {
      if (cmd_cmp(cmd, gl_cmd_func[i].name_func))
	{
	  if ((i == 8 && get_argument(cmd, 2) == NULL) ||
	      (gl_cmd_func[i].nb_arg &&
	       gl_cmd_func[i].nb_arg != get_nb_arg(cmd)))
	      break;
	  if (cmd_cmp(cmd, "incantation") && !pre_incantation(world, ia))
	    return ;
	  ia->func_act = i;
	  ia->statut = ACTION;
	  set_timeval(world, &(ia->t_cur_cmd), gl_cmd_func[i].time_action);
	  return ;
	}
      i++;
    }
  unsave_cmd(ia, access_cmdlen(ia, 'R'), 'R');
  set_timeval(world, &(ia->t_cur_cmd), NOACTION);
  ia->statut = NOACTION;
  save_cmd(ia, MSG_KO, LEN_KO, 'W');
}
