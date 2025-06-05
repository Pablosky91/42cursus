#VARIABLES

NAME = libftprintf.a

RM = rm -f

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3

AR = ar
AR_FLAGS = -cr

INCLUDE_PATH = libft
LIBRARY_NAME = $(INCLUDE_PATH)/libft.a

SOURCES =	ft_print_char.c\
			ft_print_flag.c\
			ft_print_hexadecimal.c\
			ft_print_int.c\
			ft_print_pointer.c\
			ft_print_string.c\
			ft_print_unsigned_int.c\
			ft_print.c\
			ft_printf.c

OBJECTS = $(SOURCES:.c=.o)

#RULES

all: $(NAME)

$(NAME): $(LIBRARY_NAME) $(OBJECTS)
	cp $(LIBRARY_NAME) $(NAME)
	$(AR) $(AR_FLAGS) $(NAME) $(OBJECTS)

$(LIBRARY_NAME):
	@$(MAKE) -C $(INCLUDE_PATH) all

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $^

clean:
	$(RM) $(OBJECTS)
	@$(MAKE) -C $(INCLUDE_PATH) clean

fclean:
	$(RM) $(NAME) $(OBJECTS)
	@$(MAKE) -C $(INCLUDE_PATH) fclean

re: fclean all

.PHONY: all clean fclean re