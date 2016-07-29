##
## Makefile for Makefile in /u/all/yurdus_y/cu/rendu/c/Zappy2009/server
## 
## Made by yavuz yurdusev
## Login   <yurdus_y@epitech.net>
## 
## Started on  Thu Apr 23 20:20:33 2009 yavuz yurdusev
## Last update Sun Apr 26 22:47:05 2009 yavuz yurdusev
##

CC		=	gcc

NAME		=	serveur

DIR_INCLUDE	=	./header/

DIR_SRC		=	./src/

SRC		=	$(DIR_SRC)buf_add.c		\
			$(DIR_SRC)buf_add_onbuf.c	\
			$(DIR_SRC)buf_add_overflow.c	\
			$(DIR_SRC)buf_init.c		\
			$(DIR_SRC)buf_utils2.c		\
			$(DIR_SRC)buf_utils.c		\
			$(DIR_SRC)cmd_access.c		\
			$(DIR_SRC)cmd_list2.c		\
			$(DIR_SRC)cmd_list.c		\
			$(DIR_SRC)cmd_save.c		\
			$(DIR_SRC)cmd_save2.c		\
			$(DIR_SRC)cmd_unsave.c		\
			$(DIR_SRC)cmd_utils.c		\
			$(DIR_SRC)func_action.c		\
			$(DIR_SRC)func_client.c		\
			$(DIR_SRC)func_connexion.c	\
			$(DIR_SRC)func_create_cli.c	\
			$(DIR_SRC)func_gen_obj.c	\
			$(DIR_SRC)func_gui.c		\
			$(DIR_SRC)func_ia.c		\
			$(DIR_SRC)func_objet.c		\
			$(DIR_SRC)func_pcli.c		\
			$(DIR_SRC)func_printstr.c	\
			$(DIR_SRC)func_setdifftime.c	\
			$(DIR_SRC)func_str.c		\
			$(DIR_SRC)func_team.c		\
			$(DIR_SRC)func_time.c		\
			$(DIR_SRC)func_world.c		\
			$(DIR_SRC)func_xalloc.c		\
			$(DIR_SRC)gui_bct.c		\
			$(DIR_SRC)gui_ebo.c		\
			$(DIR_SRC)gui_edi.c		\
			$(DIR_SRC)gui_eht.c		\
			$(DIR_SRC)gui_enw.c		\
			$(DIR_SRC)gui_manager.c		\
			$(DIR_SRC)gui_mct.c		\
			$(DIR_SRC)gui_msz.c		\
			$(DIR_SRC)gui_pbc.c		\
			$(DIR_SRC)gui_pdi.c		\
			$(DIR_SRC)gui_pdr.c		\
			$(DIR_SRC)gui_pex.c		\
			$(DIR_SRC)gui_pfk.c		\
			$(DIR_SRC)gui_pgt.c		\
			$(DIR_SRC)gui_pic.c		\
			$(DIR_SRC)gui_pie.c		\
			$(DIR_SRC)gui_pin.c		\
			$(DIR_SRC)gui_plv.c		\
			$(DIR_SRC)gui_pnw.c		\
			$(DIR_SRC)gui_ppo.c		\
			$(DIR_SRC)gui_seg.c		\
			$(DIR_SRC)gui_sgt.c		\
			$(DIR_SRC)gui_tna.c		\
			$(DIR_SRC)ia_avance.c		\
			$(DIR_SRC)ia_broadcast.c	\
			$(DIR_SRC)ia_broadcast_func.c	\
			$(DIR_SRC)ia_broadcast_calc1.c	\
			$(DIR_SRC)ia_broadcast_calc2.c	\
			$(DIR_SRC)ia_connect_nbr.c	\
			$(DIR_SRC)ia_droite.c		\
			$(DIR_SRC)ia_expulse.c		\
			$(DIR_SRC)ia_fork.c		\
			$(DIR_SRC)ia_gauche.c		\
			$(DIR_SRC)ia_incantation.c	\
			$(DIR_SRC)ia_inventaire.c	\
			$(DIR_SRC)ia_manager.c		\
			$(DIR_SRC)ia_pose.c		\
			$(DIR_SRC)ia_pre_incantation.c	\
			$(DIR_SRC)ia_prend.c		\
			$(DIR_SRC)ia_voir_content.c	\
			$(DIR_SRC)ia_voir.c		\
			$(DIR_SRC)kill_client.c		\
			$(DIR_SRC)main.c		\
			$(DIR_SRC)parse_options2.c	\
			$(DIR_SRC)parse_options.c	\
			$(DIR_SRC)select.c		\
			$(DIR_SRC)select_init.c		\
			$(DIR_SRC)select_read_write.c	\
			$(DIR_SRC)stop_server.c

OBJ		=	$(SRC:.c=.o)

RM		=	rm -rf

CFLAGS		+=	-I $(DIR_INCLUDE) -Wall -Wextra -ansi -pedantic -ansi -O2 -Wchar-subscripts -Wcomment -Wformat=2 -Wimplicit-int -Werror-implicit-function-declaration \
	 -Wmain -Wparentheses -Wsequence-point -Wreturn-type -Wswitch -Wtrigraphs -Wunused -Wuninitialized -Wunknown-pragmas -Wfloat-equal -Wundef \
-Wshadow -Wpointer-arith -Wbad-function-cast -Wwrite-strings -Wconversion -Wsign-compare -Waggregate-return -Wstrict-prototypes \
-Wmissing-prototypes -Wmissing-declarations -Wmissing-noreturn -Wformat -Wmissing-format-attribute -Wno-deprecated-declarations \
-Wpacked -Wredundant-decls -Wnested-externs -Winline -Wlong-long -Wunreachable-code


LIBS		=	-lm `sh compatibilite.sh`


$(NAME)		:	$(OBJ)
			$(CC) -o $@ $(OBJ) $(LIBS)

.c.o		:
			$(CC) $(CFLAGS) -o $@ -c $<

all		:	$(NAME)

clean		:
			$(RM) $(OBJ) *~

fclean		:	clean
			$(RM) $(NAME)

re		:	fclean all