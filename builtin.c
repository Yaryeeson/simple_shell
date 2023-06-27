#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "shell.h"

/**
* cd - command changes to previous directory
* @args: array of string representing command line arguments
* @ PWD: environment variable updated to reflect new current
* working directory
* Return: 0 if directory was changed succesful, 1 on error
*/

int cd(char *args[])
{
	if (args[1] == NULL)
	{
	char *homedir = getenv("HOME");

	if (homedir == NULL)
	{
	return (1);
	}
	chdir(homedir);
	}
	else if (strcmp(args[1], "-") == 0)
	{
	char *cwd = getcwd(NULL, 0);

	if (cwd == NULL)
	{
	return (1);
	}
	chdir(cwd);
	}
	else
	{
	int ky = chdir(args[1]);

	if (ky < 0)
	{
	return (1);
	}
	}
	char *cwd = getcwd(NULL, 0);

	setenv("PWD", cwd, 1);

	return (0);
}
