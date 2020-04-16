#include "shell.h"
/**
 * get_routes - function that concatenates the path and the command
 * @commands: comands given
 * @env: enviroment
 * Return: concatenation
 */
char **get_routes(char **commands, char **env)
{
	char *path = NULL, **path_final = NULL, *token = NULL;
	int pathquantity = 0, d, i, comlen = 0, pathlen = 0, l, j;

	path = get_path_id(env);
	for (d = 0; path[d] != '\0'; d++)
	{
		if (path[d + 1] == ':' || path[d + 1] == '\0')
			pathquantity++;
	}
	path_final = malloc(sizeof(char *) * (pathquantity + 1));
	if (path_final == NULL)
		return (NULL);
	i = 0;
	token = strtok(path, ":");/*separate the path*/
	while (token != NULL)
	{
		pathlen = _strlen(token);
		comlen = _strlen(commands[0]);
		path_final[i] = malloc(sizeof(char) * (pathlen + comlen + 2));
		if (path_final[i] == NULL)
		{
			free_arrays(path_final);
			return (NULL);
		}
		else
		{
			for (l = 0; l < pathlen && token[l] != '\0'; l++)
				path_final[i][l] = token[l];
			path_final[i][l] = '/';
			l++;
			for (j = 0; j < comlen && commands[0][j] != '\0'; l++, j++)
				path_final[i][l] = commands[0][j];
			path_final[i][l] = '\0';
		}
		token = strtok(NULL, ":");
		i++;
	}
	path_final[i] = NULL;
	return (path_final);
}
