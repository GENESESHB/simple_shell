#include "shell.h"
/**
 *_strlen - Entry point
 *@s: a pointer
 *DEscription:	a function that returns the length of a string
 *Return: len
 */
int _strlen(char *s)
{
	int len;

	len = 0;
	while (*(s + len) != '\0')
	{
		len++;
	}
	return (len);
}
/**
 **_strcat - Entry point
 *@dest: destination string
 *@src: the string to be appended
 *Return:  a pointer to the resulting string
 */
char *_strcat(char *dest, char *src)
{
	int len;
	int len1;
	int i;

	for (len = 0; dest[len] != '\0'; len++)
	{
		;
	}
		for (len1 = 0; src[len1] != '\0'; len1++)
		{
			;
		}
			for (i = 0; i <= len1; i++)
			{
				dest[len + i] = src[i];
			}
			return (dest);
}
/**
 *_strcmp - Entry point
 *@s1:the first string
 *@s2:the second string
 *Return: 0 or a negative number or a positive number...
 */
int _strcmp(char *s1, char *s2)
{
	int i;
	int diff;

	for (i = 0; s1[i] != '\0'; i++)
	{
		diff = s1[i] - s2[i];
		if (diff > 0 || diff < 0)
		{
			return (diff);
		}
	}
	return (0);
}

/**
 *_strcpy - Entry point
 *@dest: Address where string will be copied to.
 *@src: Original string to be copied.
 *Return: the pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
		dest[i] = ('\0');
		return (dest);
}
