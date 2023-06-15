# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/20 13:30:45 by ddania-c          #+#    #+#              #
#    Updated: 2023/05/20 13:38:33 by ddania-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#~~~~~NAME~~~~~
NAME = pipex

#~~~~~~SOURCES~~~~~~
SRC_DIR = ./src
SRCS	= 	main.c		\
			init.c		\
			error.c		\			

SRCS := $(addprefix $(SRC_DIR)/, $(SRCS))

#~~~~~~OBJETS~~~~~
OBJ_DIR = ./obj
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

#~~~~~~INCLUDES~~~~~~
INCS = pipex.h

#~~~~~~~		GNL						~~~~~~#
GNL_DIR = ./get_next_line/
GNL_OBJS = ${addprefix ${GNL_DIR}, ${GNL:.c=.o}}

#~~~~~~~		LIBFT					~~~~~~#
LIBFT_DIR = ./libft
LIBFT_PATH = ${LIBFT_DIR}/libft.a

#~~~~~~~		COMPILATION INFO		~~~~~~#
CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
LFLAGS:= -L $(LIBFT_DIR) -lft

#~~~~~~~		OS OPTION				~~~~~~#
# LINUX
# MAC

#~~~~~~~		COMPILATION RULES		~~~~~~#
all: $(NAME)

$(NAME): $(OBJS) $(GNL_OBJS)
	@make -C ${LIBFT_DIR}
	@echo "Compiling Pipex..."
	@$(CC) $(CFLAGS) $(OBJS) $(GNL_OBJS) -o $@
	@echo "OK\n"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -O3 -c $< -o $@

clean:
	@make clean -C ${LIBFT_DIR}
	@echo "Deleting pipex object..."
	@$(RM) $(OBJS) $(GNL_OBJS)
	@echo "OK\n"

fclean: clean
	@make fclean -C ${LIBFT_DIR}
	@echo "Deleting pipex executable..."
	@$(RM) $(NAME)
	@echo "OK\n"

re:		fclean all

bonus:	re

.PHONY:	all clean fclean re bonus
