#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define BUFSIZE 1024

int main() {
    char line[BUFSIZE];
    char *args[BUFSIZE];
    while (1) {
        printf("mysh> "); // Affiche le prompt
        
        if (!fgets(line, BUFSIZE, stdin)) break; // Lit la ligne entrée par l'utilisateur
        line[strcspn(line, "\n")] = 0; // Enlève le retour à la ligne

        // Commande interne : exit
        if (strcmp(line, "exit") == 0)
            break;
        // Commande interne : hello
        if (strcmp(line, "hello") == 0) {
            printf("Bonjour !\n");
            continue;
        }
        // Découpage de la ligne en arguments (séparés par espace ou tabulation)
        int i = 0;
        char *token = strtok(line, " \t");
        while (token != NULL) {
            args[i++] = token;
            token = strtok(NULL, " \t");
        }
        args[i] = NULL; // Fin du tableau d'arguments
        if (args[0] == NULL) continue; // Ignore les lignes vides
        // Création d'un processus enfant pour exécuter la commande externe
        pid_t pid = fork();
        if (pid == 0) {
            // Processus enfant : exécute la commande
            execvp(args[0], args);
            perror("mysh"); // Affiche une erreur si execvp échoue
            exit(1);
        } else if (pid > 0) {
            // Processus parent : attend la fin de la commande
            wait(NULL);
        } else {
            // Erreur lors du fork
            perror("fork");
        }
    }
    return 0;
}
