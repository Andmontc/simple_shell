#include "shell.h"
/**
 * execute_command - Function that executes a command
 * @commands: commands given
 * @final_paths: paths given
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
		exit_shell(line , commands);
	/*  */
	else if((_strcmp("env", commands[0])) == 0)
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
 * _free - function that free memory
 * @commands: memory to free
 */
void free_commands(char **commands)
{
	int i;

	if (commands == NULL)
		return;
	i = 0;
	while (commands[i])
	{
		free(commands[i]);
		i++;
	}
	if (commands[i] == NULL)
		free(commands[i]);
	free(commands);
}
