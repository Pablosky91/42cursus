#VARIABLES

NAME = libft.a

RM = rm -f

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3

AR = ar
AR_FLAGS = -r

SOURCES =		ft_atoi.c\
				ft_bzero.c\
				ft_calloc.c\
				ft_isalnum.c\
				ft_isalpha.c\
				ft_isascii.c\
				ft_isdigit.c\
				ft_isprint.c\
				ft_itoa.c\
				ft_memchr.c\
				ft_memcmp.c\
				ft_memcpy.c\
				ft_memmove.c\
				ft_memset.c\
				ft_putchar_fd.c\
				ft_putendl_fd.c\
				ft_putnbr_fd.c\
				ft_putstr_fd.c\
				ft_split.c\
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
				ft_strtrim.c\
				ft_substr.c\
				ft_tolower.c\
				ft_toupper.c

BONUS_SOURCES =	ft_lstadd_back_bonus.c\
				ft_lstadd_front_bonus.c\
				ft_lstclear_bonus.c\
				ft_lstdelone_bonus.c\
				ft_lstiter_bonus.c\
				ft_lstlast_bonus.c\
				ft_lstmap_bonus.c\
				ft_lstnew_bonus.c\
				ft_lstsize_bonus.c

OBJECTS = $(SOURCES:.c=.o)

BONUS_OBJECTS = $(BONUS_SOURCES:.c=.o)

BONUS = .bonus

#RULES

a: all
all: $(NAME)

$(NAME): $(OBJECTS)
	$(AR) $(AR_FLAGS) $(NAME) $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $^

c: clean
clean:
	$(RM) $(OBJECTS) $(BONUS_OBJECTS) $(BONUS)

f: fclean
fclean: clean
	$(RM) $(NAME)

re: fclean all

b: bonus
bonus: $(BONUS)
$(BONUS): $(BONUS_OBJECTS)
	touch $(BONUS)
	$(AR) $(AR_FLAGS) $(NAME) $(BONUS_OBJECTS)

l: library
library: all bonus clean

t:
	ar -t libft.a

.PHONY: all clean fclean re bonus library a b c f l t