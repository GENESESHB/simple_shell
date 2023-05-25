#include "shell.h"
/**
 * _strtok - a function that tokenizes a string.
 * @str: string to tokenize.
 * @delim: delimiters to use for tokenization.
 * Return: a pointer to the token otherwise  NULL.
 */
char *_strtok(char *str, char *delim)
{
	static char *next_tok;
	char *tok_start;

	if (str != NULL)
		next_tok = str;

	if (next_tok == NULL || *next_tok == '\0')
		return (NULL);

	for (; *next_tok != '\0' && _strchr(delim, *next_tok) != NULL; next_tok++)
		;
	if (*next_tok == '\0')
	{
		next_tok = NULL;
		return (NULL);
	}
	tok_start = next_tok;
	for (; *next_tok != '\0' && _strchr(delim, *next_tok) == NULL; next_tok++)
		;
	if (*next_tok != '\0')
	{
		*next_tok = '\0';
		next_tok++;
	}
	else
		next_tok = NULL;
	return (tok_start);
}
