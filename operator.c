#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/**
* main - entry point of program
* @argc: number of command line arguments
* @argv: array of command line arguments
* Return: 0 success
*/
int main(int argc, char *argv[])
{
	char *args[1024];
	int k = 0;

	int cd(char *args[]);
	int echo(char *args[]);
	int ls(char *args[]);

	/* Get the command line arguments */
	while (k < argc)
	{
	args[k] = argv[k];
	k++;
	}

	/* Handle the cd command */
	if (strcmp(args[0], "cd") == 0)
	{
	cd(args);
	}
	/* Handle the echo command */
	else if (strcmp(args[0], "echo") == 0)
	{
	echo(args);
	}
	/* Handle the ls command */
	else if (strcmp(args[0], "ls") == 0)
	{
	ls(args);
	}
	/* Handle the && and || operators */
	else
	{
	int ky = 0;
	int k = 1;

	while (k < argc)
	{
	if (strcmp(args[k], "&&") == 0)
	{
	ky = execvp(args[0], args);
	if (ky != 0)
	{
	break;
	}
	k++;
	}
	else if (strcmp(args[k], "||") == 0)
	{
	ky = execvp(args[0], args);
	if (ky == 0)
	{
	break;
	}
	k++;
	}
	else
	{
	ky = execvp(args[k], args);
	}
	}
	if (ky != 0)
	fprintf(stderr, "Error: %s\n", strerror(errno));
	}
	return (0);
}
