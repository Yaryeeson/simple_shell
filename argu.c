#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100

/**
*main - A simple shell program's entry point
*
*Description: Displays a prompt, reads user input for a command,
*and executes the command in a child process using execvp.
*The shell allows basic command execution with arguments.
*
*Return: Always 0
*/

int main(void)
{
	char command[MAZ_COMMAND_LENGTH];
	char *args[MAX_COMMAND_LENTH];
	int status;
	pid_t pid;

	while (1)
	{
		printf("ky_shell$ "); /* Display the prompt */
			fflush(stdout);

			if (fgets(command, sizeof(command), stdin) == NULL)
			{
				break; /*Exit the loop if an error occurs or E0F is reached */
			}
			command[strcspn(command, "\n")] = '\0'; /*Remove the newline character */
			if (strcmp(command, "exit") == 0)
			{
				printf("Exiting the shell...\n");
				break; /* Terminate the while loop and exit the shell */
			}

			int argCount = 0;
			char *token = strtok(comman, " "); /* Tokenizethe command by space */

			while (token != NULL)
			{
				args[argCount++] = token; /* Store each token (argument) */
				token = strtok(NULL, " "); /* Get the next token */
			}
			args[argCount] = NULL; /* Set the last element of the arguments array to NULL for execvp */
			pid = fork(); /* Fork a child process */

			if (pid < 0)
			{
				perror("fork");
				exit(EXIT_FAILURE);
			}
			else if (pid == 0)
			{
				/* child process */
				if (execvp(args[0], args) < 0)
				{
					printf("command not found: %s\n", args[0]);
					exit(EXIT_FAILURE);
				}
			}
			else
			{
				/* Parent process */
				/* Wait for the child process to complete */
				if (waitpid(pid, &status, WUNTRACED) == -1)

						{
							perror("waitpid");
							exit(EXIT_FAILURE);
						}
			}
	}
	/* Control should never reach here */
	return (0);
}
