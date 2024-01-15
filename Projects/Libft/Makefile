#VARIABLES

NAME = libft.a

RM = rm -f

SOURCES =	ft_isalnum.c\
			ft_isalpha.c\
			ft_isascii.c\
			ft_isdigit.c\
			ft_isprint.c\
			ft_strlen.c\
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

.PHONY = all clean fclean re library