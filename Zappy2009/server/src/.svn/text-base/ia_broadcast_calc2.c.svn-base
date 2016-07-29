/*
** ia_broadcast_calc2.c for ia_broadcast_calc2 in /u/all/yurdus_y/cu/rendu/c/Zappy2009/server/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:25:08 2009 yavuz yurdusev
** Last update Thu Apr 23 20:25:08 2009 yavuz yurdusev
*/

#include "broadcast.h"

int	calc_j2inf(t_broadcast *broadcast)
{
  if ((broadcast->j2->x + broadcast->droite.x) == broadcast->j1->x)
    {
      if ((broadcast->j2->y + broadcast->droite.y) == broadcast->j1->y)
	return (calc_xdown_yup(broadcast));
      return (calc_xdown_ydown(broadcast));
    }
  if ((broadcast->j2->y + broadcast->droite.y) == broadcast->j1->y)
    return (calc_xup_yup(broadcast));
  return (calc_xup_ydown(broadcast));
}

int	calc_j2xsup(t_broadcast *broadcast)
{
  if ((broadcast->j2->x - broadcast->droite.x) == broadcast->j1->x)
    {
      if ((broadcast->j2->y + broadcast->droite.y) == broadcast->j1->y)
	return (calc_xup_yup(broadcast));
      return (calc_xup_ydown(broadcast));
    }
  if ((broadcast->j2->y + broadcast->droite.y) == broadcast->j1->y)
    return (calc_xdown_yup(broadcast));
  return (calc_xdown_ydown(broadcast));
}

int	calc_j2ysup(t_broadcast *broadcast)
{
  if ((broadcast->j2->x + broadcast->droite.x) == broadcast->j1->x)
    {
      if ((broadcast->j2->y - broadcast->droite.y) == broadcast->j1->y)
	return (calc_xdown_ydown(broadcast));
      return (calc_xdown_yup(broadcast));
    }
  if ((broadcast->j2->y - broadcast->droite.y) == broadcast->j1->y)
    return (calc_xup_ydown(broadcast));
  return (calc_xup_yup(broadcast));
}

int	calc_j2sup(t_broadcast *broadcast)
{
  if ((broadcast->j2->x - broadcast->droite.x) == broadcast->j1->x)
    {
      if ((broadcast->j2->y - broadcast->droite.y) == broadcast->j1->y)
	return (calc_xup_ydown(broadcast));
      return (calc_xup_yup(broadcast));
    }
  if ((broadcast->j2->y - broadcast->droite.y) == broadcast->j1->y)
    return (calc_xdown_ydown(broadcast));
  return (calc_xdown_yup(broadcast));
}

int	horizontal(t_broadcast *broadcast)
{
  if (broadcast->j1->x > broadcast->j2->x)
    {
      if ((broadcast->j1->x - broadcast->droite.x) == broadcast->j2->x)
	return (DROITE);
      return (GAUCHE);
    }
  if ((broadcast->j2->x - broadcast->droite.x) == broadcast->j1->x)
    return (GAUCHE);
  return (DROITE);
}
