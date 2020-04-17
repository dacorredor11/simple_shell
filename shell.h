#ifndef SHELL_H
#define SHELL_H

extern char **environ;
#define _GNU_SOURCE

/* libraries */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>

/* End */

/* Structs */

/**
 * struct path - linked list for PATH
 * @route: path in the format /usr/bin
 * @next: pointer to next node
 */
typedef struct path
{
	char *route;
	struct path *next;
} path_t;

/**
 * struct builtin_commands - match system for function pointers & builtin cmds
 * @cmd_token: builtin command
 * @function: respective function
 */
typedef struct builtin_commands
{
	char *cmd_token;
	int (*function)();
} builtin_cmds_t;

/* End */

/* String functions */

int _strcmp(char *s1, char *s2);
char *_strncat(char *dest, char *src, int n);
int _strlen(char *s);
char *str_concat(char *s1, char *s2);
char *_strchr(char *s, char c);
int _strcmp(char *s1, char *s2);
unsigned int _strspn(char *s, char *accept);
char *_strpbrk(char *s, char *accept);
size_t _strcspn(const char *s1, const char *s2);
char *_strdup(char *str);
int _strncmp(const char *first, const char *last, size_t count);

/* End */

/* Structs functions */

path_t *add_node(path_t **head, char *str);
void free_list(path_t *head);

/* End */

/* print functions */

int _putchar(char c);
void _puts(char *str);
void print_error(char *exec, int num, char *error);

/* End */

/* Signal functions */

void signal_handler(int sig);
void eof(char *buffer, int erno);
void print_error_code(char *exec, int num, char *error);
void print_exit_code(char *exec, int num, char *error);

/* End  */

/* Built in functions */


/* End */

/* Buffer handler functions */

int count_buffer(char *buffer);
char **create_exec_buffer(char *buffer);
int validate_buffer(char *buffer, int err_counter);
int exec_command(char **buffer, char *exec, int err_counter);

/* End */

/* Shell & Path functions */

path_t *get_path(void);
int lexer(char *values[]);
char *_getenv(char *envp);
int validate_command(char **buffer, char *exec, int err_counter);
size_t _getline(char **lineptr, size_t *n, FILE *stream);
char *get_route(char *command);
char *_strtok(char *str, char *delim);
int env(void);

/* End */

#endif
