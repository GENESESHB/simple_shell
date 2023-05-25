#include "shell.h"
/**
 *_strstr - Entry point
 *@haystack:String to search
 *@needle:Substring to be found.
 *Return: 0 seccues otherwise -1.
 *
 */
int _strstr(char *haystack, char *needle)
{
	int i = 0;

	while (haystack[i] != '\0')
	{
		for (i = 0; needle[i] != '\0'; i++)
		{
			if (needle[i] != haystack[i])
			{
				break;
			}
		}
		if (needle[i] == '\0')
		{
			return (0);
		}
		haystack++;
	}
	return (-1);
}
