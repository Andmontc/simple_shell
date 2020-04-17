#include "shell.h"

/**
 * main - Shell execution.
 * @ac: number of input arguments.
 * @av: input arguments array.
 * @env: environment variable.
 * Return: 0 on success.
 */

int main(int ac, char **av, char **env)
{
	(void) ac;
	(void) av;
	if (isatty(STDIN_FILENO) == 1)
	{
		write(STDOUT_FILENO, "ShellBM_$ ", 11);
		interactive(env);
	}
	else
	{
		interactive(env);
	}

	exit(0);
	return (0);
}
