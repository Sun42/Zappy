/*
** gui_seg.c for gui_seg in /u/all/yurdus_y/cu/rendu/c/Zappy2009/server/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:26:44 2009 yavuz yurdusev
** Last update Thu Apr 23 20:26:45 2009 yavuz yurdusev
*/

#include <string.h>

#include "gui_command.h"

/*
** Fin du jeu. L’équipe donnée remporte la partie.
** envoie --> "seg N\n"
*/
void	gui_seg(t_world *world, char *team_win)
{
  add_buffer_to_guis(world->pgui, "seg ", 4);
  add_buffer_to_guis(world->pgui, team_win, strlen(team_win));
  add_buffer_to_guis(world->pgui, MSG_END, LEN_END);
}
