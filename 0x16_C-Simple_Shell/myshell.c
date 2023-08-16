#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int main() {
    while (1) {
        printf("$ ");
        fflush(stdout); // Flush the output buffer to ensure the prompt is displayed immediately

        char *input = NULL;
        size_t len = 0;
        ssize_t read;

        read = getline(&input, &len, stdin); // Read user input

        if (read == -1) {
            if (feof(stdin)) {
                // User pressed Ctrl+D (EOF), exit the loop
                printf("\n");
                break;
            } else {
                perror("getline");
                exit(EXIT_FAILURE);
            }
        }

        // Remove the newline character at the end of the input
        if (input[read - 1] == '\n') {
            input[read - 1] = '\0';
        }

        // Split the input into command and arguments
        char *command = input;
        char *args[] = {command, NULL};

        // Create a child process
        pid_t pid = fork();

        if (pid == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            // Child process
            execve(command, args, NULL);
            perror("execve");
            exit(EXIT_FAILURE);
        } else {
            // Parent process
            wait(NULL); // Wait for the child process to finish
        }

        // Free allocated memory for input
        free(input);
    }

    return 0;
}

