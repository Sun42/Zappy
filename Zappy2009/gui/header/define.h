/*
** define.h for define in /u/all/yurdus_y/cu/rendu/c/Zappy2009/gui/header
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:25:21 2009 yavuz yurdusev
** Last update Thu Apr 23 20:25:22 2009 yavuz yurdusev
*/


#ifndef DEFINE_H_
# define DEFINE_H_

# define H_WIN		800
# define W_WIN		1000

# define USAGE		"gui: Usage: -Host -Port\n"

# define SQUARE		50

# define MAX_CLIENTS	100
# define NB_LEVEL	9

# define PLAYER		7

# define NB_PIXEL_MOVE	5

# define MOVE_UP	1
# define MOVE_RIGHT	2
# define MOVE_DOWN	3
# define MOVE_LEFT	4

# define NB_MAX_CASE_X	20
# define NB_MAX_CASE_Y	16

# define SHEET_WIDTH	70
# define SHEET_HEIGHT	130

# define NORD		1
# define EST		2
# define SUD		3
# define OUEST		4

# define NB_CLIP	12

# define FOOD		0
# define LINEMATE	1
# define DERAUMERE	2
# define SIBUR		3
# define MENDIANE	4
# define PHIRAS		5
# define THYSTAME	6
# define OEUF		7
# define INCANTATION	8
# define NB_OBJETS	9

# define NB_WOOD	16

# define BRDCAST_MAX	90

# define BUF_SIZE	4096
# define ENDCMD		'\n'
# define FREED		'\0'

# define CENTER_X(x) ((W_WIN / 2) - ((x * SQUARE) / 2))
# define CENTER_Y(y) ((H_WIN / 2) - ((y * SQUARE) / 2))
# define IS_NONZERO(x) ((x) > (-1) ? (1) : (0))
# define VALID_CAZE(x, max) (((x) < (max)) ?  (IS_NONZERO(x)) : (0))
# define MIN(a, b) ((a) > (b) ? (b) : (a))
# define MAX(a, b) ((a) > (b) ? (a) : (b))
# define END_STR(c) ((c == '\0' || c == '\n' || c == '\r') ? 1 : 0)

#endif /*! DEFINE_H_ !*/
