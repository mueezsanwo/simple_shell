#include "main.h"

/**
 * wait_command - save the input
 * @check_path: path complete
 *
 * Return: 0 in succes, -1 on frailure
 */

int wait_command(char *check_path)
{
	char *command_buffer = NULL, *command_ex = NULL;
	size_t aux = 1;
	int check = 0, status_exit = 0, size = 1000;

	command_buffer = _calloc(sizeof(char), size);
	if (command_buffer == NULL)
	{
		free(check_path);
		return (EOF);
	}

	check = getline(&command_buffer, &aux, stdin);
	if (check == -1)
	{
		free(check_path);
		free(command_buffer);
		return (EOF);
	}
	status_exit = cheker_exit(command_buffer);
	if (status_exit == EOF)
	{
		free(check_path);
		free(command_buffer);
		return (EOF);
	}
	command_buffer[check - 1] = '\0';
	command_ex = extract_command(command_buffer);
	if (command_ex == NULL)
	{
		free(check_path);
		free(command_buffer);
		return (EOF);
	}
	command_path(command_ex, command_buffer, check_path);

	free(command_buffer);
	return (0);
}
