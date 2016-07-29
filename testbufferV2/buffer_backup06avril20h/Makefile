NAME = testbuffer
CC = gcc
CFLAGS += -W -Wall -ansi -pedantic
SRC = buffer.c\
	debug_buf.c \
	add_buf.c \
	utils_buf.c

OBJ = $(SRC:.c=.o)


$(NAME) : $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

