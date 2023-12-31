#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>

#define MAX_ARG_COUNT 1024

extern char **environ;

void prompt();
void execute_command(char **av);
int shell_loop();
char *get_path(char *cmd);
char **parse_input(char *line);
int handle_builtins(char **argv);
void handle_args(char *input, char ***av_ptr);

void type_cd(char *args);
void func_exit(void);
void env(void);

char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
int length(char *str);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);

#endif
