NAME = mysh
SRC = src/main.c src/mysh.c
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iinclude

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

run: $(NAME)
	./$(NAME)

clean:
	rm -f $(NAME)

re: clean all

.PHONY: all run clean re
