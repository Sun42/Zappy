/*
** func_time.c for func_time in /u/all/yurdus_y/cu/rendu/c/Zappy2009/server/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Sun Apr 26 22:25:51 2009 yavuz yurdusev
** Last update Sun Apr 26 22:45:01 2009 yavuz yurdusev
*/

#include <sys/time.h>
#include <stdio.h>

#include "server.h"

static void	timesub(struct timeval *timea,
			int add_usec,
			struct timeval *timeres)
{
  int		modulo;

  modulo = add_usec % 1000000;
  if (modulo == 0)
    {
      timeres->tv_sec = timea->tv_sec + (add_usec / 1000000);
      timeres->tv_usec = timea->tv_usec;
    }
  else
    {
      timeres->tv_sec = timea->tv_sec + (add_usec / 1000000) - 1;
      timeres->tv_usec = timea->tv_usec + 1000000 + modulo;
    }
  if (timeres->tv_sec < 0)
    timeres->tv_sec = 0;
}

void		timeadd(t_world *world,
			struct timeval *timea,
			int time_action,
			struct timeval *timeres)
{
  int		add_usec;
  long int	tmp;

  add_usec = time_action * world->speed;
  if (timea->tv_usec + add_usec < 0)
    timesub(timea, add_usec, timeres);
  else
    {
      tmp = timea->tv_usec + add_usec;
      if (tmp > 999999)
	{
	  timeres->tv_sec = timea->tv_sec + (tmp / 1000000);
	  timeres->tv_usec = tmp % 1000000;
	}
      else
	{
	  timeres->tv_sec = timea->tv_sec;
	  timeres->tv_usec = timea->tv_usec + add_usec;
	}
    }
}

void			set_timeval(t_world *world,
				    struct timeval *timev,
				    int timeAction)
{
  struct timeval	timenow;

  if (timeAction < 0)
    {
      timev->tv_sec = 2147483647;
      timev->tv_usec = 2147483647;
    }
  else
    {
      if (gettimeofday(&timenow, NULL) < 0)
	perror("Erreur : gettimeofday() --> set_timeval()");
      timeadd(world, &timenow, timeAction, timev);
    }
}

int	timecmp(struct timeval *t0, struct timeval *t1)
{
  if (t0->tv_sec != t1->tv_sec)
    return (t0->tv_sec >= t1->tv_sec ? 0 : 1);
  return (t0->tv_usec >= t1->tv_usec ? 0 : 1);
}
