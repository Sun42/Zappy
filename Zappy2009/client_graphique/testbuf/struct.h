#include "define.h"

#ifndef STRUCT_H_
# define STRUCT_H_

typedef struct	s_card
{
  int		x;/* ordonne : largeur */
  int		y;/* abscisse : hauteur */
  int		direction;/* direction ds laquelle regarde l'ia*/
}		t_card;


typedef	struct		s_cli
{
  int			sock;		/* socket de l'ia */
  t_card		*pos;		/* position du joueur */
  int			lvl;		/* level actuel de l'ia */
  char			*team;		/* nom de l equipe */
  t_res			*invent;	/* inventaire de l'ia */
  struct s_cli		*next;		/*client suivant*/
}			t_cli;

/* arguments supplementaires a rajouter*/
typedef struct	s_world
{
  int		sock_serv;			/* socket du serveur */
  int		port;				/* port du serveur */
  int		speed;				/* temps des actions */
  int		max_client;			/* nb maximum de clients par equipe */
  int		width;				/* largeur de la map */
  int		height;				/* hauteur de la map */
  t_res		**map;				/* map[y][x] */
  t_res		tab_elevation[NB_LEVEL];	/* tableau de ressources par level*/
  t_cli		*client;
  t_team	*team;
}		t_world;

typedef struct	s_pcli
{
  t_cli		*lcli;
  struct s_pcli	*next;
}		t_pcli;

/* liste les chaines de caracteres a emettre */
typedef struct		s_listw
{
  struct s_listw	*next;
  char			*buffer;
  int			sock;
}			t_listw;

#endif /* STRUCT_H_*/
