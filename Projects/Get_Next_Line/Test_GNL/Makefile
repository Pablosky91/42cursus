#VARIABLES

NAME = test.out
OTHER_PATH = ..

RM = rm -f

CC = gcc
CFLAGS = -Wall -Wextra -Werror $(BUF_FLAG)
BUF =
ifeq ($(BUF),)
 BUF_FLAG =
else
 BUF_FLAG = -D BUFFER_SIZE=$(BUF)
endif

SOURCES = main.c
OBJECTS = $(SOURCES:.c=.o)

GNL_SRC =	$(addprefix $(OTHER_PATH)/,\
			get_next_line_bonus.c\
			get_next_line_utils_bonus.c)
GNL_OBJ = $(GNL_SRC:.c=.o)

INCLUDE_PATH = $(OTHER_PATH)
C_INCLUDE = -I $(INCLUDE_PATH)

#RULES

all: $(NAME)

$(NAME): $(OBJECTS) $(GNL_OBJ)
	$(CC) $(CFLAGS) $(C_INCLUDE) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) $(C_INCLUDE) -o $@ -c $^

clean:
	$(RM) $(OBJECTS) $(GNL_OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

exec: $(NAME)
	@clear
	@./$(NAME)

rexec: re exec

.PHONY: all clean fclean re exec rexec