#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/* main functionality */
void perform_cmd(void);
void execute(char *args[]);

/* string functions */
void _puts(char *s);
int _strlen(char *s);
char *_strdupp(char *s);
bool starts_with(char *s, char *prefix);
char *path_join(char *dir, char *file);

/* tokens */
char **tokenize(char *str, char *delim);
int count_tokens(char *str, char *delim);
bool is_delim(char c, char *delim);
void free_tokens(char **tokens);

/* environs */
char *_get_env(char *name);
void print_env(void);

/* globals */
char *prog_name;
char *environs[];
char *paths[];
bool exit_flag;

#endif
