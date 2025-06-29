FROM alpine:latest

RUN apk add --no-cache gcc musl-dev bash

WORKDIR /app

COPY . .

RUN gcc -Wall -Wextra -Werror -o mysh main.c

CMD ["./mysh"]
