#include "shell.h"
/**
 * get_path - function that gets the path
 * @string_rutas: path given
 * Return: the paths tokenized
 */
char **get_path(char *string_rutas)
{
	int i, m = 0;
	int words = 0;
	char *firts_path;
	char **paths = NULL;

	for (m = 0; string_rutas[m] != '\0'; m++)
	{
		if (string_rutas[m + 1] == ':' || string_rutas[m + 1] == '\0')
			words++;
	}
	if (words == 0)
		return (NULL);

	paths = malloc(sizeof(char *) * (words + 1));
	if (paths == NULL)
		return (NULL);
	firts_path = strtok(string_rutas, ":");
	i = 0;
	while (firts_path != NULL)
	{
		paths[i] = malloc(sizeof(char) * (_strlen(firts_path) + 1));
		if (paths[i] == NULL)
		{
			_free(paths);
			return (NULL);
		}
		_strncpy(paths[i], firts_path, _strlen(firts_path) + 1);
		firts_path = strtok(NULL, ":");
		i++;
	}
	paths[i] = '\0';
return (paths);
}
