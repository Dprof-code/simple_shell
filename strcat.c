#include "shell.h"
/**
 * _strcat - concatenates two strings,
 * @dest: destination.
 * @src: source.
 * Return: the pointer to dest.
 */
char *_strcat(char *desc, char *src)
{
	int count = 0, count2 = 0;

	while (*(desc + count) != '\0')
	{
		count++;
	}

	while (count2 >= 0)
	{
		*(desc + count) = *(src + count2);
		if (*(src + count2) == '\0')
			break;
		count++;
		count2++;
	}
	return (desc);
}