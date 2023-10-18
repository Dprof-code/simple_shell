#include "shell.h"

/**
 * handle_builtins - Handles builtins commands
 *
 * @argv: Array of arguments
 * Return: 0 on success
 */

int handle_builtins(char **argv)
{
	if (argv != NULL && argv[0] != NULL)
	{
		if (_strcmp(argv[0], "exit") == 0)
		{
			/*call exit function*/
			func_exit();
		}
		else if (_strcmp(argv[0], "cd") == 0)
		{
			/*call cd function*/
			type_cd(argv[1]);
		}
		else if (_strcmp(argv[0], "env") == 0)
		{
			/*call env function*/
			env();
		}
		else
		{
			execute_command(argv);
		}
	}

	return (0);
}

/**
 * handle_args - handles command lines with arguments.
 * @input: input from the command line
 * @av_ptr: pointer to arguments
 *
 * Return: Nothing
 */

void handle_args(char *input, char ***av_ptr)
{
	int ac = 0, capacity = 10;
	char **av, *token, **temp;

	av = malloc(capacity * sizeof(char *));

	if (av == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	token = strtok(input, " \t\n");
	while (token != NULL)
	{
		if (token[0] == '#')
			break;
		if (ac >= capacity)
		{
			capacity *= 2;
			temp = realloc(av, capacity * sizeof(char *));
			if (temp == NULL)
			{
				perror("realloc");
				exit(EXIT_FAILURE);
			}
			av = temp;
		}

		av[ac] = _strdup(token);
		if (av[ac] == NULL)
		{
			perror("strdup");
			exit(EXIT_FAILURE);
		}
		ac++;
		token = strtok(NULL, " \t\n");
	}
	av[ac] = NULL;
	*av_ptr = av;
}
