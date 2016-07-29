/*
** select.c for select in /u/all/yurdus_y/cu/rendu/c/Zappy2009/server/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:22:09 2009 yavuz yurdusev
** Last update Sun Apr 26 22:48:03 2009 yavuz yurdusev
*/

#include <sys/select.h>
#include <stdio.h>

#include "buffer.h"
#include "serv_connexion.h"
#include "server.h"

static void	socket_action(t_world *world, fd_set *fd_rw, int nb_sock)
{
  if (FD_ISSET(world->sock_serv, &fd_rw[RFD]))
    {
      if (!world->victory_team)
	connect_new_client(world);
    }
  else
    select_read_write(fd_rw, world, nb_sock);
}

static void	timeout_action(t_world *world, t_cli *act_cli)
{
  if (timecmp(&(act_cli->t_alive), &(act_cli->t_cur_cmd)))
    kill_ia(world, act_cli);
  else
    ia_manager(world, act_cli);
}

void			run_server(t_world *world)
{
  int			max;
  int			ret;
  fd_set		fd_rw[2];
  struct timeval	timeout;
  t_cli			*act_cli;

  while (42)
    {
      max = world->sock_serv;
      act_cli = init_select(world, fd_rw, &max, &timeout);
      if ((ret = select(max + 1, &fd_rw[RFD], &fd_rw[WFD], NULL, (act_cli) ?
			&timeout :NULL)) < 0)
	{
	  perror("Erreur : select() --> run_server()");
	  continue ;
	}
      if (ret)
	socket_action(world, fd_rw, ret);
      else
	timeout_action(world, act_cli);
    }
}
