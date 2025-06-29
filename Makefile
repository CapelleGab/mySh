NAME = mysh
SRC = src/main.c
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iinclude

# Cibles
all: $(NAME) # Compile le projet avec la commande `make`

$(NAME): $(SRC)
	$(CC) $(CFLAGS) -o $(NAME) $(SRC)

run: $(NAME)
	./$(NAME)

clean:
	rm -f $(NAME)

re: clean all

docker-build:
	docker build -t mysh .

docker-run:
	docker run --rm -it mysh

test:
	@echo "ls > out.txt" | ./$(NAME) && cat out.txt

.PHONY: all run clean re docker-build docker-run test
