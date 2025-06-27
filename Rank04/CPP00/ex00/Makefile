# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/27 13:02:42 by pdel-olm          #+#    #+#              #
#    Updated: 2025/06/27 16:14:33 by pdel-olm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#GENERAL VARIABLES

MAKEFLAGS := --no-print-directory
.DEFAULT_GOAL := all

RM := rm -rf

NAME := megaphone
NAME_CAPITAL := Megaphone

CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98

#FILES

SOURCES :=	\
			megaphone.cpp\

OBJECTS := $(SOURCES:.cpp=.o)

#COLOURS

RED := \033[31m
GREEN := \033[32m
YELLOW := \033[33m
BLUE := \033[34m

RESET := \033[0m

#RULES

.PHONY: a all
all: $(NAME)
a: all

$(NAME): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: c clean
c: clean
clean: msg_clean_start
	$(RM) $(OBJECTS)
	@$(MAKE) msg_clean_end

.PHONY: f fclean
f: fclean
fclean: msg_fclean_start
	$(RM) $(OBJECTS) $(NAME)
	@$(MAKE) msg_fclean_end

.PHONY: r re
r: re
re: fclean all

#EXTRA RULES

.PHONY: e exec
e: exec
exec: all
	-./$(NAME) "shhhhh... I think the students are asleep..."
	-./$(NAME) Damnit " ! " "Sorry students, I thought this thing was off."
	-./$(NAME)

#MESSAGES

.PHONY: msg_clean_start msg_clean_end msg_fclean_start msg_fclean_end

msg_clean_start:
	@echo "$(YELLOW)Cleaning $(NAME) objects$(RED)"

msg_clean_end:
	@echo "$(GREEN)$(NAME_CAPITAL) objects cleaned$(RESET)"

msg_fclean_start:
	@echo "$(YELLOW)Cleaning $(NAME)$(RED)"

msg_fclean_end:
	@echo "$(GREEN)$(NAME_CAPITAL) cleaned$(RESET)"