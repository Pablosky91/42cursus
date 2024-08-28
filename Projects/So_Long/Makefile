# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/06 12:11:22 by pdel-olm          #+#    #+#              #
#    Updated: 2024/08/28 22:50:28 by pdel-olm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#GENERAL VARIABLES

MAKEFLAGS := --no-print-directory

RM := rm -rf
MKDIR := mkdir -p

NAME := so_long
BONUS_NAME := so_long_bonus

CC := gcc
CFLAGS := -g3 -fsanitize=address #-Wall -Wextra -Werror

#INCLUDE

LIBFT_PATH := ../../libft
LIBFT := $(LIBFT_PATH)/libft.a
LIBFT_FLAG := -L $(LIBFT_PATH) -l ft

MLX_PATH := MLX42
MLX_BUILD := $(MLX_PATH)/build
MLX_NAME := $(MLX_BUILD)/libmlx42.a
MLX_INCLUDE := $(MLX_PATH)/include/MLX42
MLX_FLAG := -L $(MLX_BUILD) -l mlx42 -l glfw


#FILES

SRC_DIR := src/
OBJ_DIR := obj/

SOURCES :=	\
			read_map.c\
			so_long.c\
			valid_path.c\

OBJECTS := $(addprefix $(OBJ_DIR), $(SOURCES:.c=.o))
SOURCES := $(addprefix $(SRC_DIR), $(SOURCES))

#BONUS FILES

BONUS_SRC_DIR := $(SRC_DIR)bonus/
BONUS_OBJ_DIR := $(OBJ_DIR)bonus/

BONUS_SOURCES := \

BONUS_REGULAR_SOURCES := \

BONUS_OBJECTS := $(addprefix $(BONUS_OBJ_DIR), $(BONUS_SOURCES:.c=.o))
BONUS_SOURCES := $(addprefix $(BONUS_SRC_DIR), $(BONUS_SOURCES))

BONUS_REGULAR_OBJECTS := $(addprefix $(OBJ_DIR), $(BONUS_REGULAR_SOURCES:.c=.o))
BONUS_REGULAR_SOURCES := $(addprefix $(SRC_DIR), $(BONUS_REGULAR_SOURCES))

BONUS_OBJECTS += $(BONUS_REGULAR_OBJECTS)
BONUS_SOURCES += $(BONUS_REGULAR_SOURCES)

#COLOURS

RED := \033[31m
GREEN := \033[32m
YELLOW := \033[33m
BLUE := \033[34m

RESET := \033[0m

#EXTRA VARIABLES

MAP := maps/valid_medium.ber

OUT := out

VALGRIND_DIR := valgrind/

#RULES

a: all
all: $(NAME)

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
	$(CC) $(CFLAGS) -c $^ $(LIBFT_FLAG) -I $(LIBFT_PATH) -I $(MLX_INCLUDE) -o $@

$(OBJ_DIR):
	$(MKDIR) $(OBJ_DIR)

c: clean
clean: msg_clean_start
	$(RM) $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_PATH) clean
	@$(MAKE) msg_clean_end

f: fclean
fclean: msg_fclean_start
	$(RM) $(OBJ_DIR) $(MLX_BUILD) $(NAME) $(BONUS_NAME)
	@$(MAKE) -C $(LIBFT_PATH) fclean
	@$(MAKE) msg_fclean_end

r: re
re: fclean all

#BONUS RULES

b:bonus
bonus: $(BONUS_NAME)

$(BONUS_NAME): $(LIBFT) $(BONUS_OBJECTS)
	$(CC) $(CFLAGS) $(BONUS_OBJECTS) $(LIBFT_FLAG) -o $(BONUS_NAME)

$(BONUS_OBJ_DIR)%.o: $(BONUS_SRC_DIR)%.c | $(BONUS_OBJ_DIR)
	$(CC) $(CFLAGS) -c $^ $(LIBFT_FLAG) -I $(LIBFT_PATH) -o $@

$(BONUS_OBJ_DIR):
	$(MKDIR) $(BONUS_OBJ_DIR)

#EXTRA RULES

reb: fclean bonus

be: bonus
	@./$(BONUS_NAME) $(ARG)

e: exec
exec: all
	@clear
	@-./$(NAME) $(MAP)

n: norminette
norminette:
	@echo "norminette src libft | grep Error\n"
	@if norminette src libft | grep -q "Error"; then echo "$(RED)$$(norminette src libft | grep "Error" | sed -z 's/\nError/\n\$(YELLOW)  Error/g' | sed -z 's/\n/\n\$(RED)/g')"; else echo "$(GREEN)Everything OK!$(RESET)"; fi
normi:
	@if norminette src libft | grep -q "Error"; then echo "\n$(RED)$$(norminette src libft | grep "Error" | grep -v -e "TOO_MANY_FUNCS" -e "WRONG_SCOPE_COMMENT" -e "EMPTY_LINE_FUNCTION" -e "LINE_TOO_LONG" -e "TOO_MANY_LINES" -e "CONSECUTIVE_NEWLINES" | sed -z 's/\nError/\n\$(YELLOW)  Error/g' | sed -z 's/\n/\n\$(RED)/g')"; else echo "$(GREEN)Run full norminette!$(RESET)"; fi

#until there's something better: make v CFLAGS=
v: valgrind
valgrind: fclean $(LIBFT) $(MLX_NAME) $(OBJECTS) | $(VALGRIND_DIR)
	@$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT_FLAG) $(MLX_FLAG) -o $(NAME)
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=$(VALGRIND_DIR)$$(date +"%y%m%d%H%M%S").txt ././$(NAME) $(ARG)
	@echo "$(BLUE) $$(grep "ERROR SUMMARY" $(VALGRIND_DIR)/$$(ls valgrind | tail -1))"
	@$(MAKE) fclean

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