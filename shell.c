#include "shell.h"

/**
 * prompt - displays prompt
 */

void prompt(void)
{
	char *prompt = "$ ";

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, prompt, _strlen(prompt));
}

/**
 * parse_input - Parse the user input into tokens
 *
 * @line: pointer to a character
 * Return: Parsed arguments
 */
char **parse_input(char *line)
{
	char **argv = NULL;

	handle_args(line, &argv);
	return (argv);
}

/**
 * execute_command - executes the entered commands
 *
 * @av: command arguments
 */

void execute_command(char **av)
{
	char *cmd = NULL, *passed_cmd = NULL;
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (child_pid == 0)
	{
		cmd = av[0];
		passed_cmd = get_path(cmd);

		if (passed_cmd == NULL)
		{
			perror("No such file or directory");
			exit(EXIT_FAILURE);
		}
		if (execve(passed_cmd, av, NULL) == -1)
		{
			perror("execve");
			free(passed_cmd);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(NULL);
	}
}

/**
 * shell_loop - calls the prompt function to display the prompt
 * and calls functions to execute entered commands
 *
 * Return: 0
 */

int shell_loop(void)
{
	char *line = NULL, **argv;
	size_t buff = 0;
	ssize_t rchars;
	int i, status;

	while (1)
	{
		prompt();
		rchars = getline(&line, &buff, stdin);

		if (rchars ==  -1)
		{
			if (!feof(stdin))
				perror("getline");
			break;
		}

		argv = parse_input(line);
		status = handle_builtins(argv);

		if (argv != NULL)
		{
			for (i = 0; argv[i] != NULL; i++)
				free(argv[i]);
			free(argv);
		}
		free(line);
		line = NULL;

		if (status == -1)
			break;
	}
	free(line);
	return (0);
}

/**
 * main - entry point of the shell program
 *
 * Return: 0
 */
int main(void)
{
	int result = shell_loop();

	exit(EXIT_SUCCESS);
	return (result);
}
