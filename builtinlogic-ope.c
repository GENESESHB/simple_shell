#include "shell.h"
/**
 *handle_sep_ope - a function that handles ";" separator.
 *@line: the input string.
 *@argv: a vector of arguments?
 *@env: an array of environment variables.
 *Return: 1 succes otherwise 0.
 */
int handle_sep_ope(char *line, char **argv, char **env)
{
	int switch_cmds = 0, i = 0;
	static char *cmds[] = {";", "&&", "||"};

	if (line == NULL)
		return (0);
	while (i <= 2)
	{
		if (_strstr(line, cmds[i]) == 0)
		{
			switch_cmds = i + 1;
			break;
		}
		i++;
	}
	switch (switch_cmds)
	{
		case 1:
			handlesep(line, argv, env);
			return (1);
		case 2:
			logicope(line, argv, env);
			return (1);
		case 3:
			logic__operator(line, argv, env);
			return (1);
		default:
			break;
	}
	return (0);
}

/**
 *logicope - a function that handles ";" separator.
 *@line: the input string.
 *@argv: a vector of arguments?
 *@env: an array of environment variables.
 *Return: 0 succes.
 */
int logicope(char *line, char **argv, char **env)
{
	char *command = _strtok(line, "&&");
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
		command = _strtok(NULL, "&&");
	}
	arg[i] = NULL;
	while (j < i)
	{
		lines = NULL;
		lines = tokenizer(arg[j]);
		j++;
		status = execute(lines, argv, env);
		if (WIFEXITED(status) && (WEXITSTATUS(status) != 0))
			break;

	}
	free(arg);
	return (0);
}

