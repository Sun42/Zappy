/*
** func_setdifftime.c for setdifftime in /u/all/yurdus_y/cu/rendu/c/Zappy2009/server/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Sun Apr 26 22:45:13 2009 yavuz yurdusev
** Last update Sun Apr 26 22:53:59 2009 yavuz yurdusev
*/

#include <stdio.h>
#include <sys/time.h>

static int	setdifftime_bis(struct timeval *timeres, int tmp)
{
  int		ret;

  ret = 0;
  if (tmp < 0)
    {
      timeres->tv_usec = tmp + 1000000;
      ret = 1;
    }
  else
    {
      if (tmp > 999999)
	{
	  ret = tmp - 1000000;
	  tmp = tmp % 1000000;
	}
      timeres->tv_usec = tmp;
    }
  return (ret);
}

void			setdifftime(struct timeval *timea,
				    struct timeval *timeres)
{
  struct timeval	timenow;
  long int		tmp;
  int			ret;

  if (gettimeofday(&timenow, NULL) < 0)
  {
    perror("Erreur : gettimeofday() --> setdifftimel()");
    timeres->tv_usec = 0;
    timeres->tv_sec = 0;
    return ;
  }
  tmp = timea->tv_usec - timenow.tv_usec;
  ret = setdifftime_bis(timeres, tmp);
  tmp = timea->tv_sec - timenow.tv_sec - ret;
  if (tmp < 0)
    {
      timeres->tv_usec = 0;
      timeres->tv_sec = 0;
    }
  else
    timeres->tv_sec = tmp;
}
