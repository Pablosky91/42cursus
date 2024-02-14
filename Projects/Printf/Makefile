#VARIABLES

NAME = libftprintf.a
LIBRARY_NAME = libft.a

RM = rm -f

CC = gcc
CFLAGS = -Wall -Wextra -Werror

AR = ar
AR_FLAGS = -r

INCLUDE_PATH = libft
C_INCLUDE = -I $(INCLUDE_PATH)

SOURCES = ft_printf.c

BONUS_SOURCES =	\

OBJECTS = $(SOURCES:.c=.o)

BONUS_OBJECTS = $(BONUS_SOURCES:.c=.o)

#RULES

all: $(NAME)

$(NAME): $(LIBRARY_NAME) $(OBJECTS)
	cp $(INCLUDE_PATH)/$(LIBRARY_NAME) $(NAME)
	$(AR) $(AR_FLAGS) $(NAME) $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) $(C_INCLUDE) -o $@ -c $^

clean:
	$(RM) $(OBJECTS) $(BONUS_OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

$(LIBRARY_NAME):
	@$(MAKE) -C $(INCLUDE_PATH) library

exec: all
	@clear
	@./$(NAME)
	@$(MAKE) -s fclean

.PHONY = all clean fclean re exec