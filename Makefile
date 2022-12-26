# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/01 13:27:49 by psegura-          #+#    #+#              #
#    Updated: 2022/12/26 18:04:41 by psegura-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRCS =					\
		srcs/main.c		\
		srcs/pipex.c	\
		srcs/child.c	\
		srcs/utils.c	\

OBJS = $(SRCS:.c=.o)
OBJSB = $(SRCS:.c=.ob)

LIB = libft/libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I inc -I libft

$(NAME): $(OBJS)
	@make -C libft
	@rm -rf $(OBJSB)
	$(CC) $(CFLAGS) $(OBJS) $(LIB) -o $(NAME)
	@echo "🏂 pepex Done 🏂"

%.o:%.c
	$(CC) -D BONUS=0 $(CFLAGS) -c $< -o $@
	
%.ob:%.c
	$(CC) -D BONUS=1 $(CFLAGS) -c $< -o $@
	
bonus: $(OBJSB)
	@make -C libft
	@rm -rf $(OBJS)
	$(CC) $(CFLAGS) $(OBJSB) $(LIB) -o $(NAME)
	@echo "🏂 pepex_bonus Done 🏂"

all: $(NAME)

clean:
	@make clean -C libft
	@rm -rf $(OBJS)
	@rm -rf $(OBJSB)

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)

re: fclean all

norma:
	@echo 6966205b5b2024286e6f726d696e65747465207c206772657020274572726f7227207c207763202d6c29202d65712030205d5d3b207468656e206e6f726d696e657474653b20656c736520286e6f726d696e65747465207c206772657020274572726f7227293b206669 | xxd -r -p | zsh

.PHONY: all clean fclean re norma bonus