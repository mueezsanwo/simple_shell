#include "main.h"

/**
 * command_path - looks for the command in the path
 * @command_ex: command in the path
 * @command_buffer: command of the user
 * @check_path: complete path
 *
 * Return: 0 on Success
 */

int command_path(char *command_ex, char *command_buffer, char *check_path)
{
	char *buffer_folder = NULL,  *check_equals = NULL;
	struct stat sb;

	buffer_folder = _calloc(sizeof(char), 1024);
	if (buffer_folder == NULL)
	{
		free(command_ex);
		free(check_path);
		return (EOF);
	}

	if (stat(command_ex, &sb) == 0)
	{
		run_command(command_ex, command_buffer);
	}
	else
	{
		buffer_folder = strtok(check_path, ":");
		while (buffer_folder != NULL)
		{
			check_equals = com_vs_path(buffer_folder, command_ex);
			if (check_equals == NULL)
			{
				free(check_path);
				free(command_ex);
				free(buffer_folder);
				return (EOF);
			}
			if (stat(check_equals, &sb) == 0)
			{
				run_command(check_equals, command_buffer);
			}
			buffer_folder = strtok(NULL, ":");
		}
		if (stat(check_equals, &sb) != 0)
			printf("Command '%s' not found\n", command_buffer);
		free(check_equals);
	}
	free(buffer_folder);
	return (0);
}
