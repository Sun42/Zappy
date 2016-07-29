/*
** define.h for define in /u/all/yurdus_y/cu/rendu/c/Zappy2009/server/header
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:19:16 2009 yavuz yurdusev
** Last update Sun Apr 26 17:36:55 2009 yavuz yurdusev
*/

#ifndef DEFINE_H_
# define DEFINE_H_

# define ABS(x) (x < 0 ? (-x) : (x))
# define MIN(a, b) ((a) > (b) ? (b) : (a))
# define MAX(a, b) ((a) > (b) ? (a) : (b))
# define END_STR(c) ((c == '\0' || c == '\n' || c == '\r') ? 1 : 0)

# define MY_PI		3.14159265358979323846

# define ICI		0
# define HAUT		1
# define HAUTGAUCHE	2
# define GAUCHE		3
# define BASGAUCHE	4
# define BAS		5
# define BASDROITE	6
# define DROITE		7
# define HAUTDROITE	8

# define MAX_CLIENTS		100
# define MAX_INIT_CLIENT	1000
# define NB_LEVEL		7
# define BUF_RECV_SEND		256
# define BUF_SIZE		4096
# define INT_LEN		13

/* buffer */
# define ENDCMD		'\n'
# define FREED		'\0'

/* Offset dans le tableau des fd_set */
# define RFD		0
# define WFD		1

/* IA Statut */
# define GUI		42	/* Client Graphique */
# define ACTION		0	/* IA realise une action */
# define NOACTION	-1	/* IA sans action definie */
# define NOTEAM		-2	/* client sans statut */
# define EGG		-3	/* IA qui attend d'eclore */
# define GHOST		-4	/* IA non controle tps de vie decrementer */
# define WILL_DIE	-5	/* CLIENT a qui il reste un message a envoye mais ne fait aucune autre action*/
# define DEAD		-6	/* client inutilise */

/* IA Direction */
# define NORD		1
# define EST		2
# define SUD		3
# define OUEST		4

# define CASE_PER_LEVEL	2

/* Objets*/
# define FOOD		0
# define COEF_FOOD	20
# define LINEMATE	1
# define COEF_LINEMATE	7
# define DERAUMERE	2
# define COEF_DERAUMERE	4
# define SIBUR		3
# define COEF_SIBUR	5
# define MENDIANE	4
# define COEF_MENDIANE	2
# define PHIRAS		5
# define COEF_PHIRAS	3
# define THYSTAME	6
# define COEF_THYSTAME	1
# define PLAYER		8
# define NB_OBJETS	7
# define DEFAULT_FOOD	10
# define COEF_DIV	100.0

/* params Victoire */
# define LVL_MAX	8
# define NB_LVL_MAX	6

/* Messages types */
# define MSG_END	"\n"
# define LEN_END	1
# define MSG_OK		"ok\n"
# define LEN_OK		3
# define MSG_KO		"ko\n"
# define LEN_KO		3
# define MSG_PREELEV	"elevation en cours\n"
# define MSG_ELEV	"niveau actuel : "
# define MSG_SEP	" "
# define LEN_SEP	1
# define MSG_INTER_VOIR	","
# define LEN_INTER_VOIR	1
# define MSG_DEB_VOIR	"{"
# define LEN_DEB_VOIR	1
# define MSG_FIN_VOIR	"}\n"
# define LEN_FIN_VOIR	2
# define MSG_EXPULSE	"deplacement "
# define LEN_EXPULSE	12
# define MSG_MORT	"mort\n"
# define LEN_MORT	5

# define GUI_SBP	"sbp\n"
# define GUI_SBPL	4
# define GUI_SUC	"suc\n"
# define GUI_SUCL	4

# define KEY_GUI	"GRAPHIC"
# define MSG_WECLOME	"BIENVENUE\n"

# define DEBUT_RESSOURCE	'{'
# define FIN_RESSOURCE		'}'

# define LIFETIME	1260
# define TIME_BIRTH	600
# define FOOD_RATION	126

#endif /* DEFINE_H_*/
