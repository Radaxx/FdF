# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aparabos <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 12:06:40 by aparabos          #+#    #+#              #
#    Updated: 2018/01/28 15:07:47 by aparabos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
RM = rm -rf
FLAGS = -Wall -Wextra -Werror
NAME = libft.a
OPT = -c
SUCCESS = \033[32m
SRCS = ft_pow.c \
	   ft_foreach.c \
	   ft_sqrt.c \
	   ft_factorial.c \
	   ft_lstadd.c \
	   ft_lstiter.c \
	   ft_lstmap.c \
	   ft_lstdel.c \
	   ft_lstdelone.c \
	   ft_lstnew.c \
	   ft_itoa.c \
	   ft_isalpha.c \
	   ft_memccpy.c \
	   ft_memmove.c \
	   ft_putendl_fd.c \
	   ft_strcat.c \
	   ft_strdel.c \
	   ft_strjoin.c \
	   ft_strncat.c \
	   ft_strnstr.c \
	   ft_strtrim.c \
	   ft_isascii.c \
	   ft_memchr.c \
	   ft_memset.c \
	   ft_putnbr.c \
	   ft_strchr.c \
	   ft_strdup.c \
	   ft_strlcat.c \
	   ft_strncmp.c \
	   ft_strrchr.c \
	   ft_tolower.c \
	   ft_atoi.c \
	   ft_isabs.c \
	   ft_isdigit.c \
	   ft_memcmp.c \
	   ft_putchar.c \
	   ft_putnbr_fd.c \
	   ft_strclr.c \
	   ft_strequ.c \
	   ft_strlen.c \
	   ft_strncpy.c \
	   ft_strsplit.c \
	   ft_toupper.c \
	   ft_bzero.c \
	   ft_isprint.c \
	   ft_memcpy.c \
	   ft_putchar_fd.c \
	   ft_putstr.c \
	   ft_strcmp.c \
	   ft_striter.c \
	   ft_strmap.c \
	   ft_strnequ.c \
	   ft_strstr.c \
	   ft_isalnum.c \
	   ft_memalloc.c \
	   ft_memdel.c \
	   ft_putendl.c \
	   ft_putstr_fd.c \
	   ft_strcpy.c \
	   ft_striteri.c \
	   ft_strmapi.c \
	   ft_strnew.c \
	   ft_strsub.c \
	   ft_strjoindel.c \
	   ft_strsubdel.c \
	   get_next_line.c \
	   ft_error.c \
	   ft_printarray.c \
	   ft_xmalloc.c \
	   ft_freetab.c
MAKEFLAGS = s
OBJS = $(SRCS:.c=.o)
.PHONY: all re fclean clean

all: $(NAME)

$(NAME): $(OBJS)
		@$(CC) $(OPT) $(FLAGS) $(SRCS)
		@ar rc $(NAME) $(OBJS)
		@ranlib $(NAME)
		@echo "$(SUCCESS)$(NAME) - Compiled with success ✅"

clean:
		@$(RM) $(OBJS)
		@echo "$(SUCCESS)$(NAME) - Object files cleaned with success ✅"

fclean: clean
		@$(RM) $(NAME)
		@echo "$(SUCCESS)$(NAME) - Executable cleaned with success ✅"

re: fclean all
