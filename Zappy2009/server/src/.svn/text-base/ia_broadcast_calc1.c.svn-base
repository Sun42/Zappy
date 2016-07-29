/*
** ia_broadcast_calc1.c for ia_broadcast_calc1 in /u/all/yurdus_y/cu/rendu/c/Zappy2009/server/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:25:17 2009 yavuz yurdusev
** Last update Thu Apr 23 20:25:17 2009 yavuz yurdusev
*/

#include "broadcast.h"

int	vertical(t_broadcast *broadcast)
{
  if (broadcast->j1->y > broadcast->j2->y)
    {
      if ((broadcast->j1->y - broadcast->droite.y) == broadcast->j2->y)
	return (BAS);
      return (HAUT);
    }
  if ((broadcast->j2->y - broadcast->droite.y) == broadcast->j1->y)
    return (HAUT);
  return (BAS);
}

int	calc_xdown_yup(t_broadcast *broadcast)
{
  if (broadcast->angle_h < (double)18)
    return (BAS);
  if (broadcast->angle_h < (double)70)
    return (BASDROITE);
  return (DROITE);
}

int	calc_xdown_ydown(t_broadcast *broadcast)
{
  if (broadcast->angle_bg < (double)18)
    return (DROITE);
  if (broadcast->angle_bg < (double)70)
    return (HAUTDROITE);
  return (HAUT);
}

int	calc_xup_yup(t_broadcast *broadcast)
{
  if (broadcast->angle_h < (double)18)
    return (BAS);
  if (broadcast->angle_h < (double)70)
    return (BASGAUCHE);
  return (GAUCHE);
}

int	calc_xup_ydown(t_broadcast *broadcast)
{
  if (broadcast->angle_bg < (double)18)
    return (GAUCHE);
  if (broadcast->angle_bg < (double)70)
    return (HAUTGAUCHE);
  return (HAUT);
}
