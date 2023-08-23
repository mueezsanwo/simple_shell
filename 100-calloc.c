#include "main.h"
/**
 * _calloc -  to allocate memory for an array
 * @nmemb: the elements to modify
 * @size: times we want modify memory
 * Return: pointer for array
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *s;
	unsigned int i;

	/*look if nmem or size are valid*/
	if (nmemb == 0 || size == 0)
		return (NULL);

	/*asign space of size and nmem*/
	s = malloc(size * nmemb);

	if (s == NULL)
		return (NULL);

	for (i = 0; i < (size * nmemb); i++)
		s[i] = 0;

	return (s);
}
