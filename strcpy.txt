#include "shell.h"

/**
 * _strcpy - copies the string pointed to by src, including the
 *  terminating null byte (\0), to the buffer pointed to by dest.
 *  @dest: destination variable
 *  @src: source
 *
 *  Return: pointer to dest
 */

char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = src[i];

	return (dest);
}
