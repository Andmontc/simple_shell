#ifndef _SHELL_H
#define _SHELL_H

/* librerias */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdarg.h>

/*global variable */
extern char **environ;


/* Funciones */
int interactive(char **env);
int non_interactive(int argc ,char **argv, char **env);

bool execute_command(char **commands, char *line, char **env);
char **get_routes(char **commands, char **env);
char *get_path_id(char **env);
bool concat_commands(char **commands, char *line, char **env);
char **get_commands(char *line);


void free_commands(char **commands);

void sighandle(int n __attribute__((unused)));
void ctrl_d(char *line);

void exit_shell(char *line, char **cmd);
void print_env();


int _strlen(char *str);
int _strcmp(char *s1, char *s2);
char *_strncat(char *dest, char *src, int n);
char *_strcpy(char *dest, char *src);
char *_strncpy(char *dest, char *src, int n);

#endif
