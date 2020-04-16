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


/*📖 I N T E R A C T I V E  A N D  N O I N T E R A C T I V E */
int interactive(char **env);
int non_interactive(int argc, char **argv, char **env);
/** M A I N 🟥 F U N C T I O N S */
bool exec_routes(char **commands, char *line, char **env);
char **get_routes(char **commands, char **env);
char *get_path_id(char **env);
bool execute_command(char **commands, char *line, char **env);
char **get_commands(char *line);
void Error_fork(char *line, char **commands);
/** 🆓F R E E  M E M O R Y */
void free_arrays(char **array);
/* 🏁S I G N A L  H A N D L E R  */
void sighandle(int n __attribute__((unused)));
void ctrl_d(char *line);
/* 🛠 B U I L T  I N S   F U C T I O N S */
void exit_shell(char *line, char **cmd);
void print_env(void);

/** 🅰️ S T R I N G S   F U C T I O N S 🅰️*/
int _strlen(char *str);
int _strcmp(char *s1, char *s2);
char *_strncat(char *dest, char *src, int n);
char *_strcpy(char *dest, char *src);
char *_strncpy(char *dest, char *src, int n);

#endif
