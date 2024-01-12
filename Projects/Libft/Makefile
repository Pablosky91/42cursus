#VARIABLES

TARGET = libft

CC = cc

CFLAGS = -Wall -Wextra -Werror

SOURCES = $(wildcard *.c)

OBJECTS = $(SOURCES:.c=.o)

#RULES

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(TARGET)

re: fclean all

exec: all
	@clear
	@./$(TARGET)