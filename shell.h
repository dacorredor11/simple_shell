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
char *_strchr(char *s, char c);
int _strcmp(char *s1, char *s2);
unsigned int _strspn(char *s, char *accept);
char *_strpbrk(char *s, char *accept);
size_t _strcspn(const char *s1, const char *s2);
char *_strdup(char *str);
char *e_strdup(char *os, char *str);

/* End */

/* Structs functions */

path_t *add_node(path_t **head, char *str);
size_t print_list(const path_t *h);
void free_list(path_t *head);

/* End */

/* print functions */

int _putchar(char c);
void _puts(char *str);
void print_error(char *exec, int num, char *error);

/* End */

/* Signal functions */

void signal_handler(int sig);
void eof(char *buffer);

/* End  */

/* Built in functions */

int arrlen(char **arrangement);
int exito(char **parsed);
void _cd(char *av[]);
int (*check_builtin(char *command))();

/* End */

/* Buffer handler functions */

char *disarm_buffer(char *buffer);
int count_buffer(char *buffer);
char *make_string(char **disarmed);
char *create_buffer(char **string);
char **create_exec_buffer(char *buffer);
int validate_buffer(char *buffer);

/* End */

/* Shell & Path functions */

path_t *get_path(void);
size_t check_path(const path_t *head, char *str2);
size_t exec_path(const path_t *head, char *str2);
void lexer(int num, char *values[]);
void get_dir(void);
char *_getenv(char *envp);
int validate_command(char **buffer, char *exec, int err_counter);
int one_param(char *buffer);
int is_flag(char *string);
size_t _getline(char **lineptr, size_t *n, FILE *stream);
char *_fgets(char *s, int size, FILE *stream);
int _getc(FILE *stream);
int _fgetc(FILE *stream);
char *get_route(char *command);
char *_strtok(char *str, char *delim);
void env(void);

/* End */

#endif
