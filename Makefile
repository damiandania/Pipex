# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/06 17:05:48 by ddania-c          #+#    #+#              #
#    Updated: 2023/07/07 15:28:43 by ddania-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

# Includes
INC = -I ./includes/

# Sources
SRC_DIR = src
UTILS_DIR = $(SRC_DIR)/utils

SRC = $(SRC_DIR)/main.c \
      $(SRC_DIR)/pipex.c \
      $(SRC_DIR)/heredoc.c \
      $(SRC_DIR)/cmd_path.c \
      $(SRC_DIR)/init.c \
      $(SRC_DIR)/error_msg.c \
      $(UTILS_DIR)/utils.c \
      $(UTILS_DIR)/ft_split.c \
      $(UTILS_DIR)/ft_strjoin.c \
      $(UTILS_DIR)/ft_strnstr.c \
      $(UTILS_DIR)/ft_substr.c \
      $(UTILS_DIR)/ft_strlcpy.c \
      $(UTILS_DIR)/get_next_line.c \
      $(UTILS_DIR)/get_next_line_utils.c

# Objects
OBJ_DIR = obj
OBJS = $(addprefix $(OBJ_DIR)/,$(notdir $(SRC:.c=.o)))

# Compilation info
CC = gcc
RM = rm -f
CFLAGS = -Werror -Wextra -Wall

# Colors
GREEN	= \033[0;32m
RED		= \033[0;31m
RESET	= \033[0m

all: $(NAME)

# Main rulepipex3/outfile_real.txt pipex3/outfile_pipex.txt pipex3/infile.txt
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(OBJ_DIR)/%.o: $(UTILS_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

# Objects rule
$(NAME): $(OBJS)
	@echo "$(GREEN)Compiling Pipex...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) -o $@
	@echo "$(GREEN)OK$(RESET)\n"

# Clean rules
clean:
	@echo "$(RED)Deleting pipex object...$(RESET)"
	@$(RM) -r $(OBJ_DIR)
	@echo "$(RED)OK\n$(RESET)"

fclean: clean
	@echo "$(RED)Deleting pipex executable...$(RESET)"
	@$(RM) $(NAME)
	@echo "$(RED)OK\n$(RESET)"

re: fclean all

.PHONY: all re clean fclean
