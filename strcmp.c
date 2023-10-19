#include "shell.h"

/**
 * _strcmp - checks if 2 strings are of equal value
 * @s1: destination string
 * @s2: source string to be copied
 *
 * Return: difference of first characters that are of diff value
 */

int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	return (0);
}
