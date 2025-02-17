# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/02 16:43:04 by pdel-olm          #+#    #+#              #
#    Updated: 2025/02/17 16:24:50 by pdel-olm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#COLOURS

RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[36m

ITALIC = \033[3m

RESET = \033[0m

#VARIABLES

NAME = libft.a

RM = rm -rf

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3

AR = ar
AR_FLAGS = -rc

SOURCES =	\
			$(addprefix extra/,\
				ft_count_char.c\
				ft_dtoa.c\
				ft_free_double_pointer.c\
				ft_get_max.c\
				ft_get_min.c\
				ft_str_equals.c)\
			$(addprefix original/is/,\
				ft_isalnum.c\
				ft_isalpha.c\
				ft_isascii.c\
				ft_isdigit.c\
				ft_isprint.c)\
			$(addprefix original/lst/,\
				ft_lstadd_back.c\
				ft_lstadd_front.c\
				ft_lstclear.c\
				ft_lstdelone.c\
				ft_lstiter.c\
				ft_lstlast.c\
				ft_lstmap.c\
				ft_lstnew.c\
				ft_lstsize.c)\
			$(addprefix original/mem/,\
				ft_memchr.c\
				ft_memcmp.c\
				ft_memcpy.c\
				ft_memmove.c\
				ft_memset.c)\
			$(addprefix original/other/,\
				ft_atoi.c\
				ft_bzero.c\
				ft_calloc.c\
				ft_get_next_line.c\
				ft_itoa.c\
				ft_split.c\
				ft_substr.c\
				ft_tolower.c\
				ft_toupper.c)\
			$(addprefix original/put/,\
				ft_putchar_fd.c\
				ft_putendl_fd.c\
				ft_putnbr_fd.c\
				ft_putstr_fd.c)\
			$(addprefix original/str/,\
				ft_strchr.c\
				ft_strdup.c\
				ft_striteri.c\
				ft_strjoin.c\
				ft_strlcat.c\
				ft_strlcpy.c\
				ft_strlen.c\
				ft_strmapi.c\
				ft_strncmp.c\
				ft_strnstr.c\
				ft_strrchr.c\
				ft_strtrim.c)\
			$(addprefix printf/,\
				ft_printf_fd.c\
				ft_printf.c\
				pf_print_char.c\
				pf_print_flag.c\
				pf_print_hexadecimal.c\
				pf_print_int.c\
				pf_print_pointer.c\
				pf_print_string.c\
				pf_print_unsigned_int.c\
				pf_print.c\
				)

OBJ_DIR = obj/
ALL_OBJ_DIR = $(addprefix $(OBJ_DIR), extra original/is original/lst original/mem original/other original/put original/str printf)
OBJECTS = $(addprefix $(OBJ_DIR), $(SOURCES:.c=.o))

MAKEFLAGS = --no-print-directory

#RULES

all: $(NAME)

$(NAME): msg_all_start $(OBJECTS)
	@$(MAKE) tab
	$(AR) $(AR_FLAGS) $(NAME) $(OBJECTS)
	@$(MAKE) msg_all_end

$(OBJ_DIR)%.o: %.c | $(OBJ_DIR)
	@$(MAKE) tab
	$(CC) $(CFLAGS) -c $^ -I . -o $@

$(OBJ_DIR):
	@$(MAKE) tab
	mkdir -p $(ALL_OBJ_DIR)

clean: msg_clean_start
	@$(MAKE) tab
	$(RM) $(OBJ_DIR)
	@$(MAKE) msg_clean_end

fclean: msg_fclean_start
	@$(MAKE) tab
	$(RM) $(OBJ_DIR) $(NAME)
	@$(MAKE) msg_fclean_end

re: fclean all

#MESSAGES

tab:
	@echo -n "  "

msg_all_start: tab
	@echo "$(YELLOW)$(ITALIC)Starting library compilation$(BLUE)"

msg_all_end: tab
	@echo "$(GREEN)Library compilation complete$(RESET)"

msg_clean_start: tab
	@echo "$(YELLOW)$(ITALIC)Cleaning library objects$(RED)"

msg_clean_end: tab
	@echo "$(GREEN)Library objects cleaned$(RESET)"

msg_fclean_start: tab
	@echo "$(YELLOW)$(ITALIC)Cleaning library$(RED)"

msg_fclean_end: tab
	@echo "$(GREEN)Library cleaned$(RESET)"

#PHONY

.PHONY: all clean fclean re tab msg_all_start msg_all_end msg_clean_start msg_clean_end msg_fclean_start msg_fclean_end