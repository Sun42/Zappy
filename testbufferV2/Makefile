NAME = testbuffer
CC = gcc
CFLAGS += -W -Wall -ansi -pedantic
SRC = buffer.c\
	debug_buf.c \
	add_buf.c \
	utils_buf.c \
	cmd_list.c

OBJ = $(SRC:.c=.o)
RM = rm -f

$(NAME) : $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean :
	$(RM) $(OBJ)
	$(RM) $(NaME)

re: clean $(NAME)