#include "shell.h"
#define MAX_TOKENS 64
/**
 *tokenizer - a function that tokenizes a string.
 *@str: the string to be tokenized.
 *Return: a pointer the token otherwise NULL.
 */
char **tokenizer(char *str)
{
	int i = 0;
	char *token = NULL;
	static char *tokens[MAX_TOKENS];
	char *del = " \t\n:";

	_memset(tokens, 0, sizeof(char *) * MAX_TOKENS);
	token = _strtok(str, del);
	while (token != NULL && i < MAX_TOKENS - 1)
	{
		tokens[i] = token;
		i++;
		token = _strtok(NULL, del);
	}
	if (token == NULL && tokens[0] == NULL)
		return (NULL);
	return (tokens);
}
