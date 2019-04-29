# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: toboutal <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/08/25 18:25:09 by toboutal     #+#   ##    ##    #+#        #
#    Updated: 2018/08/25 18:25:15 by toboutal    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY: all, clean, flcean, re
NAME =	fdf
CC = gcc -o
LIB = libft/libft.a
SRC		= 	src/main.c \
			src/parsing.c \
			src/draw.c \
			src/get_data.c \
			src/image.c \
			src/hooks.c \
			src/color.c \
			src/free.c \
			src/pallette_clr.c \

FLAGS =		-Wall -Wextra -Werror -g -I libft/includes\

MLX =		minilibx_macos/libmlx.a -framework OpenGL -framework AppKit

OBJ		=	$(SRC:.c=.o)

$(NAME):
		Make -C ./libft/
		$(CC) $(NAME) $(FLAGS) $(LIB) $(SRC) $(MLX)

all: $(NAME)

clean:
	rm -f $(OBJ)
	Make clean -C ./libft/

fclean: clean
	rm -f $(NAME)
	Make fclean -C ./libft/

re: fclean all
