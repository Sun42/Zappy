/*
** gui_tna.c for gui_tna in /u/all/yurdus_y/cu/rendu/c/Zappy2009/server/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:25:47 2009 yavuz yurdusev
** Last update Thu Apr 23 20:25:48 2009 yavuz yurdusev
*/

#include <string.h>

#include "buffer.h"
#include "gui_command.h"

/*
** mis ds le buffer --> "tna N\n"
*/
static void	gui_tna_bis(t_cli *gui, char *team_name)
{
  save_cmd(gui, "tna ", 4, 'W');
  save_cmd(gui, team_name, strlen(team_name), 'W');
  save_cmd(gui, MSG_END, LEN_END, 'W');
}

/*
** nom des equipes
** recu	--> "tna\n"
** envoie --> "tna N\n"
** N nom equipe
*/
void	gui_tna(t_world *world,
		t_cli *gui,
		char *cmd __attribute__((unused)))
{
  t_team	*teams;

  teams = world->team;
  while (teams != NULL)
    {
      gui_tna_bis(gui, teams->name);
      teams = teams->next;
    }
}
