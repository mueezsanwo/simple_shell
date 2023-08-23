#include "main.h"

/**
 * extract-command - search the command in the input
 * @command_buffer: input complete
 *
 * Return: pointer char, NULL in frailure
 */

char *extract_command(char *command_buffer)
{
	char *command_ex = NULL;
	int i = 0;

	command_ex = _calloc(sizeof(char), 1000);
	if (command_ex == NULL)
		return (NULL);

	for (i = 0; command_buffer[i] != '\0'; i++)
	{
		if (command_buffer[i] == ' ')
			break;
		command_ex[i] = command_buffer[i];
	}
	return (command_ex);
}
