NAME = fdf

CC = gcc

FLAGS = -Wall -Wextra -Werror

FFLAGS = -framework OpenGL -framework Appkit

LIBFT = ./libft/

INCLUDES = ./includes/

IMLX = /usr/local/include/

LMLX = /usr/local/lib/

SRCS = ./src/fdf.c\
		./src/bresenham.c\
	   ./src/set_env.c\
	   ./src/window.c\
		./src/make_tab.c\
		./src/set_tab.c\
		./src/fill_map.c\
		./src/key_run.c\
		./src/fill_pixel.c\
		./src/center.c\
		./src/projection.c\
		./src/erreur.c\
		./src/zoom.c\
		./src/movement.c\
		./src/background.c\
		./src/menu.c\
		./src/color.c

LIB = $(LIBFT)/libft.a

BIN = $(SRCS:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(BIN) $(INCLUDES) $(LIB)
	$(CC) $(FLAGS) $(BIN)  $(LIB) -I $(INCLUDES) -I $(IMLX) -L $(LMLX) -lmlx $(FFLAGS) -o $(NAME)

%.o:%.c
	$(CC) $(FLAGS) -I $(INCLUDES) -I $(IMLX) -c $< -o $@

$(LIB):
	make -C $(LIBFT)

clean:
	rm -f $(BIN)
	make clean -C $(LIBFT)

fclean:clean
	rm -f $(NAME)
	make fclean -C $(LIBFT)

re: fclean all
