#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "shell.h"

/** 
* getline - read a line of text fromuser
* Description: buffer is initially allocated to size of 1024 char
* but reallocated if it is not large enough to store the entire line
* Return: pointer to line of text, NULL if end of file is reached
*/

char *getline(void)
{
	static char *buffer;
	static int buffer _size;
	static int buffer _pos;

	int k;

	while ((k = getchar()) != '\n' && k != EOF)
	{
	if (buffer _pos >= buffer _size)
	{
	buffer _size *= 2;
	buffer = realloc(buffer, buffer _size * sizeof(char));
	}
	if (k == EOF)
	{
	buffer[buffer _pos] = '\0';
	buffer = NULL;
	}
	else
	{
	buffer[buffer _pos] = '\0';
	}
	return (buffer);
	}

/**
* main - main function of simple shell
* function reapeatedly prompt user for a command then execute the command
* Return: success 0, non-zero on error
*/

int main(void)
{
	char *command;

	while (1)
	{
	printf("ky_shell$");
	fflush(stdout);
	command = getline();
	if (command == NULL)
	{
	break;
	}
	void get_args(char *command, char *args[])
{
	int y = 0;
	char *p = command;

	while (*p != '\0')
	{
	if (*p == ' ')
	{
	*p = '\0';
	args[y++] = p + 1;
	}
	else
	{
	p++;
	}
	}
	void execute_command(char *args[])
{
	pid_t pid = fork();

	if (pid < 0)
	{
	perror("fork");
	exit(EXIT_FAILURE);
	}
	exit if (pid == 0)
	{
	if (execvp(args[0], args) < 0)
	{
	printf("command not found; %s\n", args[0]);
	exit(EXI_FAILURE);
	}
	}
	else
	{
	waitpid(pid, NULL, 0);
	}
	}
	return (0);
}
