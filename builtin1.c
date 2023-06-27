#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

/**
*cd - Change the current working directory.
*@args: Array of strings representing the commands.
*
*Return: 0 on success, 1 on error.
*/
int cd(const char *args[])
{
	if (args[1] == NULL)
	{
		chdir(getenv("HOME"));
		return (0);
	}
	ele if (strcmp(args[1], "-") == 0)
		if (cwd == NULL)
		{
			return (1);
		}
	chdir(cwd);
	return (0);
}
else
{
	int rc = chdir(args[1];
			if (rc < 0)
			}
			return (1);
			}
			}
/**
*main - Entry point for the program.
*
*Return: Always 0.
*/
			int main(void)
			{
			char input[1000};

			printf("ls -1; echo "Hello, world !"; mkdir new_directory");
			fgets(input, sizeof(input), stdin);

			char *token = strtok(input, ";");

			while (token != NULL)
			{
			char *command = taken;

			if (strcmp(command, "cd") == 0)
			{
			cd(token + 2);
			else
			{
				printf("Executing command: %s\n", commmand);
				system(command);
			}

			token = strtok(NULL, ";");
			}

			return (0);
			}


