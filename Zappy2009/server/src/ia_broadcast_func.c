/*
** ia_broadcast_func.c for ia_broadcast_func in /u/all/yurdus_y/cu/rendu/c/Zappy2009/server/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:24:58 2009 yavuz yurdusev
** Last update Thu Apr 23 20:24:59 2009 yavuz yurdusev
*/

#include <math.h>

#include "broadcast.h"

void	add_direction(t_broadcast *broadcast)
{
  int	fact;

  if ((broadcast->j2->direction == NORD) || (same_case(broadcast)))
    return ;
  if (broadcast->j2->direction == EST)
    fact = 3;
  if (broadcast->j2->direction == SUD)
    fact = 2;
  if (broadcast->j2->direction == OUEST)
    fact = 1;
  broadcast->reception = broadcast->reception - (2 * fact);
  if (broadcast->reception <= 0)
    broadcast->reception += 8;
}

void		get_angle(t_broadcast *broadcast)
{
  double	d;
  double	x;
  double	y;
  double	radian_bg;

  x = (double)broadcast->droite.x;
  y = (double)broadcast->droite.y;
  d = sqrt(pow(x, 2) + pow(y, 2));
  radian_bg = acos(x / d);
  broadcast->angle_bg = (double)(radian_bg * 360) / (double)(MY_PI * 2);
  broadcast->angle_h = (double)180 - (broadcast->angle_bg + (double)90);
}

int	calc_fastpath(int max, int p1, int p2)
{
  int	len1;
  int	len2;

  if (p2 > p1)
    len1 = p2 - p1;
  else
    len1 = p1 - p2;
  len2 = (len1 - (max + 1));
  return (MIN(ABS(len1), ABS(len2)));
}

int	calc_case_reception(t_broadcast *broadcast)
{
  broadcast->reception = -1;
  if (same_case(broadcast))
    return (ICI);
  if (broadcast->j1->x == broadcast->j2->x)
    return (vertical(broadcast));
  if (broadcast->j1->y == broadcast->j2->y)
    return (horizontal(broadcast));
  if (broadcast->j1->y < broadcast->j2->y)
    {
      if (broadcast->j1->x < broadcast->j2->x)
	return (calc_j2sup(broadcast));
      return (calc_j2ysup(broadcast));
    }
  if (broadcast->j1->x > broadcast->j2->x)
    return (calc_j2inf(broadcast));
  return (calc_j2xsup(broadcast));
}

int	same_case(t_broadcast *broadcast)
{
  if (broadcast->j1->x == broadcast->j2->x)
    if (broadcast->j1->y == broadcast->j2->y)
      return (1);
  return (0);
}
