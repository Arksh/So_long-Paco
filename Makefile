# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/10 09:46:21 by fraalmei          #+#    #+#              #
#    Updated: 2023/03/17 17:45:20 by fraalmei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##Colors #
RED		= @echo "\033[0;31m"
GREEN	= @echo "\033[0;32m"
BLUE	= @echo "\033[0;33m"
PURPLE	= @echo "\033[0;34m"
CYAN	= @echo "\033[0;35m"
RESET	= "\033[1;0m"

#	file's name
NAME	= so_long

#	compilation
CC		= gcc

#	options to force the remove
RM		= /bin/rm -f

#	flags
CFLAGS	= -Wall -Werror -Wextra #-fsanitize=address -g3

#	Compile a mlx for linux or mac
UNAME = $(shell uname -s)
ifeq ($(UNAME), Linux)
#	SRCS_PLATFORM	= game_Linux.c
	MLX_DIR		= mlx_Linux
	MLX_FLAGS	= -Imlx_Linux -Lmlx_Linux -lmlx_Linux -lXext -lX11 -lm -lz
	INCLUDES	= -I$(INCLUDE_DIR) \
				  -I$(LIBFT_DIR) \
				  -I$(MLX_DIR) \
				  -I/usr/include
	LIBS		= -L$(LIBFT_DIR) -lft \
				  -L/usr/lib
endif

ifeq ($(UNAME), Darwin)
#	SRCS_PLATFORM	= game_Macos.c
	MLX_DIR		= mlx
	MLX_FLAGS	= -L$(MLX_DIR) -lmlx \
				  -framework OpenGL \
				  -framework AppKit \
				  -lm
	INCLUDES	= -I$(INCLUDE_DIR) \
				  -I$(LIBFT_DIR) \
				  -I$(MLX_DIR)
	LIBS		= -L$(LIBFT_DIR) -lft
endif

# Directories
BIN_DIR		= bin
SRC_DIR		= srcs
SRCS		= main.c window.c map.c images.c locations.c check_map.c keys.c objects.c
LIBFT_DIR 	= ../libft			# path to libft library
INCLUDE_DIR	= include			# path to headers
ASSETS_DIR	= assets			# path to assets

# Convert source files to binary
OBJS = $(SRCS:%.c=$(BIN_DIR)/%.o)

all: $(NAME)

restart: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) $(LIBS) $(MLX_FLAGS) -o $(NAME)

$(NAME): $(BIN) $(OBJS) | libs
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(MLX_FLAGS) -o $(NAME)

#	Objects construction
$(OBJS): $(BIN_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) -g $(CFLAGS) $(INCLUDES) -c $< -o $@

#	Libraries compile
libs:
	make -C $(LIBFT_DIR)
	make -C $(MLX_DIR)

re: fclean all

cbuild:
	$(RM) -r $(BIN_DIR)

clean:
	$(RM) $(OBJS)
	make clean -C $(LIBFT_DIR)
	make clean -C $(MLX_DIR)
	$(RM) -r $(BIN_DIR)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(MLX_DIR)
	$(RM) $(NAME)

show:
	@printf "UNAME		: $(UNAME)\n"
	@printf "NAME		: $(NAME)\n"
	@printf "CC  		: $(CC)\n"
	@printf "CFLAGS		: $(CFLAGS)\n"
	@printf "MLX_FLAGS	: $(MLX_FLAGS)\n"
	@printf "SRCS		: $(SRCS)\n"
	@printf "OBJS		: $(OBJS)\n"

.PHONY: $(LIBFT) all clean fclean re
