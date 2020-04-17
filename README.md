

                     _   _    ___    _       ____    _____   ____    _____    ___    _   _ 
                    | | | |  / _ \  | |     | __ )  | ____| |  _ \  |_   _|  / _ \  | \ | |
                    | |_| | | | | | | |     |  _ \  |  _|   | |_) |   | |   | | | | |  \| |
                    |  _  | | |_| | | |___  | |_) | | |___  |  _ <    | |   | |_| | | |\  |
                    |_| |_|  \___/  |_____| |____/  |_____| |_| \_\   |_|    \___/  |_| \_|
                               ____     ____   _   _    ___     ___    _      
                              / ___|   / ___| | | | |  / _ \   / _ \  | |     
                              \___ \  | |     | |_| | | | | | | | | | | |     
                               ___) | | |___  |  _  | | |_| | | |_| | | |___  
                              |____/   \____| |_| |_|  \___/   \___/  |_____| 
                  ____  _   _ _____ _     _       ____  ____   ___      _ _____ ____ _____  
                 / ___|| | | | ____| |   | |     |  _ \|  _ \ / _ \    | | ____/ ___|_   _| 
                 \___ \| |_| |  _| | |   | |     | |_) | |_) | | | |_  | |  _|| |     | |   
                  ___) |  _  | |___| |___| |___  |  __/|  _ <| |_| | |_| | |__| |___  | |   
                 |____/|_| |_|_____|_____|_____| |_|   |_| \_\\___/ \___/|_____\____| |_|
                 


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
 ____  _   _ _____ _     _     ____  __  __      
/ ___|| | | | ____| |   | |   | __ )|  \/  |     
\___ \| |_| |  _| | |   | |   |  _ \| |\/| |     
 ___) |  _  | |___| |___| |___| |_) | |  | |     
|____/|_| |_|_____|_____|_____|____/|_|  |_|____ 
                                          |_____|

/*📖 I N T E R A C T I V E  A N D  N O  I N T E R A C T I V E */

int interactive(char **env);

/** M A I N 🟥 F U N C T I O N S */

/** Function that try every route to execve 🔷 */
bool exec_routes(char **commands, char *line, char **env);

/** ↪️ Function that concatenate the paths and commands */
char **get_routes(char **commands, char **env);

/** Function that extract from environment PATH at the correct index 💡 */
char *get_path_id(char **env);

/** Function that try execute built in and absolute routes ie. /bin/ls ☎️ */
bool execute_command(char **commands, char *line, char **env);

/** Function that tokenize into array the commands ie. ls -la */
char **get_commands(char *line);

/** Function that show that fork proccess fail ❌ */ 
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



## Testing cases. ⚙️

##  
ShellBM should now be ready to use. To start the shell in interactive mode, please use the following command:

```cassandra

./shbm
```


You should now see a ShellBM_$, in wait mode , waiting for the user to input a command.

Executing Commands
The ShellBM can execute many commands.

Below are some examples of things you can try.

 🏁 **- ls lists the contents of your current directory. The -l flag specifies the listing should be in long format.**

➕ Command:  ls -l

```CQL
 ____  _   _ _____ _     _     ____  __  __      
/ ___|| | | | ____| |   | |   | __ )|  \/  |     
\___ \| |_| |  _| | |   | |   |  _ \| |\/| |     
 ___) |  _  | |___| |___| |___| |_) | |  | |     
|____/|_| |_|_____|_____|_____|____/|_|  |_|____ 
                                          |_____|

ShellBM_$ ls -l
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



 🏁**- echo displays a line of text. It takes a string of characters to be displayed as an argument.**

➕ Command:  echo anything

```
 ____  _   _ _____ _     _     ____  __  __      
/ ___|| | | | ____| |   | |   | __ )|  \/  |     
\___ \| |_| |  _| | |   | |   |  _ \| |\/| |     
 ___) |  _  | |___| |___| |___| |_) | |  | |     
|____/|_| |_|_____|_____|_____|____/|_|  |_|____ 
                                          |_____|

ShellBM_$ echo anything
anything
```



🏁 - **touch creates a new file in the current directory. It takes a file name, such as file.txt as an argument.**

➕ Command:  touch file.txt

```c++
 ____  _   _ _____ _     _     ____  __  __      
/ ___|| | | | ____| |   | |   | __ )|  \/  |     
\___ \| |_| |  _| | |   | |   |  _ \| |\/| |     
 ___) |  _  | |___| |___| |___| |_) | |  | |     
|____/|_| |_|_____|_____|_____|____/|_|  |_|____ 
                                          |_____|

ShellBM_$ touch file.txt
ShellBM_$ ls
a.out  file.txt  shell.c  simple_shell	
```




 🏁 **- rm deletes a file. It takes a file name, such as file.txt as an argument.**

➕ Command: rm file.txt

```c++
 ____  _   _ _____ _     _     ____  __  __      
/ ___|| | | | ____| |   | |   | __ )|  \/  |     
\___ \| |_| |  _| | |   | |   |  _ \| |\/| |     
 ___) |  _  | |___| |___| |___| |_) | |  | |     
|____/|_| |_|_____|_____|_____|____/|_|  |_|____ 
                                          |_____|

ShellBM_$ rm file.txt
ShellBM_$ls
a.out  shell.c  simple_shell
```



**🏁 - man**
To view documentation on each command, you can use man followed by the command you would like to know more about.

```c++
 ____  _   _ _____ _     _     ____  __  __      
/ ___|| | | | ____| |   | |   | __ )|  \/  |     
\___ \| |_| |  _| | |   | |   |  _ \| |\/| |     
 ___) |  _  | |___| |___| |___| |_) | |  | |     
|____/|_| |_|_____|_____|_____|____/|_|  |_|____ 
                                          |_____|

ShellBM_$ man rm 
```



**Interactive vs. Non-Interactive Mode**
You can use the shell in both interactive and non-interactive mode. The examples above are done in interactive mode. You can tell because the shell runs continuously, awaiting and executing commands, until you explicitly exit.

Non-interactive mode, however, is when you indirectly feed commands into the executable bmsh file from outside the shell. For example, we can list files by indirectly piping ls into hsh using echo:

```c++
 ____  _   _ _____ _     _     ____  __  __      
/ ___|| | | | ____| |   | |   | __ )|  \/  |     
\___ \| |_| |  _| | |   | |   |  _ \| |\/| |     
 ___) |  _  | |___| |___| |___| |_) | |  | |     
|____/|_| |_|_____|_____|_____|____/|_|  |_|____ 
                                          |_____|

$ echo "ls" | ./hsh
a.out  shell.c  simple_shell	stuff.txt
```

🛠 **Used tools**


| Language:             | C                    |
| --------------------- | -------------------- |
| **Operating System:** | **Ubuntu 14.04 LTS** |
| **Compiler version:** | **gcc 4.8.4**        |
| **Style guidelines:** | **Betty**            |



```
 _____   _   _      _      _   _   _  __   __   __   ___    _   _  
|_   _| | | | |    / \    | \ | | | |/ /   \ \ / /  / _ \  | | | | 
  | |   | |_| |   / _ \   |  \| | | ' /     \ V /  | | | | | | | | 
  | |   |  _  |  / ___ \  | |\  | | . \      | |   | |_| | | |_| | 
  |_|   |_| |_| /_/   \_\ |_| \_| |_|\_\     |_|    \___/   \___/  
                                                                  
```




👨🏻‍💻 Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

**Developed by**:

**Oscar Andres Montes** - *GitHub user* ➞ 🖥 [Andmontc](https://github.com/Andmontc)

**Juan Sebastian Bueno** - *GitHub user* ➞ 🖥 [sebastianbm9507](https://github.com/sebastianbm9507)

**April/14/2020**
