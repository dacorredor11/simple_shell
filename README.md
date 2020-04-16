# 0x16. C - Simple Shell

## Description
Holberton School project incorporating all topics covered so far about learning C programming.

The hsh is a simplified command line interpreter for the system, or shell, an aproach to the first Unix shell written by Ken Thompson. In that sence it reads lines from either a file or the terminal, interprets them, and generally executes other commands. Simple_shell is desgined to run on the linux environment.

## File Structure
* [AUTHORS](AUTHORS) - List of contributors to this repository
* [man_1_simple_shell](man_1_simple_shell) - Manual page for the simple_shell
* [shell.h](shell.h) - program header file
* [main.c](main.c) - Main shell file function
* [builtins.c](builtins.c) - major builtin functions
* `check_builtin` - checks if command is a builtin
* `arrlen` - finds size of array
* `exito` - if user types 'exit' exit shell
* [buffer_handling.c](buffer_handling.c) - functions related to store input
* `count_buffer` - Counts the number of words in a string
* `create_buffer` - creates a string with a given bidimensional array
* `create_exec_buffer` - creates a bidimensional array of strings
* [signal_handler.c](signal_handler.c) - functions related to reading signals
* `signal_handler` - handles signals from keyboard interrupts
* `eof` - end of file declaration
* [memory_funcs.c](memory_funcs.c) - memory allocation functions
* `malloc_checked` - allocates memory using malloc
* `_realloc` - reallocates a memory block using malloc and free.
* `_memset` - fill memory with a constant byte
* `_memcpy` - copies memory area
* `free_list` - Function that frees a list
* [string_funcs.c](string_funcs.c) - functions related to string manipulation
* `_strlen` - return the length of the string
* `_strcpy` - Copy the string `src` to `dest`
* `_strcmp` - Compare two strings
* `_strncmp` - Compare n bytes of two strings
* [string_funcs_2.c](string_funcs.c) - functions related to string manipulation
* `_strtok` - Split a string up into tokens
* `_strtok_r` - extract tokens from strings & hold index ptr (thread safe).
* [string_funcs_3.c](string_funcs.c) - functions related to string manipulation
* `_strchr` - locate character in a string
* `_strcspn` - search a string for a set of bytes
* `_strspn` - gets length of a prefix substring
* `_strdup` - duplicate a specific number of bytes from a string
* `_strbrk` - search a string for any of a set of bytes
* [string_funcs_4.c](string_funcs.c) - functions related to string manipulation
* `_putchar` - writes the character c to stdout
* `_puts` - writes the character c to stdout
* `word_count` - counts words given a char delimiter
* `_strncat` - concatenates two strings by n bytes
* `str_concat` - function that concatenates two strings
* [struct_funcs.c](struct_funcs.c) - functions related to struct manipulation
* `add_node` - function that adds a node
* `print_list` - Function to print a simple list
* [parser.c](parser.c) - lexical analyzer (lexer, tokenizer, scanner)
* `lexer` - Scan for standard input from terminal
* `validate_command` - Function that validates the command
* `get_route` - Function that brings the route of a command
* [getline.c](getline.c) - custom getline approach
* `_getline` - delimited string input
* `_fgets` - input of characters and strings
* `_getc` - reads char from stream and returns it as an int
* `_fgetc` - input of characters and strings
* [cpy_funcs.c](cpy_funcs.c) - functions related to environment
* `_getenv` - get an environment variable
* `get_dir` - get current working directory
* `get_path` - return the pathname

## Requirements
simple_shell is designed to run in the `Ubuntu 14.04 LTS` linux environment and to be compiled using the GNU compiler collection v. `gcc 4.8.4` with flags`-Wall, -Werror, -Wextra, and -pedantic.`

Only allowed to use the following functions and system calls:
```
access (man 2 access)
chdir (man 2 chdir)
close (man 2 close)
closedir (man 3 closedir)
execve (man 2 execve)
exit (man 3 exit)
fork (man 2 fork)
free (man 3 free)
fstat (man 2 fstat)
getcwd (man 3 getcwd)
getline (man 3 getline)
kill (man 2 kill)
lstat (man 2 lstat)
malloc (man 3 malloc)
open (man 2 open)
opendir (man 3 opendir)
perror (man 3 perror)
read (man 2 read)
readdir (man 3 readdir)
signal (man 2 signal)
stat (man 2 stat)
strtok (man 3 strtok)
wait (man 2 wait)
waitpid (man 2 waitpid)
wait3 (man 2 wait3)
wait4 (man 2 wait4)
write (man 2 write)
_exit (man 2 _exit)
```
## Usage
Clone this repository onto your local machine, compile with the flags listed below
```sh
git clone https://github.com/VIDMORE/simple_shell.git
cd simple_shell
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
```
Run the simple shell
```sh
./hsh
```
then you can use commands like in sh
```sh
$ ls -al
```
To exit the simple shell
```sh
exit
"or in keyboard Ctrl + D"
```
## Bugs
<img src="https://media.breitbart.com/media/2019/06/AP_060502025509-640x480.jpg" align="middle" width="100" height="100">

"21 Savage - a lot ft. J. Cole"
Please report any issues to the authors.
## Authors
David Alejandro Corredor Mora <vidmore8@gmail.com>

Santiago Efrain Martinez Leon <sntgmtnz@gmail.com>
## License
simple_shell is open source and therefore free to download and use without permission.
