#include "shell.h"
/**
 * 
 * 
 * 
 */
int non_interactive(int argc ,char **argv, char **env)
{
	char *line = NULL;
	char **commands = NULL;
	size_t size_line;
	ssize_t numchar;
	pid_t pid;
	int status;


	if (argc > 1 )
	{
		printf("argv[0] %s\n", argv[0]);
	}
	numchar = getline(&line, &size_line, stdin);
	
	while (numchar != -1)
	{
		if (*line != '\n')
		{
			/**===== FUNCTIONS 🟢 =====*/
			commands = get_commands(line); /* 🚩RETURN ARRAY WITH  SPLIT COMMANDS */
	
				/** 👶🏻C R E A T E   C H I L D  🚸 P R O C E S S 👶🏻==*/
				pid = fork();
				if (pid == 0)
				{
					if (execve(commands[0], commands, env) == -1)
					{
						perror("Error:");
					}
				}
				else
				{
					wait(&status);
					free(commands);
				}
					/** 👶🏻 E N D   O F   C H I L D  🚸 P R O C E S S 👶🏻==*/
		}
		numchar = getline(&line, &size_line, stdin);
	}
return (0);
}
