# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/30 22:20:27 by pdel-olm          #+#    #+#              #
#    Updated: 2026/01/30 22:20:28 by pdel-olm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#GENERAL VARIABLES

MAKEFLAGS := --no-print-directory
.DEFAULT_GOAL := all

RM := rm -rf
MKDIR := mkdir -p

NAME := scavTrap
NAME_CAPITAL := ScavTrap

CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98 -fsanitize=address

#FILES

SRC_DIR := src/
OBJ_DIR := obj/
INC_DIR := include/

VPATH :=  $(SRC_DIR)

SOURCES :=	\
			main.cpp\
			ClapTrap.cpp\
			ScavTrap.cpp\

OBJECTS := $(addprefix $(OBJ_DIR), $(SOURCES:.cpp=.o))

#COLOURS

RED := \033[31m
GREEN := \033[32m
YELLOW := \033[33m
BLUE := \033[34m

RESET := \033[0m

#RULES

$(NAME): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(NAME)

$(OBJ_DIR)%.o: %.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -I $(INC_DIR) -c $< -o $@

$(OBJ_DIR):
	$(MKDIR) $(OBJ_DIR)

.PHONY: a all
a: all
all: $(NAME)

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
