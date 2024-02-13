#VARIABLES

NAME = test.out

RM = rm -f

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SOURCES = main.c
OBJECTS = $(SOURCES:.c=.o)

INCLUDE_PATH = ../Libft
C_INCLUDE = -I $(INCLUDE_PATH)

LIBRARY_PATH = ../Libft
LIBRARY_NAME = ft
C_LIBRARY = -L $(LIBRARY_PATH) -l $(LIBRARY_NAME)

#RULES

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(C_INCLUDE) $(C_LIBRARY) -o $@ $^ 

%.o: %.c
	$(CC) $(CFLAGS) $(C_INCLUDE) -o $@ -c $^

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

library:
	@$(MAKE) -C ../Libft library

exec: all
	@clear
	@./$(NAME)
	@$(MAKE) -s fclean

.PHONY = all clean fclean re library exec