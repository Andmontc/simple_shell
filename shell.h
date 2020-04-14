#ifndef _SHELL_H
#define _SHELL_H
#define DELIM " "

/* librerias */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/wait.h>

/*global variable */
extern char **environ;

/* structs */
/**
 * struct builtins - Struct for built-in
 * @op: operator
 * @f: function
 */
typedef struct builtins
{
	char *op;
	void (*f)(char *l, char **c, char **fp);
} built;

/* Funciones */
int _strlen(char *str);
int _strcmp(char *s1, char *s2);
ssize_t getline(char **lineptr, size_t *n, FILE *stream);
char *_getenv();
char *limpiar(int i, int len);
char *readline(void);
char **get_tokens(char *line);
char **get_path(char *line_path);
void *_realloc(void *ptr, unsigned int new_size);
char **append_path(char **path, char **comands);
char *_strncat(char *dest, char *src, int n);
char *_strcpy(char *dest, char *src);
void _free(char **freearg);
void sighandle(int n __attribute__((unused)));
char *_strncpy(char *dest, char *src, int n);
int check_builtins(char *line, char **cmd, char **fp);
void execute_command(char **commands, char **final_paths);
void exit_shell(char *line, char **cmd, char **fp);
void print_env(char *line, char **cmd, char **fp);

#endif
