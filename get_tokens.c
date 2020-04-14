#include "shell.h"
/**
 * get_tokens - Function that tokenize the commands
 * @line: getline line
 * Return: commands tokenized
 */
char **get_tokens(char *line)
{
	int i, m, words = 0;
	char *token = NULL;
	char **tokens = NULL;

		line[_strlen(line) - 1] = '\0';
		/* Counting number of delimiters to know how many spaces will be open  */
		for (m = 0; line[m] != '\0'; m++)
		{
			if (line[m] != ' ')
			{
				if (line[m + 1] == ' ' || line[m + 1] == '\0')
				words++;
			}
		}

		if (words == 0)
			return (NULL);
		tokens = malloc(sizeof(char *) * (words + 1));
		if (tokens == NULL)
			return (NULL);
		token = strtok(line, DELIM);
		i = 0;
		while (token != NULL)
		{
			tokens[i] = malloc(_strlen(token) + 1);
			if (tokens[i] == NULL)
			{
				_free(tokens);
				return (NULL);
			}
			_strncpy(tokens[i], token, _strlen(token) + 1);
			token = strtok(NULL, DELIM);
			i++;
		}
		tokens[i] = '\0';
		return (tokens);
}
