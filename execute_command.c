#include "shell.h"
/**
 * execute_command - Function that executes a command
 * @commands: commands given
 * @final_paths: paths given
 */
void execute_command(char **commands, char **final_paths)
{
	pid_t pid;
	struct stat st;
	int status;
	int i;

	/**=========================================*/
	/**===C R E A T E  C H I L D   P R O C E S S ===*/
	/**=========================================*/
		pid = fork();
		if (pid == -1)
		perror("Fork");
		if (pid == 0)
		{
			bool ejecuto = false;

			i = 0;
				while (final_paths[i] != NULL)
				{
					/**---- C H E C K   N O  I N T E R A C T I V E   M O D E -----*/
					if (stat(commands[0], &st) == 0)
					{
						execve(commands[0], commands,  environ);
						ejecuto = true;
					}
					/**---- C H E C K   I N T E R A C T I V E   M O D E -----*/
					else if (stat(final_paths[i], &st) == 0)
					{
						execve(final_paths[i], commands, environ);
						_free(final_paths);
						ejecuto = true;
					}
					i++;
					}
					if (!ejecuto)
					perror("");
				}
				else
				{
				wait(&status);
				}
}
/**
 * _free - function that free memory
 * @commands: memory to free
 */
void _free(char **commands)
{
	unsigned int i;

	if (commands == NULL)
		return;

	for (i = 0; commands[i] != '\0'; i++)
		free(commands[i]);
	free(commands);
}

