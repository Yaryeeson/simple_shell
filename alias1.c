#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "shell.h"

/**
* replace_variables - replace environment variables in command
* line argument
* @args: array of strings representing command line argument
* Return: 0 success, 1 on error
*/

int replace_variables(char *args[])
{
	char *name;
	char *value;
	int ky, k = 0;

	if (args[1] == NULL)
	{
	else
	{
	for (k = 1; args[k] != NULL; k++)
	{
	name = args[k];
	value = getenv(name);

	if (value != NULL)
	{
	args[k] = value;
	}
	else
	}
	}
	}
	return (ky);
}

/**
* handle_variables - handle special variables in command line arguments
* @args: array of strings representing command line argument
* Reture: 0 success, 1 on error
*/

int handle_variables(char *args[])
{
	int ky = 0;

	rc = replace_variables(args);

	if (strcmp(args[0], "$?") == 0)
	{
	args[0] = malloc(sizeof(int));
	sprintf(args[0], "%d", getpid());
	}
	if (strcmp(args[0], "$$") == 0)
	{
	args[0] = malloc(sizeof(int));
	sprintf(args[0], "%d", getpid())
	}
	return (ky);
}
