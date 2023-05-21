#include "shell.h"
/**
 *_strchr - Entry point
 *@s: the string to seach in
 *@c: the character to be found
 *Return: a pointer to the first occurrence of the character c
 *otherwise NULL.
 */
char *_strchr(char *s, char c)
{
	int i;

	if (s == NULL)
		return (NULL);

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == c)
		{
			return (&s[i]);
		}
	}
	if (s[i] == c)
	{
		return (&s[i]);
	}
		return ('\0');
}
/**
 *_memset - a function that sets a block of memory to a specefic value..
 *@s: it is a pointer to the memory that need to be filled.
 *@b: the char to be filled with.
 *@n: number of bytes to be filled.
 *Return: a pointer to the first element of the memory filled .
 */
char *_memset(void *s, char b, unsigned int n)
{
	unsigned int i;
	 char *p = s;

	for (i = 0; i < n; i++)
	{
		p[i] = b;
	}
	return (s);
}
