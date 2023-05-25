#include "shell.h"
/**
 *logic__operator - a function that handles logic operators.
 *@line: input string.
 *@argv: an array of arguments.
 *@env: an array of environment variables.
 *Return: 0 succes .
 */
int logic__operator(char *line, char **argv, char **env)
{
	char *command = _strtok(line, "||");
	char **arg = NULL;
	char **lines = NULL;
	int i = 0, j = 0;
	int status = 0;

	arg = malloc(sizeof(char *) * 10);
	if (arg == NULL)
		return (-1);
	while (command)
	{
		arg[i] = command;
		i++;
		command = _strtok(NULL, "||");
	}
	arg[i] = NULL;
	while (j < i)
	{
		lines = NULL;
		lines = tokenizer(arg[j]);
		j++;
		status = execute(lines, argv, env);
		if (WIFEXITED(status) && (WEXITSTATUS(status) == 0))
			break;
	}
	free(arg);
	arg = NULL;
	return (0);
}

