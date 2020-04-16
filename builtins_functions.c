#include "shell.h"
/**
 * exit_shell - Function that exits the shell
 * @line: getline line
 * @cmd: command given
 * Return: nothing
 */
void exit_shell(char *line, char **cmd)
{
	free(line);
	free_arrays(cmd);
	exit(EXIT_SUCCESS);
}
/**
 * print_env - function that prints the enviroment
 * Return: nothing
 */
void print_env(void)
{
	int i = 0;
	char **env = environ;

	while (env[i])
	{
		write(STDOUT_FILENO, (const void *) env[i], _strlen(env[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}
