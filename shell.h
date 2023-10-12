#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_ARG_COUNT 5

void prompt();
void execute_command(char *command, char *args[], char *custom_envp[]);
int shell_loop();

void handle_ls();

#endif
