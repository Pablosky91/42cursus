# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/06 12:11:22 by pdel-olm          #+#    #+#              #
#    Updated: 2024/07/29 11:32:17 by pdel-olm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#GENERAL VARIABLES

MAKEFLAGS := --no-print-directory

RM := rm -rf
MKDIR := mkdir -p

NAME := push_swap
BONUS_NAME := checker

LIBFT_PATH := libft
LIBFT := $(LIBFT_PATH)/libft.a
LIBFT_FLAG := -L $(LIBFT_PATH) -l ft

CC := gcc
CFLAGS := -g3 -Wall -Wextra -Werror -fsanitize=address

#FILES

SRC_DIR := src/
OBJ_DIR := obj/

SOURCES :=	\
			algorithm.c\
			base_cases.c\
			cut_moves.c\
			error.c\
			execute_move.c\
			get_node.c\
			instructions.c\
			parse.c\
			push_swap.c\
			simplify.c\
			sort_few.c\

OBJECTS := $(addprefix $(OBJ_DIR), $(SOURCES:.c=.o))
SOURCES := $(addprefix $(SRC_DIR), $(SOURCES))

#BONUS FILES

BONUS_SRC_DIR := $(SRC_DIR)bonus/
BONUS_OBJ_DIR := $(OBJ_DIR)bonus/

BONUS_SOURCES := \
				checker.c\

BONUS_REGULAR_SOURCES := \
				execute_move.c\

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

OUT := out

VALGRIND_DIR := valgrind/

ARG := 99 98 97 96 95 94 93 92 91 90 89 88 87 86 85 84 83 82 81 80 79 78 77 76 75 74 73 72 71 70 69 68 67 66 65 64 63 62 61 60 59 58 57 56 55 54 53 52 51 50 49 48 47 46 45 44 43 42 41 40 39 38 37 36 35 34 33 32 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0
N := 3
REPEAT := 10

#RULES

a: all
all: $(NAME)

$(NAME): $(LIBFT) $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT_FLAG) -o $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $^ $(LIBFT_FLAG) -I $(LIBFT_PATH) -o $@

$(OBJ_DIR):
	$(MKDIR) $(OBJ_DIR)

c: clean
clean: msg_clean_start
	$(RM) $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_PATH) clean
	@$(MAKE) msg_clean_end

f: fclean
fclean: msg_fclean_start
	$(RM) $(OBJ_DIR) $(NAME)
	@$(MAKE) -C $(LIBFT_PATH) fclean
	@$(MAKE) msg_fclean_end

r: re
re: fclean all

#BONUS RULES

b:bonus
bonus: $(BONUS_NAME)

$(BONUS_NAME): $(LIBFT) $(BONUS_OBJECTS)
	echo $(BONUS_OBJECTS)
	$(CC) $(CFLAGS) $(BONUS_OBJECTS) $(LIBFT_FLAG) -o $(BONUS_NAME)

$(BONUS_OBJ_DIR)%.o: $(BONUS_SRC_DIR)%.c | $(BONUS_OBJ_DIR)
	$(CC) $(CFLAGS) -c $^ $(LIBFT_FLAG) -I $(LIBFT_PATH) -o $@

$(BONUS_OBJ_DIR):
	$(MKDIR) $(BONUS_OBJ_DIR)

#EXTRA RULES

reb: fclean bonus

be: bonus
	@./$(BONUS_NAME)

o: once
once: all
	@clear
	@./$(NAME) $$(seq $(N) | sort -R)

e: exec
exec: all
	@clear
	@-./$(NAME) $(ARG) > $(OUT)
	@cat $(OUT)
	@echo "$(YELLOW)$$(cat $(OUT) | wc -l) move/s$(RESET)"
	@echo "(Change arguments with ARG)"
	@$(RM) $(OUT)

l: loop
loop: all
	@clear
	@for i in $$(seq $(REPEAT)); do ./$(NAME) $$(seq $(N) | sort -R) | wc -l >> $(OUT); done
	@echo "$(YELLOW)Max: $$(sort -n $(OUT) | tail -1) move/s$(RESET)"
	@echo "Test in $(REPEAT) tries with $(N) random numbers"
	@echo "(Change times looped with REPEAT)"
	@echo "(Change number of arguments with N)"
	@$(RM) $(OUT)

n: norminette
norminette:
	@echo "norminette | grep Error\n"
	@if norminette | grep -q "Error"; then echo "$(RED)$$(norminette | grep "Error" | sed -z 's/\nError/\n\$(YELLOW)  Error/g' | sed -z 's/\n/\n\$(RED)/g')"; else echo "$(GREEN)Everything OK!$(RESET)"; fi
normi:
	@if norminette | grep -q "Error"; then echo "\n$(RED)$$(norminette | grep "Error" | grep -v -e "TOO_MANY_FUNCS" -e "WRONG_SCOPE_COMMENT" -e "EMPTY_LINE_FUNCTION" -e "LINE_TOO_LONG" -e "TOO_MANY_LINES" -e "CONSECUTIVE_NEWLINES" | sed -z 's/\nError/\n\$(YELLOW)  Error/g' | sed -z 's/\n/\n\$(RED)/g')"; else echo "$(GREEN)Run full norminette!$(RESET)"; fi

#until there's something better: make v CFLAGS=
v: valgrind
valgrind: fclean $(LIBFT) $(OBJECTS) | $(VALGRIND_DIR)
	@$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT_FLAG) -o $(NAME)
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

msg_clean_start:
	@echo "$(YELLOW)Cleaning push_swap objects$(RED)"

msg_clean_end:
	@echo "$(GREEN)Push_swap objects cleaned$(RESET)"

msg_fclean_start:
	@echo "$(YELLOW)Cleaning push_swap$(RED)"

msg_fclean_end:
	@echo "$(GREEN)Push_swap cleaned$(RESET)"

#PHONY

.PHONY: all clean fclean re bonus be reb once exec loop norminette normi valgrind last_valgrind clean_valgrind a c f r b o e l n v msg_clean_start msg_clean_end msg_fclean_start msg_fclean_end