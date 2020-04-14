#include "shell.h"
/**
 * readline - function that reads the argv
 * Return: line captured
 */
char *readline(void)
{
	int numchar = 0;
	char *line = NULL;
	size_t size;

		numchar = getline(&line, &size, stdin);

		if (numchar != -1)
		{
			size = 0;
			return (line);
		}
		else
		{
			write(STDOUT_FILENO, "\n", 1);
			free(line);
			size = 0;
			exit(98);
		}
size = 0;
return (line);
}
