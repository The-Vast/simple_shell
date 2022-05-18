#ifndef _SHELL_H_
#define _SHELL_H_

/*Standard Libs*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdarg.h>
#include <string.h>
/*System environment*/
extern char **environ;

/*BUFF SIZE*/
#define _SHIA_LA_BEAUF_ 1024

/*SHELL INSTANCE STAGES*/
#define _ERR_ 0
#define _NORMAL_ 1
#define _SKIP_ 2
#define _SHELL_END_ 3
#define _BUILT_IN_ 4
#define _PATH_NREADY_ 5
#define _PATH_READY_ 6

/*strings stuff*/
int _strlen(char *);
char *_strcpy(char *, char *);
int _strcmp(char *, char *);
char *_strstr(char *, char *);
char *_strcat(char *, char *);

int _unix_shell(void);

void exec_process(char *program, char **e_args);

char **tokeniser(char **buffer, char *pattern);
char *get_path_args(char *program);
char *generate_prompt_line(char *custom);

char *_find_env_get_value(char *key);
char *_find_x_path(char **env_paths, char *program);

unsigned int _is_arg_run_ready(char *arg);
char *_stralloc(int count, ...);

int _tokount(char *str, char *delim);
int run_built_in(char **args);
/*functions*/
int _exit_bin(char **);
int _bin_cd(char **);
int _bin_env(char **);

/*struct*/
/**
 * struct built_ins - command name and function to handle built-ins
 * @command: command name
 * @func: pointer to function
 *
 */
typedef struct built_ins
{
    char *command;
    int (*func)(char **);
} b_ins;
/*END OF BUILT-IN STUFF*/

/*COLOR CODES*/
#define _COLOR_RED_ "\x1B[31m"
#define _COLOR_GREEN_ "\x1B[32m"
#define _COLOR_YELLOW_ "\x1B[33m"
#define _COLOR_BLUE_ "\x1B[34m"
#define _COLOR_MAGENTA_ "\x1B[35m"
#define _COLOR_CYAN_ "\x1B[36m"
#define _BOLD_ "\x1B[1m"
#define _CLEAR_ "\x1B[0m"
#define UNUSED __attribute__((unused))

#endif
