# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bhalderm <bhalderm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/04 14:08:37 by bhalderm          #+#    #+#              #
#    Updated: 2018/01/09 16:03:25 by bhalderm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

libx_flags = -L minilibx_macos -lmlx -framework OpenGL -framework AppKit

cflags = -Wall -Wextra -Werror

make_libft = @make -C ./get_next_line/libft/

header = fdf.h

includes = ./get_next_line/libft/libft.a ./get_next_line/get_next_line.c

SRC = main.c init.c utils.c draw_loop.c generate.c utils_2.c

OBJ = *.o

cc = @gcc

name = fdf

all : $(name)

$(name) :
	@make -C get_next_line/libft/
	$(cc) $(libx_flags) $(SRC) $(includes) -o $(name)
	@echo "Created FDF executable"
clean:
	@make -C get_next_line/libft/ clean
	@/bin/rm -f $(name)
fclean: clean
	@make -C get_next_line/libft/ fclean
re: fclean all