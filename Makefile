# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/05 17:28:04 by ddania-c          #+#    #+#              #
#    Updated: 2023/07/05 17:28:07 by ddania-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#~~~~~			NAME					~~~~~#
NAME = pipex

#~~~~~~			SOURCES					~~~~~~#
SRC_DIR = ./src
SRCS	= 	main.c					\
			init.c					\
			heredoc.c				\
			close_fds.c				\
			pipex.c					\
			cmd_path.c				\
			error_msg.c				\
			utils.c					\
			ft_split.c				\
			ft_strjoin.c			\
			ft_strnstr.c			\
			ft_substr.c				\
			get_next_line.c			\
			get_next_line_utils.c

SRCS := $(addprefix $(SRC_DIR)/, $(SRCS))

#~~~~~~			OBJETS					~~~~~~#
OBJ_DIR = ./obj
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

#~~~~~~			INCLUDES				~~~~~~#
INCS = pipex.h

#~~~~~~~		COMPILATION INFO		~~~~~~#
CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
LFLAGS:= -L $(LIBFT_DIR) -lft

#~~~~~~~		COMPILATION RULES		~~~~~~#
all: $(NAME)

$(NAME): $(OBJS)
	@echo "Compiling Pipex..."
	@$(CC) $(CFLAGS) $(OBJS) -o $@
	@echo "OK\n"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -O3 -c $< -o $@

clean:
	@echo "Deleting pipex object..."
	@$(RM) $(OBJS)
	@echo "OK\n"

fclean: clean
	@echo "Deleting pipex executable..."
	@$(RM) $(NAME)
	@echo "OK\n"

re:		fclean all

bonus:	re

.PHONY:	all clean fclean re bonus
