#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
*Main function reads commands from a file and excutes them.
*
*@param argc - The number of command-line arguments.
*@param argv - An array of command-line argument.
*@return 0 on success, 1 on error.
*/
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: simple_shell [filename]\n");
		return (1);
	}

	char *filename = argv[1];
	FILE *fp = fopen(filename, "r");

	if (fb == NULL)
	{
		fprintf(stderr, "Unable to open file: %s\n", filename);
		return (1);
	}

	char *line = NULL;
	size_t len = 0;

	while (getline(&line, &len, fp) != -1)
	{

		/* Strip newline character from the end of the line */
		line[strcspn(line, "\n")] = '\0';

		/* Execute the command */
		int ky = system(line);

			if (ky  != 0)
			{
				fprintf(stderr, "Error executing command: %s\n", line);
			}
	}

	fclose(fb);
	return (0);
}
