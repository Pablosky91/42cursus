#VARIABLES

NAME = test.out


RM = rm -f

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3

SOURCES = main.c
OBJECTS = $(SOURCES:.c=.o)

INCLUDE_PATH = ..
C_INCLUDE = -I $(INCLUDE_PATH)

LIBRARY = ../libft.a
LIBRARY_PATH = ..
LIBRARY_NAME = ft
C_LIBRARY = -L $(LIBRARY_PATH) -l $(LIBRARY_NAME)

#RULES

all: $(NAME)

$(NAME): $(LIBRARY) $(OBJECTS)
	$(CC) $(OBJECTS) $(CFLAGS) $(C_INCLUDE) $(C_LIBRARY) -o $@

%.o: %.c
	$(CC) $(CFLAGS) $(C_INCLUDE) -o $@ -c $^

clean:
	$(RM) $(OBJECTS)
	@$(MAKE) -C $(LIBRARY_PATH) clean

fclean: clean
	$(RM) $(NAME)
	@$(MAKE) -C $(LIBRARY_PATH) fclean

re: fclean all

$(LIBRARY):
	@$(MAKE) -C $(LIBRARY_PATH) library

exec: all
	@clear
	@./$(NAME)

.PHONY: all clean fclean re exec