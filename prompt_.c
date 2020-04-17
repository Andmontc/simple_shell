#include "shell.h"
/**
 * interactive - shell in interactive mode
 * @env: enviroment
 * Return: 0 on succes , -1 on fail
 */
int interactive(char **env)
{
	char *line = NULL, **commands = NULL;
	size_t size_line;
	ssize_t numchar;
	pid_t pid;
	int status;
	bool ejecuto = false;
	/* ========== S H E L L B M _ $ ==========*/
	signal(SIGINT, sighandle);
	while ((numchar = getline(&line, &size_line, stdin)))
	{
		if (numchar == EOF)/*=== CHECK END OF FILE ====*/
			ctrl_d(line);
		commands = get_commands(line);
		pid = fork();
		if (pid == -1)
			Error_fork(line, commands);
		if (pid == 0)
		{
			ejecuto = execute_command(commands, line, env);
			if (ejecuto == false)
			{
				perror("no encontro comando");
				free(line), free_arrays(commands), exit(EXIT_FAILURE);
			}
		}
		else
		{
			wait(&status);
			if (commands == NULL)
			free(line), free_arrays(commands);
			else if ((_strcmp("exit", commands[0])) == 0)
			exit_shell(line, commands);
			else
				free_arrays(commands), free(line);
		}
		size_line = 0, line = NULL;
		if (isatty(STDIN_FILENO) == 1)
			write(STDOUT_FILENO, "ShellBM_$ ", 11);
	} /* === END OF WHILE === 🟥*/
	return (0);
}
/**
 * sighandle - function that handle signals
 * @n: unused attribute
 */

void sighandle(int n __attribute__((unused)))
{
	write(STDERR_FILENO, "\n", 1);
	write(STDERR_FILENO, "ShellBM_$ ", 11);
}
/**
 * ctrl_d - function that handle ctrl D signal
 * @line: command
 */
void ctrl_d(char *line)
{
        if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);
		free(line);
		exit(EXIT_SUCCESS);
}
/**
 * Error_fork -  function that exits when an error in fork
 * @line: argument
 * @commands: command given
 */
void Error_fork(char *line, char **commands)
{
	perror("Error:");
	free(line);
	free_arrays(commands);
	exit(EXIT_FAILURE);
}
