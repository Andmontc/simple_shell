#include "shell.h"
/**
 * execute_command -  Execute a command in the shell
 * @commands: array of commands
 * @line: line pointer
 * @env: environment varibale
 * Return: true on succes , failure on fail
 */
bool execute_command(char **commands, char *line, char **env)
{
	bool ejecuto = false;

	if (commands == NULL)
	{
		free(line);
		exit(EXIT_SUCCESS);
	}
	/*  */
	else if ((_strcmp("exit", commands[0])) == 0)
		exit_shell(line, commands);
	/*  */
	else if ((_strcmp("env", commands[0])) == 0)
	{
		print_env();
		ejecuto = true;
	}
	/* */
	else if (access(commands[0], X_OK) == 0)
		execve(commands[0], commands, NULL);
	else
	{
		ejecuto = concat_commands(commands, line, env);
		if (ejecuto == false)
			return (false);
	}
	return (ejecuto);
}
/**
 * free_arrays - function that free memory
 * @array: memory to free
 */
void free_arrays(char **array)
{
	int i;

	if (array == NULL)
		return;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	if (array[i] == NULL)
		free(array[i]);
	free(array);
}
