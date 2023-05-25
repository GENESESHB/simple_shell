#include "shell.h"
/**
 *search_executable - a function that search for the executable files.
 *@args: an array of token ( tokenized input).
 *@argv: an array of arguments.
 *@env: an array of environment variables.
 *Return: -1 in failure.
 */
int search_executable(char **args, char **argv, char **env)
{
	char *path = NULL;
	char *pathtok = NULL;
	char fullpath[1024];

	path = get_env_var("PATH");
	pathtok = _strtok(path, ":");

	while (pathtok != NULL)
	{
		_strcpy(fullpath, pathtok);
		_strcat(fullpath, "/");
		_strcat(fullpath, args[0]);

		if (access(fullpath, X_OK) == 0)
		{
			execve(fullpath, args, env);
			perror(argv[0]);
			exit(EXIT_FAILURE);
		}
		pathtok = _strtok(NULL, ":");
	}
	return (-1);
}
