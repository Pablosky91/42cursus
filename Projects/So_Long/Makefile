# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/22 16:54:43 by pdel-olm          #+#    #+#              #
#    Updated: 2024/10/18 16:13:24 by pdel-olm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#GENERAL VARIABLES

MAKEFLAGS := --no-print-directory

RM := rm -rf
MKDIR := mkdir -p

NAME := so_long
BONUS_NAME := so_long_bonus

CC := gcc
CFLAGS := -g3 -fsanitize=address -Wall -Wextra -Werror

#INCLUDE

LIBFT_PATH := ../../libft
LIBFT := $(LIBFT_PATH)/libft.a
LIBFT_FLAG := -L $(LIBFT_PATH) -l ft

MLX_PATH := MLX42
MLX_BUILD := $(MLX_PATH)/build
MLX_NAME := $(MLX_BUILD)/libmlx42.a
MLX_INCLUDE := $(MLX_PATH)/include/MLX42
MLX_FLAG := -L $(MLX_BUILD) -l mlx42 -l glfw -l dl -l m -pthread


#FILES

SRC_DIR := src/
OBJ_DIR := obj/

SOURCES :=	\
			so_long.c\
			$(addprefix control/,\
				exit_game.c\
				free_game.c\
				free_status.c\
				)\
			$(addprefix parse/,\
				check_extension.c\
				get_info_map.c\
				open_file.c\
				read_map.c\
				save_cell.c\
				)\
			$(addprefix pathing/,\
				add_node.c\
				copy_node.c\
				create_node.c\
				get_cell_by.c\
				get_id_fish.c\
				is_same_status.c\
				is_node_repeated.c\
				valid_path.c\
				)\
			$(addprefix window/,\
				create_window.c\
				init_mlx.c\
				move_penguin.c\
				my_key_hook.c\
				my_loop_hook.c\
				show_penguin.c\
				start_movement.c\
				)\

OBJECTS := $(addprefix $(OBJ_DIR), $(SOURCES:.c=.o))
SOURCES := $(addprefix $(SRC_DIR), $(SOURCES))

#BONUS FILES

BONUS_SRC_DIR := src_bonus/
BONUS_OBJ_DIR := obj_bonus/

BONUS_SOURCES := \

BONUS_SOURCES := $(addprefix $(SRC_DIR), $(BONUS_SOURCES))
BONUS_SOURCES += $(SOURCES)

BONUS_SOURCES := $(BONUS_SOURCES:.c=_bonus.c)
BONUS_SOURCES := $(subst /,_bonus/,$(BONUS_SOURCES))

BONUS_OBJECTS := $(BONUS_SOURCES:.c=.o)
BONUS_OBJECTS := $(subst $(BONUS_SRC_DIR),$(BONUS_OBJ_DIR),$(BONUS_OBJECTS))

#COLOURS

RED := \033[31m
GREEN := \033[32m
YELLOW := \033[33m
BLUE := \033[34m

RESET := \033[0m

#EXTRA VARIABLES

MAP := medium
MAP_DIRECTORY := maps/
MAP_EXTENSION := .ber


OUT := out

VALGRIND_DIR := valgrind/

#RULES

a: all
all: $(NAME)

test:
	echo $(BONUS_SOURCES)
	echo $(BONUS_OBJECTS)

$(NAME): $(LIBFT) $(MLX_NAME) $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT_FLAG) $(MLX_FLAG) -o $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH)

$(MLX_NAME):
	@$(MAKE) msg_mlx_start
	cmake $(MLX_PATH) -B $(MLX_BUILD)
	make -C $(MLX_BUILD) -j4
	@$(MAKE) msg_mlx_end

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(LIBFT_FLAG) -I $(SRC_DIR) -I $(LIBFT_PATH) -I $(MLX_INCLUDE) -c $^ -o $@

$(OBJ_DIR):
	$(MKDIR) $(OBJ_DIR)
	$(MKDIR) $(OBJ_DIR)control
	$(MKDIR) $(OBJ_DIR)parse
	$(MKDIR) $(OBJ_DIR)pathing
	$(MKDIR) $(OBJ_DIR)window

c: clean
clean: msg_clean_start
	$(RM) $(OBJ_DIR) $(BONUS_OBJ_DIR)
	@$(MAKE) -C $(LIBFT_PATH) clean
	@$(MAKE) msg_clean_end

f: fclean
fclean: msg_fclean_start
	$(RM) $(OBJ_DIR) $(BONUS_OBJ_DIR) $(MLX_BUILD) $(NAME) $(BONUS_NAME)
	@$(MAKE) -C $(LIBFT_PATH) fclean
	@$(MAKE) msg_fclean_end

r: re
re: fclean all

#BONUS RULES

b:bonus
bonus: $(BONUS_NAME)

$(BONUS_NAME): $(LIBFT) $(MLX_NAME) $(BONUS_OBJECTS)
	$(CC) $(CFLAGS) $(BONUS_OBJECTS) $(LIBFT_FLAG) $(MLX_FLAG) -o $(BONUS_NAME)

$(BONUS_OBJ_DIR)%.o: $(BONUS_SRC_DIR)%.c | $(BONUS_OBJ_DIR)
	$(CC) $(CFLAGS) $(LIBFT_FLAG) -I $(BONUS_SRC_DIR) -I $(LIBFT_PATH) -I $(MLX_INCLUDE) -c $^ -o $@

$(BONUS_OBJ_DIR):
	$(MKDIR) $(BONUS_OBJ_DIR)
	$(MKDIR) $(BONUS_OBJ_DIR)control_bonus
	$(MKDIR) $(BONUS_OBJ_DIR)parse_bonus
	$(MKDIR) $(BONUS_OBJ_DIR)pathing_bonus
	$(MKDIR) $(BONUS_OBJ_DIR)window_bonus

#EXTRA RULES

reb: fclean bonus

be: bonus
	-./$(BONUS_NAME) $(addprefix $(MAP_DIRECTORY), $(addsuffix $(MAP_EXTENSION), $(MAP)))

e: exec
exec: all
	-./$(NAME) $(addprefix $(MAP_DIRECTORY), $(addsuffix $(MAP_EXTENSION), $(MAP)))

rexec: re exec

error: all
	@echo
	-./$(NAME)
	@echo
	-./$(NAME) maps/invalid/.ber
	@echo
	-./$(NAME) maps/invalid/no_extension
	@echo
	-./$(NAME) maps/invalid/other_extension.txt
	@echo
	-./$(NAME) maps/invalid/no_file.ber
	@echo
	mkdir -p  maps/invalid/directory.ber
	-./$(NAME) maps/invalid/directory.ber
	@echo
	chmod 000 maps/invalid/change_permissions.ber
	-./$(NAME) maps/invalid/change_permissions.ber
	@chmod 644 maps/invalid/change_permissions.ber
	@echo
	-./$(NAME) maps/invalid/empty.ber
	@echo
	-./$(NAME) maps/invalid/not_surrounded.ber
	@echo
	-./$(NAME) maps/invalid/not_rectangular0.ber
	@echo
	-./$(NAME) maps/invalid/not_rectangular1.ber
	@echo
	-./$(NAME) maps/invalid/no_collectibles.ber
	@echo
	-./$(NAME) maps/invalid/no_starting_position.ber
	@echo
	-./$(NAME) maps/invalid/two_starting_positions.ber
	@echo
	-./$(NAME) maps/invalid/no_exit.ber
	@echo
	-./$(NAME) maps/invalid/two_exits.ber
	@echo
	-./$(NAME) maps/invalid/other_characters.ber
	@echo
	-./$(NAME) maps/invalid/no_path.ber
	@echo

levels: all
	@echo
	-./$(NAME) maps/tutorial0.ber
	@echo
	-./$(NAME) maps/tutorial1.ber
	@echo
	-./$(NAME) maps/tutorial2.ber
	@echo
	-./$(NAME) maps/tutorial3.ber
	@echo
	-./$(NAME) maps/square0.ber
	@echo
	-./$(NAME) maps/square1.ber
	@echo

n: norminette
norminette:
	@echo "norminette src libft | grep Error\n"
	@if norminette src libft | grep -q "Error"; then echo "$(RED)$$(norminette src libft | grep "Error" | sed -z 's/\nError/\n\$(YELLOW)  Error/g' | sed -z 's/\n/\n\$(RED)/g')"; else echo "$(GREEN)Everything OK!$(RESET)"; fi
normi:
	@if norminette src libft | grep -q "Error"; then echo "\n$(RED)$$(norminette src libft | grep "Error" | grep -v -e "TOO_MANY_FUNCS" -e "WRONG_SCOPE_COMMENT" -e "EMPTY_LINE_FUNCTION" -e "LINE_TOO_LONG" -e "TOO_MANY_LINES" -e "CONSECUTIVE_NEWLINES" | sed -z 's/\nError/\n\$(YELLOW)  Error/g' | sed -z 's/\n/\n\$(RED)/g')"; else echo "$(GREEN)Run full norminette!$(RESET)"; fi

#until there's something better: make v CFLAGS=
v: valgrind
valgrind: clean $(LIBFT) $(OBJECTS) | $(VALGRIND_DIR)
	@$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT_FLAG) $(MLX_FLAG) -o $(NAME)
	@-valgrind --leak-check=full --show-leak-kinds=all --log-file=$(VALGRIND_DIR)$$(date +"%y%m%d%H%M%S").txt ././$(NAME) $(addprefix $(MAP_DIRECTORY), $(addsuffix $(MAP_EXTENSION), $(MAP)))
	@echo "$(BLUE) $$(grep "ERROR SUMMARY" $(VALGRIND_DIR)/$$(ls valgrind | tail -1))"
	@$(MAKE) clean

$(VALGRIND_DIR):
	$(MKDIR) $(VALGRIND_DIR)

last_valgrind:
	@cat $(VALGRIND_DIR)$$(ls valgrind | tail -1)

clean_valgrind:
	$(RM) $(VALGRIND_DIR)

#MESSAGES

msg_mlx_start:
	@echo "$(YELLOW)Starting MLX42 compilation$(RESET)"

msg_mlx_end:
	@echo "$(GREEN)MLX42 compilation complete$(RESET)"

msg_clean_start:
	@echo "$(YELLOW)Cleaning push_swap objects$(RED)"

msg_clean_end:
	@echo "$(GREEN)Push_swap objects cleaned$(RESET)"

msg_fclean_start:
	@echo "$(YELLOW)Cleaning push_swap$(RED)"

msg_fclean_end:
	@echo "$(GREEN)Push_swap cleaned$(RESET)"

#PHONY

.PHONY: all clean fclean re bonus be reb exec norminette normi valgrind last_valgrind clean_valgrind a c f r b e n v msg_mlx_start msg_mlx_end msg_clean_start msg_clean_end msg_fclean_start msg_fclean_end