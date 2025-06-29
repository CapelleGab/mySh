#ifndef MYSH_H
#define MYSH_H

// Définitions constantes
#define MYSH_BUFSIZE 1024
#define MYSH_TOK_BUFSIZE 64
#define MYSH_TOK_DELIM " \t\r\n\a"

// Prototypes des fonctions du shell
void mysh_loop(void);
char *mysh_read_line(void);
char **mysh_split_line(char *line);
int mysh_execute(char **args);

#endif /* MYSH_H */
