**Description** 📋

Welcome to our SHELLBM_ project ! This project is about making our own (CLI) Command Line Interpreter using  C programming languaje , it was faced in a critical and challenge way.

Modeled after the first Unix shell by Ken Thompson, the ShellBM handles commands located in the $PATH and supports a number of additional,built-in features listed below.

Getting Started
A starter's guide to setting up sharpiesh.

> Use git clone to get our code in your local machine and see how it works.

```
git clone https://github.com/Andmontc/simple_shell
```

> Usage

```
gcc -Wall -Wextra -Werror -pedantic -Wno-format *.c -o shbm
```



**Functions prototype** ⬇︎

```
/*📖 I N T E R A C T I V E  A N D  N O I N T E R A C T I V E */
int interactive(char **env);
/** M A I N 🟥 F U N C T I O N S */
/** Function that try every route to execve 🔷 */
bool exec_routes(char **commands, char *line, char **env);
/** ↪️ Function that concatenate the paths and commands */
char **get_routes(char **commands, char **env);
/** Function that extract from environment PATH at the correct index 💡 */
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
```

**Output** 🛠

```

```



## Testing cases. ⚙️

3. Use 
   ShellBM should now be ready to use. To start the shell in interactive mode, please use the following command:

   ./shbm
   You should now see a ShellBM_$, in wait mode , waiting for the user to input a command.

   Executing Commands
   The ShellBM can execute many commands.

Below are some examples of things you can try.

▶️	ls -l
	ls lists the contents of your current directory. The -l flag specifies the listing should be in long format.

Output ⬇️

`ShellBM_$ ls -l`

```c
total 68
-rw-rw-r-- 1 vagrant vagrant  218 Apr 16 23:29 AUTHORS
-rw-rw-r-- 1 vagrant vagrant 3335 Apr 16 23:29 README.md
-rw-rw-r-- 1 vagrant vagrant  431 Apr 16 23:29 _getenv.c
-rw-rw-r-- 1 vagrant vagrant  500 Apr 16 23:29 builtins_functions.c
-rw-rw-r-- 1 vagrant vagrant 1164 Apr 17 00:12 execute_command.c
-rw-rw-r-- 1 vagrant vagrant  851 Apr 17 00:15 execute_routes.c
-rw-rw-r-- 1 vagrant vagrant 1590 Apr 16 23:29 functions.c
-rw-rw-r-- 1 vagrant vagrant 1030 Apr 16 23:48 get_commands.c
-rw-rw-r-- 1 vagrant vagrant 1214 Apr 16 23:29 get_routes.c
-rwxrwxr-x 1 vagrant vagrant 14322 Apr 17 00:25 hsh
-rw-rw-r-- 1 vagrant vagrant  402 Apr 17 00:53 main.c
-rw-rw-r-- 1 vagrant vagrant 2042 Apr 16 23:29 man_1_simple_shell
-rw-rw-r-- 1 vagrant vagrant 1771 Apr 17 00:21 prompt_.c
-rw-rw-r-- 1 vagrant vagrant 1252 Apr 17 00:10 shell.h
```

