# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aparabos <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/22 14:14:39 by aparabos          #+#    #+#              #
#    Updated: 2018/01/28 17:30:49 by aparabos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = gcc
RM = rm -rf
CCFLAGS = -Wall -Werror -Wextra
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit
LIB = -C $(D_LIB)
OBJS = $(SRCS:.c=.o)
D_SRCS = ./srcs/
D_LIB = ./libft/
D_INC = ./includes/
SRCS = fdf.c \
	   get_map.c \
	   set_var.c \
	   draw_line.c \
	   key.c \
	   set_matrice.c
SUCCES_COLOR = \033[32m
.PHONY: all clean fclean re

all: $(NAME)

%.o:$(D_SRCS)%.c
		@$(CC) $(CCFLAGS) -I $(D_LIB) -I $(D_INC) -o $@ -c $<

$(NAME): $(OBJS)
		@make $(LIB)
		@$(CC) $(CCFLAGS) -o $(NAME) $(OBJS) -L $(D_LIB) -lft $(MLXFLAGS)
		@echo "$(SUCCES_COLOR)$(NAME) - Compiled with Success ✅"

clean:
		@make clean $(LIB)
		@echo "$(SUCCES_COLOR)$(NAME) - Object file cleaned with success ✅"
		@$(RM) $(OBJS)

fclean: clean
		@make fclean $(LIB)
		@$(RM) $(NAME)
		@echo "$(SUCCES_COLOR)$(NAME) - Executable cleaned with success ✅"

re: fclean all
