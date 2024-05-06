# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/06 12:11:22 by pdel-olm          #+#    #+#              #
#    Updated: 2024/05/06 15:55:58 by pdel-olm         ###   ########.fr        #
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

RM = rm -f

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SOURCES =	push_swap.c

OBJECTS = $(SOURCES:.c=.o)

MAKEFLAGS = --no-print-directory

#RULES

a: all
all: $(NAME)

$(NAME): msg_all_start $(LIBFT) $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT_FLAG) -o $(NAME)
	@$(MAKE) msg_all_end

$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ $(LIBFT_FLAG) -I $(LIBFT_PATH) -o $@

c: clean
clean: msg_clean_start
	$(RM) $(OBJECTS)
	@$(MAKE) -C $(LIBFT_PATH) clean
	@$(MAKE) msg_clean_end

f: fclean
fclean: msg_fclean_start
	$(RM) $(OBJECTS) $(NAME)
	@$(MAKE) -C $(LIBFT_PATH) fclean
	@$(MAKE) msg_fclean_end

re: fclean all

l: library
library:
	@$(MAKE) -C $(LIBFT_PATH) library

e: exec
exec: all
#	@clear
	@./$(NAME)

.PHONY: all clean fclean re library a c f l t

#MESSAGES

msg_all_start:
	@echo "$(YELLOW)Starting push_swap compilation$(RESET)"

msg_all_end:
	@echo "$(GREEN)Push_swap compilation complete$(RESET)"

msg_clean_start:
	@echo "$(YELLOW)Cleaning push_swap objects$(RED)"

msg_clean_end:
	@echo "$(GREEN)Push_swap objects cleaned$(RESET)"

msg_fclean_start:
	@echo "$(YELLOW)Cleaning push_swap$(RED)"

msg_fclean_end:
	@echo "$(GREEN)Push_swap cleaned$(RESET)"