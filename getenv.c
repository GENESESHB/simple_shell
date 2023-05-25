#include "shell.h"
/**
 *get_env_var - a a function that search for an environment variable.
 *@name: a pointer to the variable name we need to search for.
 *Return: a pointer to the value of the found variable otherwise NULL.
 */
char *get_env_var(char *name)
{
	char **env = environ;
	char *env_var;
	int i = 0;

	while (*env != NULL)
	{
		env_var = *env;
		while (name[i] == env_var[i] && name[i] != '\0' && env_var[i] != '=')
			i++;
		if (name[i] == '\0' && env_var[i] == '=')
			return (&env_var[i + 1]);
		env++;
	}
	return (NULL);
}
