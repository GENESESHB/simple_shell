#include "shell.h"
/**
 *change_directory - a function that changes the directory.
 *@path: the path of the directory we are supposed to change to.
 *@args: an array of arguments.
 *Return: 0 succes.
 */
int change_directory(char *path, char **args)
{
	char *old = NULL;
	char *home = NULL;

	old = get_env_var("OLDPWD");
	home = get_env_var("HOME");

	if (args[1] == NULL)
	{
		if (chdir(home) != 0)
		{
			perror("cd");
			return (-1);
		}
	}
	else if (_strcmp(args[1], "-") == 0)
	{
		if (chdir(old) != 0)
		{
			perror("cd");
			return (-1);
		}
	}
	else
	{
		if (chdir(path) != 0)
		{
			perror("cd");
			return (-1);
		}
	}
	return (0);
}
/**
 *update_environment_variables - a function that updates the
 *environment variables.
 *@old: a pointer to the variable to be updated.
 *Return: 0 succes otherwise failure.
 */
int update_environment_variables(char *old)
{
	char pwd[PATH_MAX];
	char *pwd_arg[4];
	char *old_arg[4];

	if (getcwd(pwd, sizeof(pwd)) != NULL)
	{
		pwd_arg[0] = "setenv";
		pwd_arg[1] = "PWD";
		pwd_arg[2] = pwd;
		pwd_arg[3] = NULL;
		set_env(pwd_arg);
	}
	else
	{
		perror("cd");
		return (1);
	}
	old_arg[0] = "setenv";
	old_arg[1] = "OLDPWD";
	old_arg[2] = old;
	old_arg[3] = NULL;
	set_env(old_arg);

	return (0);
}
/**
 *cdir - a function that handles "cd" command.
 *@path: the path of the directory we are supposed to change to.
 *@args: an array of arguments.
 *Return: 0 succes otherwise failure.
 */
int cdir(char *path, char **args)
{
	char *old = NULL;

	if (change_directory(path, args) != 0)
	{
		return (1);
	}

	if (update_environment_variables(old) != 0)
	{
		return (1);
	}
	return (0);
}
