# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/14 13:17:01 by pdel-olm          #+#    #+#              #
#    Updated: 2026/06/30 20:22:29 by pdel-olm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#GENERAL VARIABLES

MAKEFLAGS := --no-print-directory
.DEFAULT_GOAL := all

RM := rm -rf
MKDIR := mkdir -p

NAME := convert
NAME_CAPITAL := Convert

CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98 -fsanitize=address

#FILES

SRC_DIR := src/
OBJ_DIR := obj/
INC_DIR := include/

VPATH := $(SRC_DIR)

SOURCES :=	\
			main.cpp\
			ScalarConverter.cpp\

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
	@echo "$(RED)\nNO ARGUMENT\n$(RESET)"
	-./$(NAME)
	@echo "$(RED)\nINVALID ARGUMENT\n$(RESET)"
	./$(NAME) invalid
	@echo "$(BLUE)\nSPECIAL ARGUMENTS\n$(RESET)"
	./$(NAME) nanf
	@echo
	./$(NAME) +inff
	@echo
	./$(NAME) -inff
	@echo
	./$(NAME) nan
	@echo
	./$(NAME) +inf
	@echo
	./$(NAME) -inf
	@echo "$(GREEN)\nCHARACTER ARGUMENTS\n$(RESET)"
	./$(NAME) a
	@echo
	./$(NAME) "'a'"
	@echo
	./$(NAME) "'0'"
	@echo
	./$(NAME) " "
	@echo "$(GREEN)\nINTEGER ARGUMENTS\n$(RESET)"
	./$(NAME) 0
	@echo
	./$(NAME) 65
	@echo
	./$(NAME) +65
	@echo
	./$(NAME) -65
	@echo "$(GREEN)\nFLOAT ARGUMENTS\n$(RESET)"
	./$(NAME) 42.0f
	@echo
	./$(NAME) 42.42f
	@echo
	./$(NAME) +42.42f
	@echo
	./$(NAME) -42.42f
	@echo "$(GREEN)\nDOUBLE ARGUMENTS\n$(RESET)"
	./$(NAME) 42.0
	@echo
	./$(NAME) 42.42
	@echo
	./$(NAME) +42.42
	@echo
	./$(NAME) -42.42
	@echo

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
