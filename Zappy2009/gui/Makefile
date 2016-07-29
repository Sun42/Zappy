##
## Makefile for Makefile in /u/all/yurdus_y/cu/rendu/c/Zappy2009/gui
## 
## Made by yavuz yurdusev
## Login   <yurdus_y@epitech.net>
## 
## Started on  Thu Apr 23 20:37:56 2009 yavuz yurdusev
## Last update Sun Apr 26 12:34:16 2009 yavuz yurdusev
##

CC		=	gcc

NAME		=	gui

DIR_INCLUDE	=	./header/

DIR_SRC		=	./src/

SRC		=	$(DIR_SRC)aff_var_infos.c	\
			$(DIR_SRC)blit_and_verif.c	\
			$(DIR_SRC)buf_add.c		\
			$(DIR_SRC)buf_add_onbuf.c	\
			$(DIR_SRC)buf_add_overflow.c	\
			$(DIR_SRC)buf_init.c		\
			$(DIR_SRC)buf_utils.c		\
			$(DIR_SRC)buf_utils2.c		\
			$(DIR_SRC)broadcast.c		\
			$(DIR_SRC)cmd_access.c		\
			$(DIR_SRC)cmd_list.c		\
			$(DIR_SRC)cmd_list2.c		\
			$(DIR_SRC)cmd_save.c		\
			$(DIR_SRC)cmd_unsave.c		\
			$(DIR_SRC)cmd_utils.c		\
			$(DIR_SRC)event.c		\
			$(DIR_SRC)func_egg.c		\
			$(DIR_SRC)func_init_clip.c	\
			$(DIR_SRC)func_init_ghost.c	\
			$(DIR_SRC)func_init_object.c	\
			$(DIR_SRC)func_init_perso.c	\
			$(DIR_SRC)func_object.c		\
			$(DIR_SRC)func_print_perso.c	\
			$(DIR_SRC)func_str.c		\
			$(DIR_SRC)func_xalloc.c		\
			$(DIR_SRC)func_xy_max.c		\
			$(DIR_SRC)free_all.c		\
			$(DIR_SRC)free_all_struct.c	\
			$(DIR_SRC)infos_inventaire.c	\
			$(DIR_SRC)init.c		\
			$(DIR_SRC)init_wood.c		\
			$(DIR_SRC)main.c		\
			$(DIR_SRC)map.c			\
			$(DIR_SRC)minimap.c		\
			$(DIR_SRC)minimap_utils.c	\
			$(DIR_SRC)move.c		\
			$(DIR_SRC)move_map.c		\
			$(DIR_SRC)move_teleport.c	\
			$(DIR_SRC)pos_perso.c		\
			$(DIR_SRC)read_server.c		\
			$(DIR_SRC)socket.c		\
			$(DIR_SRC)serv_bvn.c		\
			$(DIR_SRC)serv_cmd.c		\
			$(DIR_SRC)serv_ebo.c		\
			$(DIR_SRC)serv_enw.c		\
			$(DIR_SRC)serv_eht.c		\
			$(DIR_SRC)serv_edi.c		\
			$(DIR_SRC)serv_msz.c		\
			$(DIR_SRC)serv_bct.c		\
			$(DIR_SRC)serv_tna.c		\
			$(DIR_SRC)serv_pbc.c		\
			$(DIR_SRC)serv_pdi.c		\
			$(DIR_SRC)serv_pdr.c		\
			$(DIR_SRC)serv_pex.c		\
			$(DIR_SRC)serv_pgt.c		\
			$(DIR_SRC)serv_pic.c		\
			$(DIR_SRC)serv_pie.c		\
			$(DIR_SRC)serv_pin.c		\
			$(DIR_SRC)serv_plv.c		\
			$(DIR_SRC)serv_pnw.c		\
			$(DIR_SRC)serv_ppo.c		\
			$(DIR_SRC)serv_seg.c		\
			$(DIR_SRC)verif_team.c		\
			$(DIR_SRC)x_func_sdl.c


OBJ		=	$(SRC:.c=.o)

LDFLAGS		=	`sdl-config --libs --cflags` -lSDLmain -lSDL -lSDL_image -lSDL_net -lSDL_ttf

CFLAGS		+=	-I $(DIR_INCLUDE) -Wall -Wextra -ansi -pedantic

RM		=	rm -rf


$(NAME)		:	$(OBJ)
			$(CC) -o $@ $(OBJ) $(LDFLAGS)

.c.o		:
			$(CC) $(CFLAGS) -o $@ -c $<

all		:	$(NAME)

clean		:
			$(RM) -rf $(OBJ) *~

fclean		:	clean
			$(RM) $(NAME)

re		:	fclean all
