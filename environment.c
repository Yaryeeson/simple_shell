#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
* main - simple shell program's entry point
* Description: displays a prompt read user input for a command
* and executes the command in a child process using execuvp
* the shell allows basic command execution with arguments
* Return: 0
*/

int main(void)
{
	char command[100];

	while (1)
	{
	printf("ky_shell$");
	fflush(stdout);

	if (fget(command, sizeof(command), stdin) == NULL)
	{
	break;
	}

	command[strcspn(command, "\n")] = '\0';

	if (strcmp(command, "exit") == 0)
	{
	printf("Exiting the shell...\n");
	break;
	}
	else if (strcmp(command, "envp") == 0)
	{
	/* Print the current environment */
	for (char **envp = environ; *envp; envp++)
	{
	printf("%s\n", *envp);
	}
	}
	else
	{
	/* Execute the command */
	pid_t pid = fork();

	if (pid < 0)
	{
	perror("fork");
	exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
	if (execlp(command, command, NULL) < 0)
	{
	prinf("command not found: %s\n", command);

	exit(EXIT_FAILURE);
	}
	}
	else
	{
	waitpid(pid, NULL, 0);
	}
	}
	}
	return (0);
}
