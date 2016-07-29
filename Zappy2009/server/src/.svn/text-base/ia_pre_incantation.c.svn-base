/*
** ia_pre_incantation.c for ia_pre_incantation in /u/all/yurdus_y/cu/rendu/c/Zappy2009/server/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:23:18 2009 yavuz yurdusev
** Last update Sat Apr 25 12:05:47 2009 yavuz yurdusev
*/

#include <string.h>

#include "ia_command.h"

/*
** Check si le niveau des joueurs correspond bien au niveau recquis
** pour debuter l'incantation
*/
static char	check_level_player(t_world *world, t_cli *ia)
{
  t_pcli	*list;

  list = world->map[ia->pos.y][ia->pos.x].pcli;
  while (list != NULL)
    {
      if (list->lcli->lvl != ia->lvl || list->lcli->statut != NOACTION)
	return (0);
      list = list->next;
    }
  return (1);
}

/*
** Verifie que toutes les conditions sont correctes pour debuter
** l'incantation
** Change le statut des joueurs inclus dans l'incantation
*/
static void	set_pre_elevation(t_world *world, t_cli *ia)
{
  t_pcli	*list;

  list = world->map[ia->pos.y][ia->pos.x].pcli;
  while (list != NULL)
    {
      list->lcli->statut = ACTION;
      list->lcli->elevation = 1;
      save_cmd(list->lcli, MSG_PREELEV, strlen(MSG_PREELEV), 'W');
      list = list->next;
    }
}

char	pre_incantation(t_world *world, t_cli *ia)
{
  if (!memcmp(&(world->tab_elevation[(int)ia->lvl - 1].objet[LINEMATE]),
	     &(world->map[ia->pos.y][ia->pos.x].objet[LINEMATE]),
	     sizeof(int) * NB_OBJETS) && check_level_player(world, ia))
    {
      set_pre_elevation(world, ia);
      if (world->pgui != NULL)
	gui_pic_serv(world, ia);
      world->map[ia->pos.y][ia->pos.x].elevation = 1;
      return (1);
    }
  save_cmd(ia, MSG_KO, LEN_KO, 'W');
  unsave_cmd(ia, access_cmdlen(ia, 'R'), 'R');
  return (0);
}
