#include "shell.h"

/**
 * get_path - handles the path
 * @cmd: command
 *
 * Return: pointer to path
 */
char *get_path(char *cmd)
{
	char *path = getenv("PATH"), *pathcopy, *pathtok, *file_path;
	int cmd_length, dir_length;
	struct stat buff;

	if (path)
	{
		pathcopy = _strdup(path);
		cmd_length = _strlen(cmd);
		pathtok = strtok(pathcopy, ":");
		while (pathtok != NULL)
		{
			dir_length = _strlen(pathtok);
			file_path = malloc(cmd_length + dir_length + 2);
			if (file_path == NULL)
			{
				perror("malloc");
				exit(EXIT_FAILURE);
			}
			_strcpy(file_path, pathtok);
			_strcat(file_path, "/");
			_strcat(file_path, cmd);
			if (stat(file_path, &buff) == 0)
			{
				free(pathcopy);
				return (file_path);
			}
			else
			{
				free(file_path);
				pathtok = strtok(NULL, ":");
			}
		}
		free(pathcopy);
		if (stat(cmd, &buff) == 0)
			return (_strdup(cmd));
		return (NULL);
	}
	return (NULL);
}
