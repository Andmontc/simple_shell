# simple_shell
About
Modeled after the first Unix shell by Ken Thompson, the ShellBM handles commands located in the $PATH and supports a number of additional, built-in features listed below.

Built-In Commands
Built-in	Use
exit	exits the shell
env	prints the current environment
Contains no memory leaks

Getting Started
A starter's guide to setting up sharpiesh.

1. Install
To download a copy of the source code locally, please run the following command in your terminal:

$ git clone https://github.com/Andmontc/simple_shell.git
2. Compile
After downloading the source code, you can use the following command to compile a working version of the shell:

gcc -Wall -Werror -Wextra -pedantic *.c -o shbm

3. Use
ShellBM should now be ready to use. To start the shell in interactive mode, please use the following command:

./shbm
You should now see a ShellBM_$, in wait mode , waiting for the user to input a command.

Executing Commands
The ShellBM can execute many commands.

Below are some examples of things you can try.

ls -l
ls lists the contents of your current directory. The -l flag specifies the listing should be in long format.

ShellBM_$ ls -l
total 108
-rw-rw-r-- 1 vagrant vagrant  1065 Apr 16 03:02 append_path.c
-rw-rw-r-- 1 vagrant vagrant   218 Apr 15 04:11 AUTHORS
-rw-rw-r-- 1 vagrant vagrant   599 Apr 15 23:28 builtins_functions.c
-rw-rw-r-- 1 vagrant vagrant  1085 Apr 15 23:28 execute_command.c
-rw-rw-r-- 1 vagrant vagrant  1590 Apr 15 23:28 functions.c
-rw-rw-r-- 1 vagrant vagrant   927 Apr 15 23:54 _getenv.c
-rw-rw-r-- 1 vagrant vagrant   834 Apr 15 23:54 _get_path.c
-rw-rw-r-- 1 vagrant vagrant   936 Apr 15 23:28 get_tokens.c
-rw-rw-r-- 1 vagrant vagrant   313 Apr 15 23:29 main.c
-rw-rw-r-- 1 vagrant vagrant  2042 Apr 15 23:09 man_1_simple_shell
-rw-rw-r-- 1 vagrant vagrant   867 Apr 15 23:28 no_interactivemode.c
-rw-rw-r-- 1 vagrant vagrant  2348 Apr 16 03:03 prompt_.c
-rw-rw-r-- 1 vagrant vagrant  3038 Apr 16 16:38 README.md
-rw-rw-r-- 1 vagrant vagrant  1050 Apr 15 23:28 shell.h

echo anything
echo displays a line of text. It takes a string of characters to be displayed as an argument.

ShellBM_$ echo anything
anything

touch file.txt
touch creates a new file in the current directory. It takes a file name, such as file.txt as an argument.

ShellBM_$ touch file.txt
ShellBM_$ ls
a.out  file.txt  shell.c  simple_shell	

rm file.txt
rm deletes a file. It takes a file name, such as file.txt as an argument.

$ rm file.txt
$ ls
a.out  shell.c  simple_shell

exit
exit exits the shell.

$ exit
vagrant@vagrant-ubuntu-trusty-64:~/simple_shell$

man
To view documentation on each command, you can use man followed by the command you would like to know more about.

Interactive vs. Non-Interactive Mode
You can use the shell in both interactive and non-interactive mode. The examples above are done in interactive mode. You can tell because the shell runs continuously, awaiting and executing commands, until you explicitly exit.

Non-interactive mode, however, is when you indirectly feed commands into the executable bmsh file from outside the shell. For example, we can list files by indirectly piping ls into hsh using echo:

$ echo "ls" | ./hsh
a.out  shell.c  simple_shell	stuff.txt

Feature	Version
Language	C
Operating System	Ubuntu 14.04 LTS
Compiler	gcc 4.8.4
Style Guidelines	Betty
