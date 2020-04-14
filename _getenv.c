#include "shell.h"
/**
 * _getenv - function that gets the enviroment
 * Return: the enviroment captured
*/
char *_getenv(void)
{
	int len;
	int i, j;
	int found = 0;
	char *string_rutas = NULL;
	char *compare = "PATH";

for (i = 0; environ[i] != NULL; i++)
{
	if (found == 4)
		break;
	for (j = 0; environ[i][j] != '\0' && j < 5; j++)
	{
		if (environ[i][j] == compare[j])
		{
			found++;
			if (found == 4)
			{
				len = strlen(environ[i]);
				string_rutas = limpiar(i, len);
				break;
			}
		}
	}
}
return (string_rutas);
}
/**
 * limpiar - function that cleans the path
 * @i: number of paths
 * @len: lenght of the paths
 * Return: path cleaned
 */
char *limpiar(int i, int len)
{
	int m = 0, l = 5;
	char *rutas = NULL;

	rutas = malloc(sizeof(char) * (len + 1));

if (!rutas)
{
	free(rutas);
	return (NULL);
}
for ( ; environ[i][l] != '\0'; m++, l++)
{
	rutas[m] = environ[i][l];
}
rutas[m] = '\0';
return (rutas);
}
