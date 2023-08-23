#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>

#define ISATTYPROMPT(PROMPT, LEN) \
do {\
	if (isatty(0) == 1)\
		write(STDOUT_FILENO, (PROMPT), (LEN));\
} while (0)

extern char **environ;

char *com_vs_path(char *buffer_folder, char *command_buffer);
int run_command(char *command_ex, char *command_buffer);
void sighandler(int signum);
int len_path(void);
int extract_len(char *s);
char *_strdup(char *buffer, int len);
int len_command(char *s);
int cheker_exit(char *command_buffer);
int _strlen(char *s);
void *_calloc(unsigned int nmemb, unsigned int size);
char *find_username(void);
void sighandler(int signum);
char *search_path(void);
int wait_command(char *check_path);
char *extract_command(char *command_buffer);
int command_path(char *command_ex, char *command_buffer, char *check_path);

#endif /*MAIN_H*/
