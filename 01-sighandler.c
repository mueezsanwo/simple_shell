#include "main.h"

/**
 * sighandler - the function for exit
 * @signum: void input
 *
 * Return: none
 */

void sighandler(int signum)
{
	(void) signum;
	write(STDOUT_FILENO, "\n:) ", 4);
}
