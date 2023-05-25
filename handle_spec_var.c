#include "shell.h"
/**
 *handle_spec_var - a function that handles the special variables.
 *@args: arguments.
 *@i: exit status.
 *Return: 0 succes.
 */
int handle_spec_var(char **args, int i)
{
	char *status_str = NULL;
	char *getpid_str = NULL;

	if (_strcmp(args[0], "echo") == 0)
	{
		if (_strcmp(args[1], "$?") == 0)
		{
			status_str = utoa(i);
			write(1, status_str, strlen(status_str));
			write(1, "\n", 1);
			return (1);
		}
		else if (_strcmp(args[1], "$$") == 0)
		{
			getpid_str = utoa(getpid());
			write(1, getpid_str, _strlen(getpid_str));
			write(1, "\n", 1);
			return (1);
		}
	}
	return (0);
}

