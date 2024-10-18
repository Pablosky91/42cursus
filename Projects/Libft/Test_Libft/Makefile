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

$(NAME): library $(OBJECTS)
	$(CC) $(OBJECTS) $(CFLAGS) $(C_INCLUDE) $(C_LIBRARY) -o $@

%.o: %.c
	$(CC) $(CFLAGS) $(C_INCLUDE) $(C_LIBRARY) -o $@ -c $^

clean:
	$(RM) $(OBJECTS)
	@$(MAKE) -C $(LIBRARY_PATH) clean

fclean: clean
	$(RM) $(NAME)
	@$(MAKE) -C $(LIBRARY_PATH) fclean

re: fclean all

library:
	@$(MAKE) -C $(LIBRARY_PATH) library

exec: all
	@clear
	@./$(NAME)

.PHONY: all clean fclean re library exec