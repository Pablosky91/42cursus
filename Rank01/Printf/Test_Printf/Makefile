#VARIABLES

NAME = test.out
OTHER_PATH = ..

RM = rm -f

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3

SOURCES = main.c
OBJECTS = $(SOURCES:.c=.o)

INCLUDE_PATH = $(OTHER_PATH)
C_INCLUDE = -I $(INCLUDE_PATH)

LIBRARY = ../libftprintf.a
LIBRARY_PATH = $(OTHER_PATH)
LIBRARY_NAME = ftprintf
C_LIBRARY = -L $(LIBRARY_PATH) -l $(LIBRARY_NAME)

#RULES

all: $(NAME)

$(NAME): $(LIBRARY) $(OBJECTS)
	$(CC) $(OBJECTS) $(CFLAGS) $(C_INCLUDE) $(C_LIBRARY) -o $@

%.o: %.c
	$(CC) $(CFLAGS) $(C_INCLUDE) -o $@ -c $^

clean:
	$(RM) $(OBJECTS)
	@$(MAKE) -C $(OTHER_PATH) clean

fclean: clean
	$(RM) $(NAME)
	@$(MAKE) -C $(OTHER_PATH) fclean

re: fclean all

$(LIBRARY):
	@$(MAKE) -C $(OTHER_PATH) all

exec: all
	@clear
	@./$(NAME)

.PHONY: all clean fclean re exec