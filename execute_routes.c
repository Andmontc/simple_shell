#include "shell.h"
/**
 * exec_routes - functions that receive commands into directores array
 * and try one by one to execv
 * @commands: Array of commands
 * @line: Pointer to line
 * @env: environment
 * Return: false on fail
 */
bool exec_routes(char **commands, char *line, char **env)
{
	char **directories = NULL;
	int i = 0;
	/* 🧿 directories obtains the routes */
	/* EXAMPLE : /BIN/LS - /BIN/PWD */
	directories = get_routes(commands, env);
	/* T R Y   D I R E C T O R I E S   R O U T E S */
	while (directories[i] != NULL)
	{
		if (access(directories[i], X_OK) == 0)
			execve(directories[i], commands, env);
		i++;
	}
	/* NOT FOUND COMMAND */
	if (directories[i] ==  NULL)
	{
		free_arrays(directories);
		return (false);
	}
    /** 🆓 MEMORY */
	free(line);
	free_arrays(directories);
	free_arrays(commands);
	exit(EXIT_SUCCESS);
}

