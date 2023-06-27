#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

/**
*ky_setenv - Initialize a new environment variable or modify an existing one.
*@args: The array of arguments passed to the function.
*
*Return: Always return 1 to continue executing the shell.
*/
int ky_setenv(char **args)
	if (args[1] == NULL || args[2] == NULL)
{
	fprintf(stderr, "usage: ky_setenv USERNAME KATYRA\n");
	return (1);
}
if (setenv(args[1], args[2], 1) != 0)
{
	perror("ky_setenv");
	return (1);
}
return (1);

/**
*ky_unsetenv - Remove an environment variable.
*@args: The array of arguments passed to the function.
*
*Return: Always return 1 to continue executing the shell.
*/
int ky_unsetenv(char **args)

	if (args[1] == NULL)
{
	fprintf(stderr, "usage: ky_unsetenv ky_VAR\n");
	return (1);
}
if (unsetenv(args[1]) != 0)
{
	perror("ky_unsetenv");
	return (1);
}

return (1);
