#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "shell.h"

#define MAX_COMMAND_LENGTH 100

/**
*display_prompt - Display the shell prompt
*/
void display_prompt(void)
{
	printf("ky_shell$");
	fflush(stdout);
}

/**
*read_command - Read user input for a command
*@command: Buffer to store the user input
*Return: 1 on success, 0 on error or EOF
*/
int read_command(char *command)
{
	if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL)
		return (0);

	command[strcspn(command, "\n")] = '\0';

	return (1);
}

/**
*tokenize_command - Tokenize the command by space
*@command: User input command
*@args: Array to store command arguments
*Return: The number of arguments
*/
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

/**
*execute_command - Execute the command in a child process using execvp
*@args: Array of command arguments
*Return: 1 if successful, 0 on failure
*/
int execute_command(char **args)
{
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

/**
*main - A simple shell program's entry point
*Return: Always 0
*/
int main(void)
{
	char command[MAX_COMMAND_LENGTH];
	char *args[MAX_COMMAND_LENGTH];
	int status;
	pid_t pid;

	while (1)
	{
		display_prompt();

		if (!read_command(command))
		break;

		if (strcmp(command, "exit") == 0)
		{
			printf("Exiting the shell...\n");
			break;
		}

		int argCount = tokenize_command(command, args);

		status = execute_command(args);

		/* Free memory allocated for the arguments */
		for (int i = 0; i < argCount; i++)
		{
			free(args[i]);
			}
		}

	return (0);
}

