#VARIABLES

NAME = libft.a

RM = rm -f

SOURCES =	ft_bzero.c\
			ft_isalpha.c\
			ft_isalnum.c\
			ft_isascii.c\
			ft_isdigit.c\
			ft_isprint.c\
			ft_memcpy.c\
			ft_memset.c\
			ft_memmove.c\
			ft_strchr.c\
			ft_strlcpy.c\
			ft_strlcat.c\
			ft_strlen.c\
			ft_strrchr.c\
			ft_tolower.c\
			ft_toupper.c\

OBJECTS = $(SOURCES:.c=.o)

#RULES

all: $(NAME)

$(NAME): $(OBJECTS)
	ar -rcs $(NAME) $(OBJECTS)

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

library: all clean

exec: library
	$(MAKE) -s -C ../Test_Libft exec fclean

.PHONY = all clean fclean re library exec