# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/22 16:54:43 by pdel-olm          #+#    #+#              #
#    Updated: 2025/05/01 17:07:58 by pdel-olm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#GENERAL VARIABLES

MAKEFLAGS := --no-print-directory

RM := rm -rf
MKDIR := mkdir -p

NAME := so_long
BONUS_NAME := soo_loong

CC := cc
CFLAGS := -Wall -Wextra -Werror -g3 -fsanitize=address

#INCLUDE

LIBFT_PATH := libft/
LIBFT := $(LIBFT_PATH)libft.a
LIBFT_FLAG := -L $(LIBFT_PATH) -l ft

MLX_PATH := MLX42
MLX_BUILD := $(MLX_PATH)/build
MLX_NAME := $(MLX_BUILD)/libmlx42.a
MLX_INCLUDE := $(MLX_PATH)/include/MLX42
MLX_FLAG := -L $(MLX_BUILD) -l mlx42 -l glfw -l dl -l m -pthread

#FILES

DIRECTORIES :=	\
				control\
				hook\
				parse\
				pathing\
				window\

SRC_DIR := src/
OBJ_DIR := obj/
HEADER := $(SRC_DIR)/$(NAME).h

SOURCES :=	\
			so_long.c\
			$(addprefix control/,\
				exit_game.c\
				free_game.c\
				free_status.c\
				)\
			$(addprefix hook/,\
				my_key_hook.c\
				my_loop_hook.c\
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
				animations.c\
				draw_cell.c\
				init_mlx.c\
				move_penguin.c\
				start_movement.c\
				)\

OBJECTS := $(addprefix $(OBJ_DIR), $(SOURCES:.c=.o))
SOURCES := $(addprefix $(SRC_DIR), $(SOURCES))

#BONUS FILES

BONUS_SRC_DIR := src_bonus/
BONUS_OBJ_DIR := obj_bonus/
BONUS_HEADER := $(BONUS_SRC_DIR)/$(NAME)_bonus.h

BONUS_SOURCES := \
				$(addprefix pathing/,\
					get_id_seal.c\
				)\
				$(addprefix hook/,\
					my_close_hook.c\
					my_cursor_hook.c\
					my_mouse_hook.c\
					my_scroll_hook.c\
				)\
				$(addprefix window/,\
					direction_to_mouse.c\
					refresh_counter.c\
					retry.c\
				)\

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

VALGRIND_DIR := valgrind/

#RULES

.PHONY: a all
a: all
all: $(NAME)

$(NAME): $(LIBFT) $(MLX_NAME) $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT_FLAG) $(MLX_FLAG) -o $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH)

$(MLX_NAME): $(MLX_PATH)
	@$(MAKE) msg_mlx_start
	cmake $(MLX_PATH) -B $(MLX_BUILD)
	make -C $(MLX_BUILD) -j4
	@$(MAKE) msg_mlx_end

$(MLX_PATH):
	git clone https://github.com/codam-coding-college/MLX42.git

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADER) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I $(SRC_DIR) -I $(LIBFT_PATH) -I $(MLX_INCLUDE) -c $< -o $@

$(OBJ_DIR):
	$(MKDIR) $(addprefix $(OBJ_DIR),$(DIRECTORIES))

.PHONY: c clean
c: clean
clean: msg_clean_start
	$(RM) $(OBJ_DIR) $(BONUS_OBJ_DIR)
	@$(MAKE) -C $(LIBFT_PATH) clean
	@$(MAKE) msg_clean_end

.PHONY: f fclean
f: fclean
fclean: msg_fclean_start
	$(RM) $(OBJ_DIR) $(BONUS_OBJ_DIR) $(MLX_BUILD) $(NAME) $(BONUS_NAME)
	@$(MAKE) -C $(LIBFT_PATH) fclean
	@$(MAKE) msg_fclean_end

.PHONY: r re
r: re
re: fclean all

#BONUS RULES

.PHONY: b bonus
b:bonus
bonus: $(BONUS_NAME)

$(BONUS_NAME): $(LIBFT) $(MLX_NAME) $(BONUS_OBJECTS)
	$(CC) $(CFLAGS) $(BONUS_OBJECTS) $(LIBFT_FLAG) $(MLX_FLAG) -o $(BONUS_NAME)

$(BONUS_OBJ_DIR)%.o: $(BONUS_SRC_DIR)%.c $(BONUS_HEADER) | $(BONUS_OBJ_DIR)
	$(CC) $(CFLAGS) -I $(BONUS_SRC_DIR) -I $(LIBFT_PATH) -I $(MLX_INCLUDE) -c $< -o $@

$(BONUS_OBJ_DIR):
	$(MKDIR) $(addprefix $(BONUS_OBJ_DIR),$(addsuffix _bonus,$(DIRECTORIES)))

#EXTRA RULES

.PHONY: reb
reb: fclean bonus

.PHONY: e exec
e: exec
exec: all
	-./$(NAME) $(addprefix $(MAP_DIRECTORY), $(addsuffix $(MAP_EXTENSION), $(MAP)))

.PHONY: be bexec
be: bexec
bexec: bonus
	-./$(BONUS_NAME) $(addprefix $(MAP_DIRECTORY), $(addsuffix $(MAP_EXTENSION), $(MAP)))

.PHONY: error
error: all
	@echo "\nMap:"
	@./$(NAME) || true

	@echo "\nMap: maps/invalid/.ber"
	@cat maps/invalid/.ber && echo
	@./$(NAME) maps/invalid/.ber || true

	@echo "\nMap: maps/invalid/no_extension"
	@cat maps/invalid/no_extension && echo
	@./$(NAME) maps/invalid/no_extension || true

	@echo "\nMap: maps/invalid/other_extension.txt"
	@cat maps/invalid/other_extension.txt && echo
	@./$(NAME) maps/invalid/other_extension.txt || true

	@echo "\nMap: maps/invalid/no_file.ber"
	@./$(NAME) maps/invalid/no_file.ber || true

	@echo "\nMap: maps/invalid/directory.ber"
	@$(MKDIR) maps/invalid/directory.ber
	@./$(NAME) maps/invalid/directory.ber || true

	@echo "\nMap: maps/invalid/no_permissions.ber"
	@chmod 000 maps/invalid/no_permissions.ber
	@./$(NAME) maps/invalid/no_permissions.ber || true
	@chmod 644 maps/invalid/no_permissions.ber

	@echo "\nMap: maps/invalid/empty.ber"
	@cat maps/invalid/empty.ber && echo
	@./$(NAME) maps/invalid/empty.ber || true

	@echo "\nMap: maps/invalid/not_surrounded.ber"
	@cat maps/invalid/not_surrounded.ber && echo
	@./$(NAME) maps/invalid/not_surrounded.ber || true

	@echo "\nMap: maps/invalid/not_rectangular0.ber"
	@cat maps/invalid/not_rectangular0.ber && echo
	@./$(NAME) maps/invalid/not_rectangular0.ber || true

	@echo "\nMap: maps/invalid/not_rectangular1.ber"
	@cat maps/invalid/not_rectangular1.ber && echo
	@./$(NAME) maps/invalid/not_rectangular1.ber || true

	@echo "\nMap: maps/invalid/no_collectibles.ber"
	@cat maps/invalid/no_collectibles.ber && echo
	@./$(NAME) maps/invalid/no_collectibles.ber || true

	@echo "\nMap: maps/invalid/no_starting_position.ber"
	@cat maps/invalid/no_starting_position.ber && echo
	@./$(NAME) maps/invalid/no_starting_position.ber || true

	@echo "\nMap: maps/invalid/two_starting_positions.ber"
	@cat maps/invalid/two_starting_positions.ber && echo
	@./$(NAME) maps/invalid/two_starting_positions.ber || true

	@echo "\nMap: maps/invalid/no_exit.ber"
	@cat maps/invalid/no_exit.ber && echo
	@./$(NAME) maps/invalid/no_exit.ber || true

	@echo "\nMap: maps/invalid/two_exits.ber"
	@cat maps/invalid/two_exits.ber && echo
	@./$(NAME) maps/invalid/two_exits.ber || true

	@echo "\nMap: maps/invalid/other_characters.ber"
	@cat maps/invalid/other_characters.ber && echo
	@./$(NAME) maps/invalid/other_characters.ber || true

	@echo "\nMap: maps/invalid/no_path0.ber"
	@cat maps/invalid/no_path0.ber && echo
	@./$(NAME) maps/invalid/no_path0.ber || true
	
	@echo "\nMap: maps/invalid/no_path1.ber"
	@cat maps/invalid/no_path1.ber && echo
	@./$(NAME) maps/invalid/no_path1.ber || true

.PHONY: l levels
l: levels
levels: all bonus
	@echo
	-./$(BONUS_NAME) maps/tutorial0.ber
	@echo
	-./$(BONUS_NAME) maps/tutorial1.ber
	@echo
	-./$(BONUS_NAME) maps/tutorial2.ber
	@echo
	-./$(BONUS_NAME) maps/tutorial3.ber
	@echo
	-./$(BONUS_NAME) maps/tutorial4.ber
	@echo
	-./$(BONUS_NAME) maps/square0.ber
	@echo
	-./$(BONUS_NAME) maps/square1.ber
	@echo
	-./$(BONUS_NAME) maps/heart.ber
	@echo
	-./$(BONUS_NAME) maps/9rooms.ber
	@echo
	-./$(BONUS_NAME) maps/4rooms.ber
	@echo
	-./$(BONUS_NAME) maps/labyrinth.ber
	@echo

.PHONY: run
run: levels fclean

.PHONY: n norminette normi
n: norminette
norminette:
	@echo "norminette $(SRC_DIR) $(BONUS_SRC_DIR) $(LIBFT_PATH) | grep Error\n"
	@if norminette $(SRC_DIR) $(BONUS_SRC_DIR) $(LIBFT_PATH) | grep -q "Error"; then echo "$(RED)$$(norminette $(SRC_DIR) $(BONUS_SRC_DIR) $(LIBFT_PATH) | grep "Error" | sed -z 's/\nError/\n\$(YELLOW)  Error/g' | sed -z 's/\n/\n\$(RED)/g')$(RESET)"; else echo "$(GREEN)Everything OK!$(RESET)"; fi
normi:
	@if norminette $(SRC_DIR) $(BONUS_SRC_DIR) $(LIBFT_PATH) | grep -q "Error"; then echo "\n$(RED)$$(norminette $(SRC_DIR) $(BONUS_SRC_DIR) $(LIBFT_PATH) | grep "Error" | grep -v -e "TOO_MANY_FUNCS" -e "WRONG_SCOPE_COMMENT" -e "EMPTY_LINE_FUNCTION" -e "LINE_TOO_LONG" -e "TOO_MANY_LINES" -e "CONSECUTIVE_NEWLINES" | sed -z 's/\nError/\n\$(YELLOW)  Error/g' | sed -z 's/\n/\n\$(RED)/g')$(RESET)"; else echo "$(GREEN)Run full norminette!$(RESET)"; fi

.PHONY: v valgrind valgrind_no_flags
v: valgrind
valgrind:
	@$(MAKE) CFLAGS= valgrind_no_flags
valgrind_no_flags: clean $(LIBFT) $(OBJECTS) | $(VALGRIND_DIR)
	@$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT_FLAG) $(MLX_FLAG) -o $(NAME)
	@-valgrind --leak-check=full --show-leak-kinds=all --log-file=$(VALGRIND_DIR)$$(date +"%y%m%d%H%M%S").txt ././$(NAME) $(addprefix $(MAP_DIRECTORY), $(addsuffix $(MAP_EXTENSION), $(MAP)))
	@echo "$(BLUE) $$(grep "ERROR SUMMARY" $(VALGRIND_DIR)/$$(ls valgrind | tail -1))"
	@$(MAKE) clean

.PHONY: vb balgrind balgrind_no_flags
vb: balgrind
balgrind:
	@$(MAKE) CFLAGS= balgrind_no_flags
balgrind_no_flags: clean $(LIBFT) $(BONUS_OBJECTS) | $(VALGRIND_DIR)
	@$(CC) $(CFLAGS) $(BONUS_OBJECTS) $(LIBFT_FLAG) $(MLX_FLAG) -o $(BONUS_NAME)
	@-valgrind --leak-check=full --show-leak-kinds=all --log-file=$(VALGRIND_DIR)$$(date +"%y%m%d%H%M%S").txt ././$(BONUS_NAME) $(addprefix $(MAP_DIRECTORY), $(addsuffix $(MAP_EXTENSION), $(MAP)))
	@echo "$(BLUE) $$(grep "ERROR SUMMARY" $(VALGRIND_DIR)/$$(ls valgrind | tail -1))"
	@$(MAKE) clean

$(VALGRIND_DIR):
	$(MKDIR) $(VALGRIND_DIR)

.PHONY: last_valgrind
last_valgrind:
	@cat $(VALGRIND_DIR)$$(ls valgrind | tail -1)

.PHONY: clean_valgrind
clean_valgrind:
	$(RM) $(VALGRIND_DIR)

#MESSAGES

.PHONY: msg_mlx_start msg_mlx_end msg_clean_start msg_clean_end msg_fclean_start msg_fclean_end

msg_mlx_start:
	@echo "$(YELLOW)Starting MLX42 compilation$(RESET)"

msg_mlx_end:
	@echo "$(GREEN)MLX42 compilation complete$(RESET)"

msg_clean_start:
	@echo "$(YELLOW)Cleaning so_long objects$(RED)"

msg_clean_end:
	@echo "$(GREEN)So_long objects cleaned$(RESET)"

msg_fclean_start:
	@echo "$(YELLOW)Cleaning so_long$(RED)"

msg_fclean_end:
	@echo "$(GREEN)So_long cleaned$(RESET)"