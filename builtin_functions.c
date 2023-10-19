#include "shell.h"

/**
 * type_cd - CD Function
 *
 * @args: entered command
 */

void type_cd(char *args) /* If the user does not pass any argument*/
{
	if (args == NULL)
	{
		char *go_home = getenv("HOME");

		if (go_home == NULL)
		{
			perror("cd: HOME environment variable is not set\n");
		}
		else
		{
			/* Take the user home */
			if (chdir(go_home) != 0)
			{
				perror("could not change directory");
			}
		}
	}
	else
	{
		/* If the user adds an argument*/
		if (chdir(args) != 0)
		{
			perror("could not change directory");
		}
	}
}

/**
 * func_exit - exit function
 */
void func_exit(void)
{
	printf("Exiting shell.....\n");
	/* Before exiting, it can sleep*/
	sleep(2);
	exit(0); /*exited succressfully here sha*/
}

/*env prints the current  current environment*/

/**
 * env - prints current environment
 */
void env(void)
{
	char **print_env = environ;
	size_t len = strlen(*print_env);

	while (*print_env != NULL)
	{
		write(STDOUT_FILENO, *print_env, len);
		write(STDOUT_FILENO, "\n", 1);
		print_env++;
	}
}
