#include "shell.h"
/**
 * exit_shell - Function that exits the shell
 * @line: getline line
 * @cmd: command given
 * @fp: final path
 */
void exit_shell(char *line, char **cmd, char **fp)
{
	_free(fp);
	_free(cmd);
	free(line);
	exit(98);
}
/**
 * print_env - function that prints the enviroment
 * @line: getline line
 * @cmd: command given
 * @fp: final path
 */
void print_env(char *line, char **cmd, char **fp)
{
	int i = 0;
	char **env = environ;

	(void)line;
	(void)cmd;
	(void)fp;

	while (env[i])
	{
		write(STDOUT_FILENO, (const void *) env[i], _strlen(env[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}
