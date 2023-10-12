#include "shell.h"

/**
 * prompt - displays prompt
 */

void prompt(void)
{
	char *prompt = "$ ";

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, prompt, strlen(prompt));
}

/**
 * execute_command - executes the entered commands
 *
 * @command: entered commands
 * @args: command arguments
 */

void execute_command(char *command, char *args[], char *custom_envp[])
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}

	if (child_pid == 0)
	{
		if (execve(command, args, custom_envp) == -1)
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
	char *token;
	char *command;
	char *args[MAX_ARG_COUNT];
	int argCount = 0;

	char *custom_envp[] = {
		"PATH=/bin/ls",
		NULL
	};

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

				while (argCount < MAX_ARG_COUNT - 1 && (token = strtok(NULL, " ")) != NULL)
				{
					args[argCount] = token;
					argCount++;
				}
				args[argCount] = NULL;

				execute_command(command, args, custom_envp);
			}
		}
		free(line);
		line = NULL;
	}
	printf("\n");

	free(line);

	return (rchars);
}

int main()
{
	int result = shell_loop();
	exit(EXIT_SUCCESS);
	return (result);
}
