#include "shell.h"
/**
 *main - the main function.
 *@argc: number of arguments.
 *@argv: an array of arguments.
 *@env: an array of environmment variables.
 *Return: 0 (succes).
 */
int main(int argc, char **argv, char **env)
{
	int status = 0;
	size_t len = 0;
	int num_chars = 0;
	char **args = NULL, *line = NULL;
	(void)argc;

	while (1)
	{
		args = NULL;
		if (isatty(STDIN_FILENO))
			write(1, "$ ", 2);
		num_chars = getline(&line, &len, stdin);
		if (num_chars == -1)
		{
			free(line);
			line = NULL;
			write(STDIN_FILENO, "\n", 1);
			break;
		}
		if (line[num_chars] == '\n')
			line[num_chars] = '\0';
		if (handle_sep_ope(line, argv, env))
			continue;
		args = tokenizer(line);
		if (args == NULL || *args == NULL)
			continue;
		if (buildincmd(args, line))
			continue;
		if ((handle_spec_var(args, WEXITSTATUS(status))) == 0)
			status = execute(args, argv, env);
	}
	return (0);
}
