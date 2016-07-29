/*
** gui_mct.c for gui_mct in /u/all/yurdus_y/cu/rendu/c/Zappy2009/server/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:29:18 2009 yavuz yurdusev
** Last update Sat Apr 25 15:08:34 2009 yavuz yurdusev
*/

#include "gui_command.h"
#include "gui_send.h"

/*
** contenu de la map
** recu --> "mct\n"
*/
void	gui_mct(t_world *world,
		t_cli *gui,
		char *cmd __attribute__((unused)))
{
  int	y;
  int	x;

  y = 0;
  while (y < world->height)
  {
    x = 0;
    while (x < world->width)
    {
      gui_bct_bis(world, gui, y, x);
      if (world->map[y][x].elevation)
	gui_pic(world, gui, world->map[y][x].pcli->lcli);
      x++;
    }
    y++;
  }
}
