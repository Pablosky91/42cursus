# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/18 16:39:30 by pdel-olm          #+#    #+#              #
#    Updated: 2025/04/18 19:11:16 by pdel-olm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#GENERAL VARIABLES

MAKEFLAGS := --no-print-directory

RM := rm -rf
MKDIR := mkdir -p

NAME := philo

CC := cc
CFLAGS := -Wall -Wextra -Werror -g3

#FILES

SRC_DIR := src/
OBJ_DIR := obj/
INC_DIR := include/
HEADER := $(INC_DIR)/$(NAME).h

SOURCES :=	\
			philo.c\

OBJECTS := $(addprefix $(OBJ_DIR), $(SOURCES:.c=.o))
SOURCES := $(addprefix $(SRC_DIR), $(SOURCES))

#COLOURS

RED := \033[31m
GREEN := \033[32m
YELLOW := \033[33m
BLUE := \033[34m

RESET := \033[0m

#EXTRA VARIABLES

ARG = 4 40 10 5

VALGRIND_DIR := valgrind/

#RULES

.PHONY: a all
a: all
all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADER) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

$(OBJ_DIR):
	$(MKDIR) $(OBJ_DIR)

.PHONY: c clean
c: clean
clean: msg_clean_start
	$(RM) $(OBJ_DIR)
	@$(MAKE) msg_clean_end

.PHONY: f fclean
f: fclean
fclean: msg_fclean_start
	$(RM) $(OBJ_DIR) $(NAME)
	@$(MAKE) msg_fclean_end

.PHONY: r re
r: re
re: fclean all

#EXTRA RULES

.PHONY: e exec
e: exec
exec: all
	-./$(NAME) $(ARG)

.PHONY: n norminette normi
n: norminette
norminette:
	@echo "norminette src | grep Error\n"
	@if norminette src | grep -q "Error"; then echo "$(RED)$$(norminette src | grep "Error" | sed -z 's/\nError/\n\$(YELLOW)  Error/g' | sed -z 's/\n/\n\$(RED)/g')$(RESET)"; else echo "$(GREEN)Everything OK!$(RESET)"; fi
normi:
	@if norminette src | grep -q "Error"; then echo "\n$(RED)$$(norminette src | grep "Error" | grep -v -e "TOO_MANY_FUNCS" -e "WRONG_SCOPE_COMMENT" -e "EMPTY_LINE_FUNCTION" -e "LINE_TOO_LONG" -e "TOO_MANY_LINES" -e "CONSECUTIVE_NEWLINES" | sed -z 's/\nError/\n\$(YELLOW)  Error/g' | sed -z 's/\n/\n\$(RED)/g')$(RESET)"; else echo "$(GREEN)Run full norminette!$(RESET)"; fi

.PHONY: v valgrind valgrind_no_flags
v: valgrind
valgrind:
	@$(MAKE) CFLAGS="-g3 -Wall -Wextra -Werror" valgrind_no_flags
valgrind_no_flags: clean $(OBJECTS) | $(VALGRIND_DIR)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)
	-valgrind -s --trace-children=yes --track-fds=yes --leak-check=full --show-leak-kinds=all --log-file=$(VALGRIND_DIR)$$(date +"%y%m%d%H%M%S").txt ./$(NAME) $(ARG)
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
	@echo "$(YELLOW)Cleaning philo objects$(RED)"

msg_clean_end:
	@echo "$(GREEN)Philo objects cleaned$(RESET)"

msg_fclean_start:
	@echo "$(YELLOW)Cleaning philo$(RED)"

msg_fclean_end:
	@echo "$(GREEN)Philo cleaned$(RESET)"