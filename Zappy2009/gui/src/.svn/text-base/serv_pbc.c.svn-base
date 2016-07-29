/*
** serv_pbc.c for serv_pbc in /u/all/yurdus_y/cu/rendu/c/Zappy2009/gui/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:41:14 2009 yavuz yurdusev
** Last update Thu Apr 23 20:41:14 2009 yavuz yurdusev
*/

#include "command.h"
#include "broadcast.h"
#include "func_xmemory.h"

static int	team_name(t_on_screen *screen, char *str)
{
  int		i;
  int		limit;

  limit = n_strlen(str, 1);
  screen->brdcast.broadcast = xmalloc(sizeof(char) * limit + 2);
  if (screen->brdcast.broadcast == NULL)
    return (0);
  i = 0;
  while (i < limit)
    {
      screen->brdcast.broadcast[i] = str[i];
      i++;
    }
  screen->brdcast.broadcast[i] = '\0';
  return (limit);
}

static void	message(t_on_screen *screen, char *str)
{
  int		i;
  int		limit;
  int		end;
  int		imax;

  limit = n_strlen(str, 0);
  end = strlen(screen->brdcast.broadcast);
  imax = limit + end;
  screen->brdcast.broadcast =
    xrealloc(screen->brdcast.broadcast, imax + 1);
  if (screen->brdcast.broadcast == NULL)
    return ;
  i = 0;
  while (i < limit)
    {
      screen->brdcast.broadcast[end] = str[i];
      i++;
      end++;
    }
  screen->brdcast.broadcast[end] = '\0';
}

void	serv_pbc(t_on_screen *screen, char *msg)
{
  int	brdcast_pos;

  if (screen->brdcast.broadcast != NULL)
    free(screen->brdcast.broadcast);
  brdcast_pos = team_name(screen, msg + 4);
  if (brdcast_pos)
    {
      if (n_strlen(msg, 0) > (4 + brdcast_pos))
	message(screen, msg + (unsigned int)(brdcast_pos + 4));
    }
  if (screen->brdcast.broadcast != NULL)
    {
      screen->brdcast.brdcast_time = 0;
      display_broadcast(screen);
      screen->world->loading = 0;
    }
}
