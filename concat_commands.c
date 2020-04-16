#include "shell.h"
/**
 * 
 * 
 * 
 * 
 * 
 */
bool concat_commands(char **commands, char *line, char **env)
{
    char **path_dir = NULL;
    int i = 0;

    path_dir = get_routes(commands, env);
    while (path_dir[i] != NULL)
    {
        if (access(path_dir[i], X_OK) == 0)
            execve(path_dir[i], commands, NULL);
        i++;
    }
    if (path_dir[i] ==  NULL)
    {
        free_commands(path_dir);
        return (false);
    }
    free(line);
    free_commands(path_dir);
    free_commands(commands);
    exit(EXIT_SUCCESS);
}