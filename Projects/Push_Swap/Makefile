# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/06 12:11:22 by pdel-olm          #+#    #+#              #
#    Updated: 2024/06/18 18:57:09 by pdel-olm         ###   ########.fr        #
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
CFLAGS = #-Wall -Wextra -Werror -g3 -fsanitize=address

SOURCES =	push_swap.c\
			algorithm.c\
			parse.c\
			movements.c

OBJ_DIR = obj/
OBJECTS = $(addprefix $(OBJ_DIR), $(SOURCES:.c=.o))

MAKEFLAGS = --no-print-directory

#AB
#CD

#A->B:2 mid
#A->C:1 high
#A->D:3 low

#B->A:4 high
#B->C:5 mid
#B->D:6 low

#D->B:7
#C->A:8

ARG = 17 14 3 2 16 4 20 9 27 23 8 24 15 11 21 22 10 7 18 19 12 1 26 13 5 25 6
N = 3
REPEAT = 10

#RULES

a: all
all: $(NAME)

$(NAME): $(LIBFT) $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT_FLAG) -o $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH)

$(OBJ_DIR)%.o: %.c | $(OBJ_DIR)
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

e: exec
exec: all
	@clear
	@-./$(NAME) $(ARG) > $(OUT)
	@cat $(OUT)
	@echo "$(YELLOW)$$(cat $(OUT) | wc -l) move/s$(RESET)"
	@echo "(Change arguments with ARG)"
	@$(RM) $(OUT)
#	@echo "-------"
#	@./$(NAME) 1 2 3
#	@echo "-------"
#	@./$(NAME) 1 3 2
#	@echo "-------"
#	@./$(NAME) 2 1 3
#	@echo "-------"
#	@./$(NAME) 2 3 1
#	@echo "-------"
#	@./$(NAME) 3 1 2
#	@echo "-------"
#	@./$(NAME) 3 2 1
#	@echo "-------"

l: loop
loop: all
	@clear
	@for i in $$(seq $(REPEAT)); do ./$(NAME) $$(seq 1000 | sort -R | tail -$(N)) | wc -l >> $(OUT); done
	@echo "$(YELLOW)Max: $$(sort $(OUT) | tail -1) move/s$(RESET)"
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

.PHONY: all clean fclean re exec loop norminette a c f r e l n msg_clean_start msg_clean_end msg_fclean_start msg_fclean_end