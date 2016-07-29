/*
** select_read_write.c for select_read_write in /u/all/yurdus_y/cu/rendu/c/Zappy2009/server/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:21:44 2009 yavuz yurdusev
** Last update Sat Apr 25 16:24:17 2009 yavuz yurdusev
*/

#include "buffer.h"
#include "ia_command.h"
#include "serv_connexion.h"

/*
** Determine le type de client : GUI ou NOTEAM ou NOACTION
*/
static void	select_type_client(t_world *world, t_cli *cli, char *cmd)
{
  if (cli->statut == NOTEAM)
    {
      if (cmd_cmp(cmd, KEY_GUI))
	set_gui(world, cli);
      else
	set_ia_team(world, cli, cmd);
      unsave_cmd(cli, access_cmdlen(cli, 'R'), 'R');
    }
  else if (cli->statut == NOACTION)
    select_action(world, cli, cmd);
  else if (cli->statut == GUI)
    {
      gui_manager(world, cli, cmd);
      unsave_cmd(cli, access_cmdlen(cli, 'R'), 'R');
    }
}

void	select_read_write(fd_set fd_rw[], t_world *world, int nb_sock)
{
  t_cli	*cli;

  cli = world->client;
  while (cli && nb_sock > 0)
    {
      if (cli->statut != EGG && cli->statut != GHOST && cli->statut != DEAD)
	{
	  if (FD_ISSET(cli->sock, &fd_rw[WFD]))
	    {
	      nb_sock--;
	      write_client(world, cli);
	    }
	  if (cli->statut != WILL_DIE && cli->statut != DEAD &&
	      FD_ISSET(cli->sock, &fd_rw[RFD]))
	    {
	      nb_sock--;
	      read_client(world, cli);
	      if (cli->statut != DEAD && access_cmdlen(cli, 'R') > 0)
		select_type_client(world, cli, access_cmd(cli, 'R'));
	    }
	}
      cli = cli->next;
    }
}
