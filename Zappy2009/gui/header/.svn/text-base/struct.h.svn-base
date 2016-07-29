/*
** struct.h for struct in /u/all/yurdus_y/cu/rendu/c/Zappy2009/gui/header
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:30:11 2009 yavuz yurdusev
** Last update Thu Apr 23 20:30:12 2009 yavuz yurdusev
*/

# include "define.h"
# include "buffer.h"

#ifndef STRUCT_H_
# define STRUCT_H_

typedef	struct s_point
{
  int		x;
  int		y;
}		t_point;

typedef struct	s_card
{
  SDL_Rect	pos_player;	/* les coordonnees du joueur pos_player.x & y */
  t_point	old_pos;	/* les coordonnees du joueur pos_player.x & y */
  SDL_Rect	mov_player;	/* les coordonnees du joueur pos_player.x & y */
  int		direction;	/* direction ds laquelle regarde l'ia*/
}		t_card;

typedef struct	s_print_player
{
  SDL_Surface	*player;
  int		i_clip;		/* index sur le tableau de CLIP */
}		t_print_player;

typedef struct		s_res
{
  int			objet[NB_OBJETS];
  int			id_wood;
  int			nb_ghost;
  int			*ghost_num;
  int			*oeuf_num;
}			t_res;

typedef	struct		s_cli
{
  int			num;		/* numero de l'ia */
  int			on_move;	/* Joueur en mouvement ou pas */
  t_card		pos;		/* position du joueur */
  int			lvl;		/* level actuel de l'ia */
  char			*team;		/* nom de l equipe */
  t_res			invent;		/* inventaire de l'ia */
  t_print_player	mob;		/* l'image du joueur selon son level */
  struct s_cli		*next;		/*client suivant*/
}			t_cli;

/* arguments supplementaires a rajouter*/
typedef struct		s_world
{
  int			sock_serv;	/* socket du serveur */
  int			speed;		/* temps des actions */
  int			width;		/* largeur de la map en case*/
  int			height;		/* hauteur de la map en case*/
  int			mini_width;	/* largeur de la minimap en case*/
  int			mini_height;	/* hauteur de la minimap en case*/
  int			x_begin;	/* Position de la camera  X & Y */
  int			y_begin;
  int			loading;	/* bool de depart*/
  int			time_expulse;
  SDL_Surface		*portal;
  SDL_Surface		**player;
  SDL_Surface		**wood;
  SDL_Rect		clip[NB_CLIP];	/* Initialisation des animations pour les joueurs */
  SDL_Rect		pos_expulse;
  SDL_Surface		**ressources;
  t_res			**map;		/* map[y][x] */
  t_cli			*client;
  t_print_player	ghost;
}			t_world;

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

typedef struct	s_bag
{
  SDL_Surface	*bag;
  SDL_Surface	*info_invent;
  SDL_Surface	*play;
  TTF_Font	*font;
  char		translate[20];
  SDL_Rect	pos_bag;
  SDL_Color	textcolor;
  SDL_Rect	pos_team_name;
  SDL_Rect	pos_level;
  SDL_Rect	pos_invent;
  SDL_Rect	pos_play;
  int		have_invent;
  t_cli		*heros;
}		t_bag;

typedef struct	s_broadcast
{
  SDL_Surface	*brdcast_img;
  SDL_Surface	*brdcast_txt;
  char		*broadcast;
  int		brdcast_time;
}		t_broadcast;

typedef	struct	s_on_screen
{
  SDL_Surface	*window;
  SDL_Surface	*map;
  SDL_Rect	*pos;
  SDLKey	cmd;
  TCPsocket	sock_server;
  int		velocity;
  int		x;
  int		y;
  int		quit;
  int		show_minimap;
  t_point	coor_max;
  t_broadcast	brdcast;
  t_world	*world;
  t_msg		my_msg;
  t_bag		*info_bag;
}		t_on_screen;

#endif /* STRUCT_H_*/
