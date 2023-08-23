#include "main.h"

/**
 * _strlen - to return the length of a string.
 * @s: Pointer to string to measure
 *
 * Return: Lenght of the string
 */

int _strlen(char *s)
{
	int i = 0, len = 0;

	if (!s)
		return (len);

	while (*(s + i) != '\0')
	{
		len = len + 1;
		i++;
	}
	return (len);
}
