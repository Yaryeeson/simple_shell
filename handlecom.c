#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/* Function prototypes */
int cd(char *args[]);
int echo(char *args[]);
int ls(char *args[]);
int alias(char *args[]);

/*
*replace_variables - Replace environ variables in
*the command-line arguments.
*
*@args: Array of strings representing the command-line arguments.
*
*This function searches for environ variables in the command-line args
*and replaces them with their corresponding values.
*
*Return: 0 on success, 1 on error.
*/
int replace_variables(char *args[])
{
	/* Implementation code here */
	char *name, *value;
	int k, ky = 0;

		if (args[1] == NULL)
			return (ky);

	for (i = 1; args[k] != NULL; k++)
	{
		/* Handle comments: skip lines starting with '#' */
		if (args[k][0] == '#')
			continue;

		name = args[k];
		value = getenv(name);

		if (value != NULL)
			args[k] = value;
	}

	return (ky);
}

/*
*handle_variables - Handle special variables in the comman-line arguments.
*
*args: Array of strings representing the command-line arguments
*
*This function handles special variables like "$?" and "$$" in the
*comman-line arguments replacing them with their respective values.
*
*Return: 0 on success, 1 on error.
*/
int handle_variables(char *args[])
{
	/* Implementation code here */
	int ky = 0;

	ky  = replace_variables(args);

	if (strcmp(args[0], "$?") == 0)
	{
		args[0] = malloc(sizeof(int));
		sprintf(args[0], "%d", getppid();
				}

				if (strcmp(args[0], "$$") == 0)
				{
				args[0] = malloc(sizeof(int));
				sprintf(args[0], "%d", getppid());
				}

				return (ky);

			}



