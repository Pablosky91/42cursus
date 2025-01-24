# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/18 17:00:57 by pdel-olm          #+#    #+#              #
#    Updated: 2025/01/24 20:33:49 by pdel-olm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#GENERAL VARIABLES

MAKEFLAGS := --no-print-directory

RM := rm -rf
MKDIR := mkdir -p

NAME := pipex

LIBFT_PATH := ../../libft
LIBFT := $(LIBFT_PATH)/libft.a
LIBFT_FLAG := -L $(LIBFT_PATH) -l ft

CC := cc
CFLAGS := -g3 -Wall -Wextra -Werror -fsanitize=address

#FILES

SRC_DIR := src/
OBJ_DIR := obj/
HEADER := $(SRC_DIR)/$(NAME).h

SOURCES :=	\
			pipex.c

OBJECTS := $(addprefix $(OBJ_DIR), $(SOURCES:.c=.o))
SOURCES := $(addprefix $(SRC_DIR), $(SOURCES))

#COLOURS

RED := \033[31m
GREEN := \033[32m
YELLOW := \033[33m
BLUE := \033[34m

RESET := \033[0m

#EXTRA VARIABLES

ARG := infile "grep -e line" "tail -1" "wc -m" outfile

VALGRIND_DIR := valgrind/

#RULES

.PHONY: a all
a: all
all: $(NAME)

$(NAME): $(LIBFT) $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT_FLAG) -o $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADER) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I $(SRC_DIR) -I $(LIBFT_PATH) -c $< -o $@

$(OBJ_DIR):
	$(MKDIR) $(OBJ_DIR)

.PHONY: c clean
c: clean
clean: msg_clean_start
	$(RM) $(OBJ_DIR) $(BONUS_OBJ_DIR)
	@$(MAKE) -C $(LIBFT_PATH) clean
	@$(MAKE) msg_clean_end

.PHONY: f fclean
f: fclean
fclean: msg_fclean_start
	$(RM) $(OBJ_DIR) $(BONUS_OBJ_DIR) $(NAME) $(BONUS_NAME)
	@$(MAKE) -C $(LIBFT_PATH) fclean
	@$(MAKE) msg_fclean_end

.PHONY: r re
r: re
re: fclean all

#EXTRA RULES

.PHONY: e exec
e: exec
exec: all
	-./$(NAME) $(ARG)
	cat outfile

.PHONY: n norminette normi
n: norminette
norminette:
	@echo "norminette src src_bonus libft | grep Error\n"
	@if norminette src src_bonus libft | grep -q "Error"; then echo "$(RED)$$(norminette src_bonus src libft | grep "Error" | sed -z 's/\nError/\n\$(YELLOW)  Error/g' | sed -z 's/\n/\n\$(RED)/g')"; else echo "$(GREEN)Everything OK!$(RESET)"; fi
normi:
	@if norminette src src_bonus libft | grep -q "Error"; then echo "\n$(RED)$$(norminette src src_bonus libft | grep "Error" | grep -v -e "TOO_MANY_FUNCS" -e "WRONG_SCOPE_COMMENT" -e "EMPTY_LINE_FUNCTION" -e "LINE_TOO_LONG" -e "TOO_MANY_LINES" -e "CONSECUTIVE_NEWLINES" | sed -z 's/\nError/\n\$(YELLOW)  Error/g' | sed -z 's/\n/\n\$(RED)/g')"; else echo "$(GREEN)Run full norminette!$(RESET)"; fi

.PHONY: v valgrind valgrind_no_flags
v: valgrind
valgrind:
	@$(MAKE) CFLAGS="-g3 -Wall -Wextra -Werror" valgrind_no_flags
valgrind_no_flags: clean $(LIBFT) $(OBJECTS) | $(VALGRIND_DIR)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT_FLAG) -o $(NAME)
	-valgrind --track-fds=yes --leak-check=full --show-leak-kinds=all --log-file=$(VALGRIND_DIR)$$(date +"%y%m%d%H%M%S").txt ./$(NAME) $(ARG)
	@echo "$(BLUE) $$(grep -e "ERROR SUMMARY" -e "FILE DESCRIPTORS" $(VALGRIND_DIR)/$$(ls valgrind | tail -1))"
	@$(MAKE) clean
	cat outfile

$(VALGRIND_DIR):
	$(MKDIR) $(VALGRIND_DIR)

.PHONY: last_valgrind
last_valgrind:
	@cat $(VALGRIND_DIR)$$(ls valgrind | tail -1)

.PHONY: clean_valgrind
clean_valgrind:
	$(RM) $(VALGRIND_DIR)

#MESSAGES

.PHONY: msg_clean_start msg_clean_end msg_fclean_start msg_fclean_end

msg_clean_start:
	@echo "$(YELLOW)Cleaning pipex objects$(RED)"

msg_clean_end:
	@echo "$(GREEN)Pipex objects cleaned$(RESET)"

msg_fclean_start:
	@echo "$(YELLOW)Cleaning pipex$(RED)"

msg_fclean_end:
	@echo "$(GREEN)Pipex cleaned$(RESET)"