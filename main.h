#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/wait.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

/* main functionality */
void perform_cmd(void);
void execute(char *args[]);

/* buffer constants */
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

/* commands chaining */
#define CMD_NORM 0
#define CMD_OR 1
#define CMD_AND 2
#define CMD_CHAIN 3

/* to convert numbers */
#define CONVERT_LOWERCASE 1
#define CONVERT_UNSIGNED 2

/* if using system getline */
#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE ".simple_shell_history"
#define HIST_MAX 4096

extern char **environ;

/**
 * struct liststr - single linked list
 * @num: the number
 * @str: a string
 * @next: pointer to the next node
 */
typedef struct liststr
{
 int num;
 char *str;
 struct liststr *next;
} list_t;
/*
 * struct passinfo - contains pseudocode arguments
 * @arg: arguments as string
 * @argv: args array
 * @path: a path var for current command
 * @argc: argc
 * @line_count: line_count
 * @err_num: err_num
 * @linecount_flag: linecount_flag
 * @fname: fname
 * @env: env
 * @environ: environ
 * @history: history var
 * @alias: alias to a node
 * @env_changed: bool if environ changed
 * @status: status
 * @cmd_buf: cmd buffer
 * @cmd_buf_type: cmd buffer type
 * @readfd: read line input
 * @histcount: history number line count
 */
typedef struct passinfo
{
    char *arg;
    char **argv;
    char *path;
    int argc;
    unsigned int line_count;
    int err_num;
    int linecount_flag;
    char *fname;
    list_t *env;
    list_t *history;
    list_t *alias;
    char **environ;
    int env_changed;
    int status;
    char **cmd_buf;
    int cmd_buf_type;
    int readfd;
    int histcount;
} info_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
 0, 0, 0}

/*
 * struct builtin - builtin  string
 * @type: the type of the built in
 * @func: the function
 */
typedef struct builtin
{
    char *type;
    int (*func)(info_t *);
} builtin_table;

/* hsh.c */
int hsh(info_t *, char **);
int find_builtin(info_t *);
void find_cmd(info_t *);
void fork_path(info_t *);

/* path.c */
int is_cmd(info_t *, char *);
char *dup_chars(char *, int, int);
char *find_path(info_t *, char *, char *);

/* loophsh.c */
int loophsh(char **);

/* err_string_functions.c */
void _eputs(char *);
int _eputschar(char);
int _putfd(char, int);
int _putsfd(char *, int);

/* string_functions.c */
int _strlen(char *);
int _strcmp(char *, char *);
char *starts_with(const char *, const char *);
char *_strcat(char *, char *);

/* string_functions2.c */
char *_strcpy(char *, char *);
char *_strdup(const char *);
void _puts(char *);
int _putchar(char);

/* string_functions3.c */
char *_strncpy(char *, char *, int);
char *_strncat(char *, char *, int);
char *_strchr(char *, char);

/* string_functions4.c */
char **strtow(char *, char *);
char **strtow2(char *, char);

/* memory_functions.c */
char *_memset(char *, char, unsigned int);
void ffree(char **);
void *_realloc(void *, unsigned int, unsigned int);

/* memory_functions2.c */


#endif