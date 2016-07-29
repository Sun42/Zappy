CC = gcc
NAME = buf
SRC = 	main.c \
	buf_add.c \
	buf_add_onbuf.c \
	buf_add_overflow.c \
	buf_debug.c \
	buf_init.c \
	buf_utils.c \
	buf_utils2.c \
	cmd_access.c \
	cmd_list.c \
	cmd_list2.c \
	cmd_save.c \
	cmd_unsave.c \
	cmd_utils.c

OBJ = $(SRC:.c=.o)

CFLAGS += -W -Wall -ansi -pedantic -g3

$(NAME) : $(OBJ)
	$(CC) -o $(NAME) $(OBJ)