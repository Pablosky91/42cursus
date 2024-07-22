# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/06 12:11:22 by pdel-olm          #+#    #+#              #
#    Updated: 2024/07/22 20:56:56 by pdel-olm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#COLOURS

RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m

RESET = \033[0m

#VARIABLES

NAME = push_swap

LIBFT_PATH = libft
LIBFT = $(LIBFT_PATH)/libft.a
LIBFT_FLAG = -L $(LIBFT_PATH) -l ft

RM = rm -rf
OUT = out

CC = gcc
CFLAGS = -g3 -Wall -Wextra -Werror -fsanitize=address

SRC_DIR = src/
SOURCES =	algorithm.c\
			base_cases.c\
			cut_moves.c\
			execute_move.c\
			get_node.c\
			instructions.c\
			parse.c\
			push_swap.c\
			simplify.c\
			sort_few.c

OBJ_DIR = obj/
OBJECTS := $(addprefix $(OBJ_DIR), $(SOURCES:.c=.o))

SOURCES := $(addprefix $(SRC_DIR), $(SOURCES))

MAKEFLAGS = --no-print-directory


ARG = 99 98 97 96 95 94 93 92 91 90 89 88 87 86 85 84 83 82 81 80 79 78 77 76 75 74 73 72 71 70 69 68 67 66 65 64 63 62 61 60 59 58 57 56 55 54 53 52 51 50 49 48 47 46 45 44 43 42 41 40 39 38 37 36 35 34 33 32 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0
N = 3
REPEAT = 10

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
	mkdir $(OBJ_DIR)

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

o: once
once: all
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
#l: leaks
#leaks: all
#	@clear
#	valgrind --leak-check=full ./$(NAME) 1 3 2

n: norminette
norminette:
	@echo "norminette | grep Error"
	@if norminette | grep -q "Error"; then echo "\n$(RED)$$(norminette | grep "Error" | sed -z 's/\nError/\n\$(YELLOW)  Error/g' | sed -z 's/\n/\n\$(RED)/g')"; else echo "$(GREEN)Everything OK!$(RESET)"; fi

#MESSAGES

msg_clean_start:
	@echo "$(YELLOW)Cleaning push_swap objects$(RED)"

msg_clean_end:
	@echo "$(GREEN)Push_swap objects cleaned$(RESET)"

msg_fclean_start:
	@echo "$(YELLOW)Cleaning push_swap$(RED)"

msg_fclean_end:
	@echo "$(GREEN)Push_swap cleaned$(RESET)"

.PHONY: all clean fclean re once exec loop norminette a c f r o e l n msg_clean_start msg_clean_end msg_fclean_start msg_fclean_end