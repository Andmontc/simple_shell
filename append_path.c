#include "shell.h"
/**
 * append_path - function that concatenates the path and the command
 * @path: path given
 * @comands: comands givev
 * Return: concatenation
 */
char **append_path(char **path, char **comands)
{
	int i, j = 0;
	char **final_paths;
	int pathsquantity = 0;
	int lenpath, lencmd;

	while (path[pathsquantity] != NULL)
	{
		pathsquantity++;
	}
	final_paths = malloc(sizeof(char *) * (pathsquantity + 1));
	if (final_paths == NULL)
	{
		free(final_paths);
		return (NULL);
	}
	i = 0;
	lencmd = _strlen(comands[0]);
	while (path[i] != NULL)
	{
		lenpath = _strlen(path[i]);
		final_paths[i] = malloc(sizeof(char) * (lenpath + lencmd) + 1);
		if (final_paths[i] == NULL)
		{
			_free(final_paths);
			return (NULL);
		}
		_strcpy(final_paths[i], path[i]);
		_strncat(final_paths[i], "/", 1);
		_strncat(final_paths[i], comands[j], _strlen(comands[j]));
		i++;
	}
	final_paths[i] = '\0';
	pathsquantity = 0;
	i = 0;
	return (final_paths);
}
