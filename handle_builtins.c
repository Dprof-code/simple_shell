#include "shell.h"

/**
 * handle_ls - this function locates the ls executable
 *
 */

void handle_ls()
{
	char *ls_args[] = { "ls", NULL };
	char *ls_envp[] = { "PATH=/bin:/usr/bin", NULL };


	if (execve("/bin/ls", ls_args, ls_envp) == -1)
	{
		perror("execve");
		exit(EXIT_FAILURE);
	}
}
