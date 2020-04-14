#include "shell.h"
/**
 * check_builtins - Function that check if the command is a builtin or no
 * @line: getline line
 * @cmd: command given
 * @fp: final path
 * Return: sucess
 */
int check_builtins(char *line, char **cmd, char **fp)
{
int j;

	built fm[] = {
		{"exit", exit_shell},
		{"env", print_env},
		{NULL, NULL}
	};

	if (cmd[0] != NULL)
	{
		for (j = 0; fm[j].op != '\0'; j++)
		{
			if (_strcmp(cmd[0], fm[j].op) == 0)
			{
				fm[j].f(line, cmd, fp);
				return (1);
			}
		}
	}
return (0);
}
