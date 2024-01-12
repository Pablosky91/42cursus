#VARIABLES

NAME = libft.a

CC = cc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

SOURCES = $(wildcard *.c)

OBJECTS = $(SOURCES:.c=.o)

#RULES

all: $(NAME)

$(NAME): $(OBJECTS)
	ar -cr $(NAME) $(OBJECTS)

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

exec: all
	@clear
	@./$(NAME)