#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char command[1024];        // Buffer to store user input
    char *token;               // Pointer to the first token found in input
    const char delim[2] = " "; // Delimiter for splitting commands

    while (1)
    {
        printf("myshell> "); // Prompt for input
        if (fgets(command, sizeof(command), stdin) == NULL)
            break; // Exit if EOF is reached (Ctrl+D)

        command[strcspn(command, "\n")] = 0; // Remove newline character

        // Tokenize the input
        token = strtok(command, delim);
        if (token == NULL)
            continue;

        // Process each token
        if (strcmp(token, "exit") == 0)
        {
            printf("Exiting shell...\n");
            break;
        }
        else
        {
            printf("You entered command: %s\n", token);
            while (token != NULL)
            {
                token = strtok(NULL, delim);
                if (token != NULL)
                    printf("With argument: %s\n", token);
            }
        }
    }

    return 0;
}