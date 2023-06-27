#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "shell.h"

#define MAX_COMMAND_LENGTH 100

/*
*display_prompt - Displays the prompt indication
*that the shell is ready to accept a command.
*/
/* Displays the prompt for the user */
void display_prompt(void)
{
	printf("ky_shell$ ");
	fflush(stdout);
}

/*
*read_command - Reads a comman entered by the user from the standard input.
*@command: A Character array to store the entered command.
*
*Returns:
*	-1 if a command is successfully read.
*	-0 if there is an error or end of input is reached
*/

/*Reads a command from the user */
int read_command(char *command)
{
	if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL)
		return (0);

	command[strcspn(command, "\n")] = '\0'; /* Remove the newline character */

	return (1);

}

/*
*tokenize_command - Tokenizes the command string into individual arguments.
*@command: The command string to be tokenized.
*args: An array to store the individual arguments.
*
*Returns: 
*	The number of arguments.
*/

/* Tokenizes a command string into separate arguments */
int tokenize_command(char *command, char *args[])
{
	int argCount = 0;
	char *token = strtok(command, " ");

	while (token != NULL)
	{
		args[argCount++] = strdup(token);
		token = strtok(NULL, " ");
	}

	args[argCount] = NULL;

	return (argCount);
}

/*
*execute_command - Execute the command entered by user
*@args: An array containing the command and its arguments.
*
*Returns:
*	The status of the command execution
*/

/* Executes a command with the given arguments */
int execute_command(char **args)
{
	if (strcmp(args[0], "env") == 0)
	{
		print_environment();
		return (0);
	}
	else if (strcmp(args[0], "exit") == 0)
	{
		int exit_status = 0;

		if (args[1] != NULL)
			exit_status = atoi(args[1]);

		printf("Exiting the shell with status %d...\n", exit_status);
		exit(exit_status);
		}

		pid_t pid;
		int status;

		pid = fork();

		if (pid < 0)
		{
		perror("fork");
		exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
		if (execvp(args[0], args) < 0)
		{
		printf("command not found: %s\n", args[0]);
		exit(EXIT_FAILURE);
		}
		}
		else
		{
			if (waitpid(pid, &status, WUNTRACED) == -1)
			{
				perror("waitpid");
				exit(EXIT_FAILURE);
			}
		}

		return (status);

}

/* Main function for the program */
int main(void)
{
	char command[MAX_COMMAND_LENGTH];
	char *args[MAX_COMMAND_LENGTH];
	int status;

	while (1)
	{
		display_prompt();

		if (!read_command(command))
			break;

		int argCount = tokenize_command(command, args);

		if (strcmp(args[0], "exit") == 0 && argCount > 2)
		{
			printf ("Usage: exit [status]\n");
			continue;
		}

		status = execute_command(args);

		/* Free memory allocated for the arguments */
		for (int i = 0; i < argCOUNT; i++)
		{
			free(args[i]);
		}
	}

	return (0);

}
