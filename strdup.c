#include "shell.h"

/**
 * _strdup -  returns a pointer to a new string
 * which is a duplicate of the string str
 * @str: given string
 * Return: NULL, is str = NULL
 * else return pointer to the duplicated string
 * else return NULL if insufficient memory was available
 */

char *_strdup(char *str)
{
	char *new_str;
	int i;

	if (str == NULL)
		return (NULL);

	new_str = malloc((length(str) + 1) * sizeof(char));
	if (new_str == NULL)
		return (NULL);

	for (i = 0; str[i] != '\0'; i++)
		new_str[i] = str[i];
	new_str[i] = '\0';

	return (new_str);
}

/**
 * length - counts a string
 * @str: string
 * Return: count
 */

int length(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;

	return (i);
}
