#include "shell.h"
/**
 *handlesep - a function that handles ";" separator.
 *@line: the input string.
 *@argv: a vector of arguments?
 *@env: an array of environment variables.
 *Return: 0 succes.
 */
int handlesep(char *line, char **argv, char **env)
{
	char *command = _strtok(line, ";");
	char **arg = NULL;
	char **lines = NULL;
	int i = 0, j = 0;

	arg = malloc(sizeof(char *) * 10);
	if (arg == NULL)
	{
		free(arg);
		return (-1);
	}
	while (command)
	{
		arg[i] = command;
		i++;
		command = _strtok(NULL, ";");
	}
	arg[i] = NULL;
	while (j < i)
	{
		lines = NULL;
		lines = tokenizer(arg[j]);
		j++;
		execute(lines, argv, env);
	}
	free(arg);
	arg = NULL;
	return (0);
}

