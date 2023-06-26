#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/**
* getline - reads a line of text from the user
* Description: the buffer is initially allocated to size 1024 char
* but reallocated if not large to store the entire line
* Return: pointer to the line of text, NULL end of file is reached
*/

char *getline(void)
{
	static char *buffer;

	static int buffer _size = 1024;

	static int buffer _pos;

	/* Intialize the buffer if it not already initialized */
	if (buffer == NULL)
	{
	buffer = malloc(buffer _size * sizeof(char));
	}
	/* Read characters from the user until newline or EOF is reached */
	int k;

	while ((k = getchar()) != '\n' && k != EOF)
	{
	/* If buffer is full reallocate it to be twice as big */
	if (buffer _pos >= buffer _size)
	{
	buffer _size *= 2;
	buffer = realloc(buffer, buffer _size * sizeof(char));
	}
	/* Store the character in the buffer */
	buffer[buffer _pos++] = k;
	}
	/* If the end of file was reached, set buffer to NULL */
	if (k == EOF)
	{
	buffer[buffer _pos] = '\0';
	buffer = NULL;
	}
	else
	{
	/* Terminate the string with a NULL character */
	buffer[buffer _pos] = '\0';
	}
	return (buffer);
}

