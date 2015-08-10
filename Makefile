# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsautron <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/08/11 00:35:27 by bsautron          #+#    #+#              #
#    Updated: 2015/08/11 00:35:29 by bsautron         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
SRC = main.c \
	  ft_gettab.c \
	  expose_hook.c \
	  key_hook.c \
	  \
	  ft_abs.c \
	  ft_max.c \
	  ft_dtor.c \
	  \
	  ft_draw_line_in_image.c \
	  ft_proj_iso.c \
	  ft_proj_tab_iso.c \
	  ft_regu_tab.c \
	  ft_zoom_tab.c \
	  ft_make_draw.c \
	  ft_make_mx.c \
	  ft_make_my.c \
	  ft_make_mz.c \
	  ft_put_pixel_in_image.c \
	  ft_white.c \
	  \
	  ft_east.c \
	  ft_east_north.c \
	  ft_east_south.c \
	  ft_north.c \
	  ft_north_east.c \
	  ft_north_west.c \
	  ft_south.c \
	  ft_south_east.c \
	  ft_south_west.c \
	  ft_west.c \
	  ft_west_north.c \
	  ft_west_south.c 
OBJ = $(SRC:.c=.o)
NAME = fdf
FLAGS = -Wall -Wextra -Werror
LX11 = -L/usr/X11/lib -lmlx -lXext -lX11
LIB = -L./libft -lft

all: $(NAME)

$(NAME):
	make -C libft/
	$(CC) $(FLAGS) -I libft/includes/ -c $(SRC)
	$(CC) -o $(NAME) $(OBJ) $(LIB) $(LX11)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f *~

re: fclean all
