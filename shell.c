#include "shell.h"

/**
 * prompt - displays prompt
 */

void prompt()
{
	printf("$ ");
}

/**
 * execute_command - executes the entered commands
 *
 * @command: entered commands
 * @args: command arguments
 */

void execute_command(char *command, char *args[])
{
	pid_t child_pid;
	int status;
	char *newenviron;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}

	if (child_pid == 0)
	{
		newenviron[] = { NULL };

		if (execve(command, args, newenviron) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(child_pid, &status, 0);
	}
}

/**
 * shell_loop - calls the prompt function to display the prompt and calls the execute_command function to execute the entered commands on every line.
 *
 * return: number of entered characters
 */

int shell_loop()
{
	char *line = NULL;
	size_t len = 0;
	ssize_t rchars = 0;
	char *token, *command, *args[rchars];
	int argCount = 0;

	while (rchars != -1)
	{
		prompt();
		rchars = getline(&line, &len, stdin);

		if (rchars != -1)
		{
			if (line[rchars - 1] == '\n')
				line[rchars - 1] = '\0';


			token = strtok(line, " ");

			if (token != NULL)
			{
				command = token;
			
				while ((token == strtok(NULL, " ")) != NULL)
				{
					args[argCount++] = token;
				}
				args[argCount] = NULL;

				execute_command(command, args);
			}
		}
		free(line);
		line = NULL;
	}

	free(line);

	return (rchars);
}

int main()
{
	int result = shell_loop();
	exit(EXIT_SUCCESS);
	return (result);
}
