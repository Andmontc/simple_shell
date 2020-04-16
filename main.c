#include "shell.h"

/**
 * main - Shell execution.
 * @argc: number of input arguments.
 * @argv: input arguments array.
 *
 * Return: 0 on success.
 */

int main(int ac, char **av, char **env)
{

	if (isatty(STDIN_FILENO) == 1)
	{
		interactive(env);
	}
	else
	{
		non_interactive(ac , av, env);
	}
	exit(0);
	return (0);
}