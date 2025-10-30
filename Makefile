# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atoepper <atoepper@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/06 14:47:59 by atoepper          #+#    #+#              #
#    Updated: 2025/10/30 16:56:22 by atoepper         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC      = gcc -O2
FLAGS  = -Wall -Wextra -Werror -g

### EXECUTABLE ###
NAME   = fdf

### SOURCE FILES ###
SRC_DIR = srcs
INC_DIR = incl
SRC = calculus.c \
		colors.c \
		colors_basic.c \
		drawing.c \
		fdf.c \
		hooks_2.c \
		hooks.c \
		init.c \
		memory.c \
		parse.c \
		parse_map.c \
		projection.c \
		utils.c \
		vector.c \
		main.c 
SRC := $(patsubst %.c, $(SRC_DIR)/%.c, $(SRC))

### COMPILATION ###
CC = cc
CFLAGS = -Wall -Wextra -Werror
CFLAGS += -g -fPIE 
CFLAGS += -I$(LIBFT_DIR) -I$(INC_DIR)

### INCLUDES ###

LIBFT_DIR = ./libft/
LIBFT = $(LIBFT_DIR)/libft.a
LDLIBS = -L$(LIBFT_DIR) -lft

GLIB_NAME = mlx
GLIB_PATH = ./incl/minilibx-linux

GFLAGS = -L$(GLIB_PATH) -l$(GLIB_NAME) -lX11 -lXext -lm

### OBJECTS ###

OBJ_DIR = .obj
OBJ = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))
OBJ_TEST = $(filter-out $(OBJ_DIR)/main.o,$(OBJ))

### RULES ###

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LDLIBS) $(GFLAGS) 

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(LIBFT)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(GLIB_NAME):
	@$(MAKE) -C $(GLIB_PATH)

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) clean -C $(LIBFT_DIR) 

fclean: clean
	rm -f $(NAME) 
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean
	$(MAKE) all

.PHONY: all clean fclean re
