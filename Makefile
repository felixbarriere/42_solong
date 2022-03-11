SRCS = 	main.c \
		fill_tab.c \
		check_error.c \
		check_error2.c \
		so_long_utils.c \
		so_long_utils2.c \
		fill_map.c \
		movement.c \
		get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra 
#pour checker les leaks:
#-fsanitize=leaks -fsanitize=undefined  -fsanitize=address -g3

NAME = so_long
HEADER = so_long.h

.c.o:
		${CC} ${CFLAGS} -Imlx -c $< -o ${<:.c=.o}

$(NAME):	$(OBJS)
		${CC} ${CFLAGS} $(OBJS) -lmlx -Lget_next_line -framework OpenGL -framework AppKit -o $(NAME)

# pour faire tourner le programme sur Linux, ajouter -Lmlx
#MLX_DIR = mlx_linux
#MLX_MAKE = Makefile
#MLX_PATH = ${MLX_DIR}/libmlx.a

all:		$(NAME)

get_next_line:
	make -C

clean:
		rm -f $(OBJS)

fclean:
	rm -f $(OBJS) $(NAME)

re: fclean all

.PHONY: all clean fclean re
