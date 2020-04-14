#include "shell.h"
/**
 * main - shell main function
 * @argc: number of args
 * @argv: commands
 * Return: sucess
 */
int main(int argc, char *argv[])
{
	int x = 1, mode;
	char *line, *string_rutas;
	char **commands, **split_path, **final_paths;

	if (argc > 1)
		dprintf(STDERR_FILENO, "bash error: can't open %s\n", argv[1]), exit(127);
	signal(SIGINT, sighandle);
	do {
		mode = isatty(STDIN_FILENO);
		if (mode == 1) /** Modo interactivo */
			write(STDOUT_FILENO, "ShellBM$ ", 10);
		line = readline();
		if (*line != '\n')
		{
			commands = get_tokens(line); /** return array with split commands */
			if (check_builtins(line, commands, final_paths) == 1)
			{
				_free(commands), free(line);
				_free(split_path), free(string_rutas);
				x = 0;
			}
			else
			{
				string_rutas = _getenv();/**return string rutas sin split*/
				split_path = get_path(string_rutas);/** return split array string_rutas */
				final_paths = append_path(split_path, commands);
				execute_command(commands, final_paths);
				x = 0;
				_free(commands), free(line);
			}
			if (mode == 0)
				exit(EXIT_SUCCESS);
		}
		free(string_rutas), _free(split_path);
	} while (x == 0);
return (0);
}
/**
 * sighandle - function that handle signals
 * @n: unused attribute
 */
void sighandle(int n __attribute__((unused)))
{
	write(STDERR_FILENO, "\n", 1);
	write(STDERR_FILENO, "ShellBM$ ", 10);
}
