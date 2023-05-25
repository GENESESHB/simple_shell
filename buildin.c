#include "shell.h"
/**
 *buildincmd - a function that handles the builtin commands.
 *@str: input string.
 *@args: a array in which we have stored arguments.
 *Return: 0 succes.
 */
int buildincmd(char **args, char *str)
{
	int switch_cmds = 0, i = 0;
	static char *cmds[] = {"env", "exit", "setenv", "unsetenv", "cd"};

	if (args == NULL)
		return (0);
	while (i <= 4)
	{
		if (_strcmp(args[0], cmds[i]) == 0)
		{
			switch_cmds = i + 1;
			break;
		}
		i++;
	}
	switch (switch_cmds)
	{
		case 1:
			envr();
			return (1);
		case 2:
			exit_shell(args, str);
			return (1);
		case 3:
			set_env(args);
			return (1);
		case 4:
			unset_env(args);
			return (1);
		case 5:
			cdir(args[1], args);
			return (1);
		default:
			break;
	}
	return (0);
}
/**
 *envr - a function that prints environment variables.
 *Return: nothing.
 */
void envr(void)
{
	int i = 0;

	while (environ[i])
	{
		write(1, environ[i], _strlen(environ[i]));
		write(1, "\n", 2);
		i++;
	}
}
/**
 *exit_shell - a function that handles "exit" command.
 *@str: input string.
 *@args: a array in which we have stored arguments.
 *Return: 0  succes.
 */
int exit_shell(char **args, char *str)
{
	int exit_status = 0;

	if (args[1] != NULL)
	{
		exit_status = atoi(args[1]);
		exit(exit_status);
	}
	if (args[1] == NULL)
	{
		free(str);
		str = NULL;
		args = NULL;
		exit(0);
	}
	return (0);

}
/**
 *set_env - a function that sets an environment variable.
 *@args: a array in which we have stored arguments.
 *Return: 0 succes.
 */
int set_env(char **args)
{
	char *new_env_var;
	int len1, len2;

	if (args[1] == NULL || args[2] == NULL)
		return (-1);
	len1 = _strlen(args[1]);
	len2 = _strlen(args[2]);
	new_env_var = malloc(len1 + len2 + 2);
	if (new_env_var == NULL)
	{
		free(new_env_var);
		return (-1);
	}
	_strcpy(new_env_var, args[1]);
	_strcat(new_env_var, "=");
	_strcat(new_env_var, args[2]);
	if (setenv(args[1], args[2], 1) != 0)
	{
		perror("setenv");
		free(new_env_var);
		return (-1);
	}

	free(new_env_var);
	return (0);
}
/**
 *unset_env - a function that unsets an environment variable.
 *@args: a array in which we have stored arguments.
 *Return: 0 succes.
 */
int unset_env(char **args)
{
	if (args[1] == NULL)
		return (-1);

	if (unsetenv(args[1]) != 0)
	{
		perror("unsetenv");
		return (-1);
	}
	return (0);
}
