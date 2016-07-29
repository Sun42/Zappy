/*
** struct.h for struct in /u/all/yurdus_y/cu/rendu/c/Zappy2009/server/header
**
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
**
** Started on  Thu Apr 23 20:21:17 2009 yavuz yurdusev
** Last update Sat Apr 25 10:11:41 2009 yavuz yurdusev
*/

#include <sys/time.h>

#include "define.h"

#ifndef STRUCT_H_
# define STRUCT_H_

typedef	struct	s_res
{
  int		objet[NB_OBJETS];
  int		nb_joueur;		/* nb de joueurs present sur la case */
  struct s_pcli	*pcli;			/* liste chaine de ptr sur client contenant les clients a cette case */
  char		elevation;		/* permet de specifier une case en cour d'elevation */
}		t_res;

typedef struct	s_buff
{
  char		buf[BUF_SIZE];
  int		begin;
  int		end;
}		t_buf;

typedef struct	s_cmd
{
  char		*cmd;
  int		indice_buf;
  int		len;
  char		is_complet;
  int		sended;
  struct s_cmd	*next;
}		t_cmd;

typedef struct	s_team
{
  int		nb_client;		/* nb de client pouvant encore se connecter */
  int		nb_lvl_max;
  char		*name;			/* nom de l equipe */
  struct s_team	*next;			/* team suivante */
}		t_team;

typedef struct	s_card
{
  int		x;			/* ordonne : largeur */
  int		y;			/* abscisse : hauteur */
  char		direction;		/* direction ds laquelle regarde l'ia */
}		t_card;

typedef	struct		s_cli
{
  int			sock;		/* socket de l'ia */
  int			numero;		/* numero de joueur */
  t_buf			bufr;
  t_cmd			*lcmdr;
  t_buf			bufw;
  t_cmd			*lcmdw;
  t_card		pos;		/* position du joueur */
  struct s_pcli		*pcli;		/* pointeur a place ds la liste des clients sur une case*/
  int			statut;		/* etat d'un client */
  char			lvl;		/* level actuel de l'ia */
  int			func_act;	/* numero de la fct a executer */
  t_team		*team;		/* ptr sur sa team */
  t_res			invent;		/* inventaire de l'ia */
  char			elevation;	/* le joueur est en cours d'elevation */
  struct timeval	t_cur_cmd;	/*temps restant fin comd courante*/
  struct timeval	t_alive;	/*temps restant avant de die*/
  struct s_cli		*next;		/*client suivant*/
}			t_cli;

typedef struct	s_world
{
  int		sock_serv;		/* socket du serveur */
  int		port;			/* port du serveur */
  int		speed;			/* temps des actions */
  int		max_client;		/* nb maximum de clients par equipe */
  int		width;			/* largeur de la map */
  int		height;			/* hauteur de la map */
  t_res		**map;			/* map[y][x] */
  t_res		tab_elevation[NB_LEVEL]; /* tableau de ressources par niveau */
  t_cli		*client;		/* ptr sur la liste des clients */
  struct s_pcli	*pgui;			/* ptr sur la liste des gui */
  t_team	*team;			/* ptr sur la liste des teams */
  t_team	*victory_team;			/* ptr sur l'equipe victorieuse */
}		t_world;

typedef struct	s_pcli
{
  t_cli		*lcli;			/* pointeur sur la structure du client associe */
  struct s_pcli	*next;
}		t_pcli;

typedef struct	s_objet
{
  char		*name;
  int		value;
  int		len;
}		t_objet;


typedef	struct	s_broadcast
{
  t_card	*j1;
  t_card	*j2;
  t_card	droite;
  double	angle_h;
  double	angle_bg;
  int		reception;
}		t_broadcast;

#endif /* STRUCT_H_*/
