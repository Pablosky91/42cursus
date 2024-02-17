#VARIABLES

NAME = test.out
OTHER_PATH = ../Printf

RM = rm -f

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SOURCES = main.c
OBJECTS = $(SOURCES:.c=.o)

INCLUDE_PATH = $(OTHER_PATH)/libft
C_INCLUDE = -I $(INCLUDE_PATH)

LIBRARY_PATH = $(OTHER_PATH)
LIBRARY_NAME = ftprintf
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
	@$(MAKE) -C $(OTHER_PATH) all

exec: library all
	@clear
	@./$(NAME)
	@$(MAKE) -s fclean
	@$(MAKE) -s -C $(OTHER_PATH) fclean

.PHONY = all clean fclean re library exec