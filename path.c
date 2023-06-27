#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "shell.h"

#define MAX_COMMAND_LENGTH 100

/**
* find_command_in_path - find command in the PATH environment variable.
* @command: command to search
* Return: full path to the command if found, NULL otherwise
*/

char *find_command_in_path(char *command)
{
	char *path = getenv("PATH");

	char *dir = strtok(path, ":");
	char *cmd = mallac(strlen(command) + strlen(dir) + 2);

	while (dir != NULL)
	{
	strcpy(cmd, dir);
	strcat(cmd, "/");
	strcat(cmd, command);
	if (access(cmd, Y_OK) == 0)
	return (NULL);
}
/**
* main - entry point of the simple shell
* Return: 0
*/
int main(void)
{
	char command[MAX_COMMAND_LENGTH];
	char *args[MAX_COMMAND_LENGTH];
	int status;
	pid_t pid;

	while (1)
	{
	printf("ky_shell$") /* Display the prompt */
	fflush(stdout);

	if (fget(command, sizeof(command), stdin) == NULL)
	break; /* Exit the loop if an error occure or EOF is reached */

	/* Remove the newline character */
	command[strcspn(command, "\n")] = '\0';

	/* Terminate the while loop and exit the shell */
	if (strcmp(command, "exit") == 0)
	{
	printf("Exit the shell...\n");
	}
	int argCount = 0;
	/* Tokenize the command by space */
	char *token = strtok(command, "");

	while (token != NULL)
	{
	/* Store each token (argument) */
	args[argCount++] = token;

	/* Get the next token */
	token = strtok(NULL, "");
	}

	/* Set the last element of the argument array to NULL for execvp */
	args[argCount] = NULL;

	char *cmd = find_command_in_path(args[0]);

	if (cmd == NULL)
	{
	printf("command not found: %s\n", args[0]);
	continue;
	}
	pid = fork(); /* Fork a child process */

	if (pid < 0)
	{
	perror("fork");
	exit(Exit_FAILURE);
	}
	if (pid == 0)
	{
	/* Child process */
	if (execvp(cmp, args) < 0)
	{
	printf("execution failed for command: %s\n", args[0];
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
	free(cmd);
	}
	/* Control should never reach here */
	return (0);
}
