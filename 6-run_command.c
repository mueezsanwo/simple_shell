#include "main.h"

/**
 * run_command - run the command digited by user
 * @command_ex: command in the path
 * @command_buffer: command of the user
 *
 * Return: 0 on Succes.
 */

int run_command(char *command_ex, char *command_buffer)
{
	char **args;
	int i = 0, pid = 0, wstatus = 0;
	char *auxline = NULL;

	args = _calloc(sizeof(char *), 10);
	if (args == NULL)
	{
		free(auxline);
		free(command_ex);
		free(command_buffer);
		return (EOF);
	}

	auxline = strtok(command_buffer, " ");
	for (i = 0; auxline; i++)
	{
		args[i] = auxline;
		auxline = strtok(NULL, " ");
	}
	args[i] = NULL;

	pid = fork();
	if (pid > 0)
		wait(&wstatus);

	if (pid == 0)
		execve(command_ex, args, NULL);

	return (0);
}
