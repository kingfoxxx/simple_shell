#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <signal.h>
#include <limits.h>
#include <fcntl.h>


#define BUFSIZE 1024
#define TOK_BUFSIZE 128
#define TOK_DELIM " \t\r\n\a"

/* The points to an array of pointers to strings called the "environment" */
extern char **environ;


/**
 * struct data - struct that contains all important data on runtime
 * @av: argument vector
 * @input: command lines written by the user
 * @args: tokens of the command line
 * @status: last status of the shell
 * @counter: lines counter
 * @_environ: environment variable
 * @pid: process ID of the shell
 */

typedef struct data

{

	char **av;
	char *input;
	char **args;
	int counter;
	int status;
	char **_environ;
	char *pid;
} data_shell;

/**
 * struct sep_list_s - let single linked lists be seperated
 * @separator: ; | &
 * @next: next node
 * Description: single linked list to store separators
 */

typedef struct sep_list_s

{
	char separator;
	struct sep_list_s *next;
} sep_list;

/**
 * struct line_list_s - single linked list
 * @line: command line
 * @next: next node
 * Description: single linked list to store command lines
 */

typedef struct line_list_s

{
	char *line;
	struct line_list_s *next;
} line_list;

/**
 * struct r_var_list - single linked list
 * @len_var: length of the variable
 * @val: value of the variable
 * @len_val: length of the value
 * @next: next node
 * Description: single linked list to store variables
 */

typedef struct r_var_list
{
	int len_var;
	char *val;
	int len_val;
	struct r_var_list *next;
} r_var;

/**
 * struct builtin_s - Builtin struct for command args in files.
 * @name: The name of the command builtin i.e cd, exit, env
 * @f: data type pointer function.
 */

typedef struct builtin_s

{
	char *name;
	int (*f)(data_shell *datash);
} builtin_t;

/* line_list.c */
sep_list *add_sep_node_end(sep_list **head, char sep);
void free_sep_list(sep_list **head);
line_list *add_line_node_end(line_list **head, char *line);
void free_line_list(line_list **head);

/* line_list1.c */
r_var *add_rvar_node(r_var **head, int lvar, char *var, int lval);
void free_rvar_list(r_var **head);

/* baux_str functions */
char *_strcat(char *dest, const char *src);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strchr(char *s, char c);
int _strspn(char *s, char *accept);

/* baux_mem.c */
void _memcpy(void *newptr, const void *ptr, unsigned int sign);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char **_reallocdp(char **ptr, unsigned int old_size, unsigned int new_size);

/* baux_str2.c */
char *_strdup(const char *s);
int _strlen(const char *s);
int cmp_chars(char str[], const char *delim);
char *_strtok(char str[], const char *delim);
int _isdigit(const char *s);

/* syntax_errors.c */
int repeated_char(char *input, int j);
int error_sep_op(char *input, int j, char last);
int first_char(char *input, int *j);
void print_syntax_error(data_shell *datash, char *input, int j, int bool);
int check_syntax_error(data_shell *datash, char *input);

/* shell_loops.c */
char *without_comment(char *in);
void shell_loop(data_shell *datash);

/* bread_line.c */
char *read_line(int *i_get);

/* split_shell.c */
char *swap_char(char *input, int bool);
void add_nodes(sep_list **head_s, line_list **head_l, char *input);
void go_next(sep_list **list_s, line_list **list_l, data_shell *datash);
int split_commands(data_shell *datash, char *input);
char **split_line(char *input);

/* rep_var.c */
void check_env(r_var **h, char *in, data_shell *data);
int check_vars(r_var **h, char *in, char *st, data_shell *data);
char *replaced_input(r_var **head, char *input, char *new_input, int xlen);
char *rep_var(char *input, data_shell *datash);

/* bget_line.c */
void bring_line(char **lineptr, size_t *n, char *buffer, size_t j);
ssize_t get_line(char **lineptr, size_t *n, FILE *stream);

/* envec_line */
int exec_line(data_shell *datash);

/* cmd_path.c */
int is_cdir(char *path, int *j);
char *_which(char *cmd, char **_environ);
int is_executable(data_shell *datash);
int check_error_cmd(char *dir, data_shell *datash);
int cmd_exec(data_shell *datash);

/* envec.c */
char *_getenv(const char *name, char **_environ);
int _env(data_shell *datash);

/* envec2.c */
char *copy_intro(char *name, char *index);
void set_env(char *name, char *index, data_shell *datash);
int _setenv(data_shell *datash);
int _unsetenv(data_shell *datash);

/* bcd.c */
void cd_dot(data_shell *datash);
void cd_to(data_shell *datash);
void cd_previous(data_shell *datash);
void cd_to_home(data_shell *datash);

/* cd_shell_dot.c */
int cd_shell(data_shell *datash);

/* bget_builtin */
int (*get_builtin(char *cmd))(data_shell *datash);

/* bexit_shell.c */
int exit_shell(data_shell *datash);

/* baux_stdlib.c */
int get_len(int n);
char *aux_itoa(int n);
int _atoi(char *s);

/* error_1.c */
char *strcat_cd(data_shell *, char *, char *, char *);
char *error_get_cd(data_shell *datash);
char *error_not_found(data_shell *datash);
char *error_exit_shell(data_shell *datash);

/* error_2.c */
char *error_get_alias(char **args);
char *error_env(data_shell *datash);
char *error_syntax(char **args);
char *error_permission(char **args);
char *error_path_208(data_shell *datash);


/* bget_error.c */
int get_error(data_shell *datash, int eval);

/* bget_sigint.c */
void get_sigint(int signals);

/* help_setenv.c */
void aux_help_env(void);
void aux_help_setenv(void);
void aux_help_unsetenv(void);
void aux_help_general(void);
void aux_help_exit(void);

/* aux_help0.c */
void aux_help(void);
void aux_help_alias(void);
void aux_help_cd(void);

/* bget_help.c */
int get_help(data_shell *datash);

/* baux_str3.c */
void rev_string(char *s);


#endif
