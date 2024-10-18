#VARIABLES

NAME = test.out
OTHER_PATH = ..

RM = rm -f

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SOURCES = main.c
OBJECTS = $(SOURCES:.c=.o)

INCLUDE_PATH = $(OTHER_PATH)
C_INCLUDE = -I $(INCLUDE_PATH)

LIBRARY_PATH = $(OTHER_PATH)
LIBRARY_NAME = ftprintf
C_LIBRARY = -L $(LIBRARY_PATH) -l $(LIBRARY_NAME)

#RULES

all: $(NAME)

$(NAME): library $(OBJECTS)
	$(CC) $(OBJECTS) $(CFLAGS) $(C_INCLUDE) $(C_LIBRARY) -o $@

%.o: %.c
	$(CC) $(CFLAGS) $(C_INCLUDE) $(C_LIBRARY) -o $@ -c $^

clean:
	$(RM) $(OBJECTS)
	@$(MAKE) -C $(OTHER_PATH) clean

fclean: clean
	$(RM) $(NAME)
	@$(MAKE) -C $(OTHER_PATH) fclean

re: fclean all

library:
	@$(MAKE) -C $(OTHER_PATH) all

exec: all
	@clear
	@./$(NAME)

.PHONY: all clean fclean re library exec