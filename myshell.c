#include <stdio.h>
#include <signal.h>

int main()
{
    signal(SIGINT, SIG_IGN);
    char command[1024]; // Buffer to store use input

    while (1)
    {                        // infinite loop to keep the shell running
        printf("myshell> "); // Prompt for input
        if (fgets(command, sizeof(command), stdin) == NULL)
            break; // Exit if Ctrl+D is pressed

        printf("You enetered: %s", command); // Echo back the input
    }

    return 0;
}