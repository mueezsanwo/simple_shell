#include "main.h"

/**
 * com_vs_path - add command to the path
 * @buffer_folder: buffer of divided path
 * @command_buffer: buffer to save the user command
 *
 * Return: path with command
 */

char *com_vs_path(char *buffer_folder, char *command_buffer)
{
	char *buffer_complete_path = NULL;
	int i = 0, j = 0;

	buffer_complete_path = _calloc(sizeof(char), 1024);
	if (buffer_complete_path == NULL)
	{
		free(buffer_folder);
		free(command_buffer);
		return (NULL);
	}

	for (i = 0; buffer_folder[i]; i++)
		buffer_complete_path[i] = buffer_folder[i];

	for (; command_buffer[j] != '\0'; i++, j++)
	{
		if (j == 0 && buffer_complete_path[i - 1] != '/')
		{
			buffer_complete_path[i] = '/';
			i++;
		}
		buffer_complete_path[i] = command_buffer[j];
	}
	return (buffer_complete_path);

