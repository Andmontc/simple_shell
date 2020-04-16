#include "shell.h"
/**
 * get_path_id - function that gets the PATH
 * @env: enviroment
 * Return: the PATH POSITION captured into environment path
*/

char *get_path_id(char **env)
{
	int i, j;
	char compare[4] = "PATH";

	for (i = 0; env[i] != NULL; i++)
	{
		for (j = 0; compare[j] != '\0'; j++)
		{
			if (env[i][j] == compare[j])
				continue;
			else
				break;
		}
		if (compare[j] == '\0')
			break;
	}
	return (env[i]);
}
