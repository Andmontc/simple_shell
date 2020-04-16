#include "shell.h"
/**
 * interactive - shell in interactive mode
 * Return: 0 on succes , -1 on fail
 */
int interactive(char **env)
{
	/** ======== 💎 V A R I A B L E S 💎 ==============*/
	char *line = NULL;
	char **commands = NULL;
	size_t size_line;
	ssize_t numchar;
	pid_t pid;
	int status;
	bool ejecuto = false;

	/*====🔴🔴🔴🔴🔴🔴🔴🔴🔴🔴🔴🔴🔴🔴🔴🔴======*/
	/* ========== S H E L L B M _ $ ==========*/
	/* ===🔴🔴🔴🔴🔴🔴🔴🔴🔴🔴🔴🔴🔴🔴🔴🔴======*/
	signal(SIGINT, sighandle);
	write(STDOUT_FILENO, "ShellBM_$ ", 11);
	while ((numchar = getline(&line, &size_line, stdin)))
	{
		if (numchar == EOF)/*=== CHECK END OF FILE ====*/
		ctrl_d(line);
		/**===== FUNCTIONS 🟢 =====*/
		commands = get_commands(line);
		pid = fork();
		if (pid == -1)
			perror("Cannot create FORK");
		if (pid == 0)
		{
			ejecuto = execute_command(commands, line, env);
			if (ejecuto == false)
			{
				printf("No encontro comando\n");
			}
		}
		else
		{
			wait(&status);
			if (commands == NULL)
			free(line), free_commands(commands);
			else if ((_strcmp("exit", commands[0])) == 0)
			exit_shell(line, commands);
			else
			{
				free_commands(commands);
				free(line);
			}
		}
		size_line = 0, line = NULL;
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
 * 
 * 
 * 
 */
void ctrl_d(char *line)
{
	write(STDOUT_FILENO, "\n", 1);
			free(line);
			exit (98);
}
