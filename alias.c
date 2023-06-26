#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/**
* alias - define aliases
* @args: array of string representing command line arguments
* Return: 0 success, 1 on error
*/

int alias(char *args[])
{
	char *name;
	char *value;
	int k;
	int ky = 0;

/* Check if the user provided any arguments */
	if (args[1] == NULL)
	{
/* Print a list of all aliases */
	for (k = 0; k < 1024; k++)
	{
	if (aliases[k] != NULL)
	{
	printf("aliases %s='%s'\n", aliases[k], values[k]);
	}
	}
	else
	{
/* Process the alias commands */
	for (k = 1; args[k] != NULL; k++)
	{
	name = args[k];
	value = args[k + 1];

/* Check if user is defining a new alias or redefining an existing one */
	if (value != NULL)
	{
/* Define a new alias */
	aliases[k] = name;
	values[k] = value;
	}
	else
	{
/* Redefine an existing alias */
	if (aliases[k] == NULL)
	{
	printf("Error: alias '%s' does not exit\n", name);
	ky = 1;
	}
	else
	{
	values[k] = value;
	}
	}
	}
	}
	return (ky);
}
