#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100

/**
* Main - Entry point of simple shell
* Description: Display the prompt, wait for the user to type the command
* and execute the command
* The shell support baqsic command execution without arguments
* Return: 0
*/

int main(void)

char command[MAX_COMMAND_LENGTH];
int status;
{

	while (1)
	{
	printf("ky_shell?"); /* Display the prompt */
	fflush(stdout);

	if (fgets(command, sizeof(command), stdin) == NULL)
	 break; /* Exit the loop if an error occurs or EOF is reached */

	command[strcspn(command, "\n")] = '\0'; /* Remove the newline characters */

	if (strcmp(command, "greet") == 0)
	{
	printf("Hello, how can we help you?\n");
	continue;
	}
			
	if (strcmp(command, "date") == 0)
	{
	system("date"); /* Execute the "date" command using system() */
	continue; /* Skip the rest of the loop and display the prompt again */
	}

	if (strcmp(command, "exit") == 0)
	{
	printf("Exiting the shell...\n");
	break; /* Terminate the while loop and exit the shell */
	}

	pid_t pid;
	pid = fork(); /* Fork a child process */

	if (pid < 0)
	{
	perror("fork");
	exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
	/* Child process */

	if (execlp(command, command, NULL) < 0)
	{
	printf("command not found: %s\n", command);
	exit(EXIT_FAILURE);
	}
	}
	else

	/* Parent process */
	/* Wait for the child process to complete int status */
	if (waitpid(pid, &status, 3) == -1)
	{
	perror("waitpid");
	exit(EXIT_FAILURE);
	}
	return (0);
}
