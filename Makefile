# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aparabos <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/15 11:11:28 by aparabos          #+#    #+#              #
#    Updated: 2018/01/15 16:02:22 by aparabos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CC_MLX = -lmlx -framework OpenGL -framework AppKit
OPT = -o
RM = rm -rf
NAME = fdf
LIBFT = ./libft/libft.a
SRCS = main.c \
	   ft_key.c \
	   get_map.c 
OBJS = $(SRCS:.c=.o)
MAKEFLAGS = s
.PHONY: all fclean clean re

all: $(NAME)

$(NAME): $(OBJS)
		@make -C ./libft/
		@$(CC) $(OPT) $(NAME) $(SRCS) $(LIBFT) $(CC_MLX)
		@echo "Compilation de FdF fini."

clean:
		@$(RM) $(OBJS)
		@echo "Supression des fichiers objets."

fclean: clean
		@make fclean -C ./libft/
		@$(RM) $(NAME)
		@echo "Suppresion de l'executable."

re: fclean all
