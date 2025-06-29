#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "../include/mysh.h"

void mysh_loop(void) {
    char *line;
    char **args;
    int status;

    do {
        printf("mysh> ");
        line = mysh_read_line();
        args = mysh_split_line(line);
        status = mysh_execute(args);

        free(line);
        free(args);
    } while (status);
}

char *mysh_read_line(void) {
    char *line = NULL;
    size_t bufsize = 0;

    getline(&line, &bufsize, stdin);
    return line;
}

char **mysh_split_line(char *line) {
    int bufsize = MYSH_TOK_BUFSIZE;
    int position = 0;
    char **tokens = malloc(bufsize * sizeof(char *));
    char *token;

    if (!tokens) {
        fprintf(stderr, "mysh: allocation error\n");
        exit(EXIT_FAILURE);
    }

    token = strtok(line, MYSH_TOK_DELIM);
    while (token != NULL) {
        tokens[position++] = token;

        if (position >= bufsize) {
            bufsize += MYSH_TOK_BUFSIZE;
            tokens = realloc(tokens, bufsize * sizeof(char *));
            if (!tokens) {
                fprintf(stderr, "mysh: allocation error\n");
                exit(EXIT_FAILURE);
            }
        }

        token = strtok(NULL, MYSH_TOK_DELIM);
    }
    tokens[position] = NULL;
    return tokens;
}

int mysh_execute(char **args) {
    if (args[0] == NULL) {
        return 1;
    }

    if (strcmp(args[0], "exit") == 0) {
        return 0;
    }

    pid_t pid = fork();

    if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("mysh");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        perror("mysh");
    } else {
        int status;
        waitpid(pid, &status, 0);
    }

    return 1;
}
