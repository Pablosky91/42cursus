# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/02 16:43:04 by pdel-olm          #+#    #+#              #
#    Updated: 2024/05/02 21:43:59 by pdel-olm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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

$(NAME): $(OBJECTS)
	$(AR) $(AR_FLAGS) $(NAME) $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -I . -o $@ -c $^

c: clean
clean:
	$(RM) $(OBJECTS)

f: fclean
fclean: clean
	$(RM) $(NAME)

re: fclean all

l: library
library: all clean

t:
	ar -t $(NAME)

.PHONY: all clean fclean re library a c f l t