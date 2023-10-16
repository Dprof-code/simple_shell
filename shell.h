#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define MAX_ARG_COUNT 5

void prompt();
void execute_command(char *args[]);
int shell_loop();
char *get_path(char *cmd);
char **parse_input(char *line);
int handle_builtins(char **argv);
void handle_args(char *input, char ***av_ptr);

void handle_ls();

#endif
