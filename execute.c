#include "shell.h"
/**
 *execute - a function that executes commands.
 *@args: an array of tokens.
 *@argv: a vector of arguments.
 *@env: an array of environment variables.
 *Return: status
 */
int execute(char **args, char **argv, char **env)
{
	pid_t pid;
	int status;

		pid = fork();
		if (pid == -1)
		{
			exit(EXIT_FAILURE);
		}
		if (pid == 0)
		{
			if (args[0][0] == '/')
			{
				execve(args[0], args, env);
				perror("execve");
				exit(EXIT_FAILURE);
			}
			else
			{
				search_executable(args, argv, env);
				if (search_executable(args, argv, env)  < 0)
				{
					perror(args[0]);
					exit(EXIT_FAILURE);
				}
			}
		}
		else
			wait(&status);
		return (status);
}

