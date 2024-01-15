#VARIABLES

NAME = test.out

RM = rm -f

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SOURCES = main.c
OBJECTS = $(SOURCES:.c=.o)

INCLUDE_PATH = ..
C_INCLUDE = -I $(INCLUDE_PATH)

LIBRARY_PATH = ..
LIBRARY_NAME = ft
C_LIBRARY = -L $(LIBRARY_PATH) -l $(LIBRARY_NAME)

#RULES

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(C_INCLUDE) $(C_LIBRARY) -o $@ $^ 

%.o: %.c
	$(CC) $(CFLAGS) $(C_INCLUDE) -c -o $@ $^

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

exec: all
	@clear
	@./$(NAME)

.PHONY = all clean fclean re exec