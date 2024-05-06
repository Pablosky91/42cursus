# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/02 16:43:04 by pdel-olm          #+#    #+#              #
#    Updated: 2024/05/06 11:56:00 by pdel-olm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#COLOURS

RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m

RESET = \033[0m

#VARIABLES

NAME = libft.a

RM = rm -f

CC = gcc
CFLAGS = -Wall -Wextra -Werror

AR = ar
AR_FLAGS = -r

SOURCES =	$(addprefix gnl/,\
				get_next_line_utils.c\
				get_next_line.c)\
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
				ft_print_char.c\
				ft_print_flag.c\
				ft_print_hexadecimal.c\
				ft_print_int.c\
				ft_print_pointer.c\
				ft_print_string.c\
				ft_print_unsigned_int.c\
				ft_print.c\
				ft_printf.c)

OBJECTS = $(SOURCES:.c=.o)

#RULES

a: all
all: $(NAME)

$(NAME): msg_all_start $(OBJECTS) 
	$(AR) $(AR_FLAGS) $(NAME) $(OBJECTS)
	@$(MAKE) -s msg_all_end

%.o: %.c
	$(CC) $(CFLAGS) -I . -o $@ -c $^

c: clean
clean: msg_clean_start
	$(RM) $(OBJECTS)
	@$(MAKE) -s msg_clean_end

f: fclean
fclean: msg_fclean_start clean
	$(RM) $(NAME)
	@$(MAKE) -s msg_fclean_end

re: fclean all

l: library
library: all clean

t:
	ar -t $(NAME)

.PHONY: all clean fclean re library a c f l t
#MESSAGES

msg_all_start:
	@echo "$(YELLOW)Starting library compilation$(RESET)"

msg_all_end:
	@echo "$(GREEN)Library compilation complete$(RESET)"

msg_clean_start:
	@echo "$(YELLOW)Cleaning library objects$(RESET)"

msg_clean_end:
	@echo "$(GREEN)Library objects cleaned$(RESET)"

msg_fclean_start:
	@echo "$(YELLOW)Cleaning library$(RESET)"

msg_fclean_end:
	@echo "$(GREEN)Library cleaned$(RESET)"