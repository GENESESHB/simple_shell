#include "shell.h"
/**
 *reverse - a function that reverses a string.
 *@s: the string to be reversed.
 *@len: the length of the string.
 *Return: nothing.
 */
void reverse(char *s, int len)
{
	char temp;
	int i = 0;
	int j = len - 1;

	while (i < j)
	{
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
		i++;
		j--;
	}
}
/**
 *utoa - a function that converts an int to a string.
 *@num: the number to be converted.
 *Return: a pointer to the converted string otherwise NULL.
 */
char *utoa(unsigned int num)
{
	int len = 0, i = 0;
	char *str = NULL;

	if (num == 0)
	{
		str = malloc(2);
		if (str == NULL)
			return (NULL);
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	len = numlen(num);
	str = malloc(len + 1);
	if (str == NULL)
		return (NULL);
	for (i = 0; num != 0; i++)
	{
		str[i] = (num % 10) + '0';
		num /= 10;
	}
	reverse(str, len);
	str[i] = '\0';
	return (str);
}
/**
  *numlen - a function to get the length of a number.
  *@n: the number that we should get its length.
  *Return: the length of the number.
  */
int numlen(unsigned int n)
{
	int len = 0;

	while (n != 0)
	{
		n = n / 10;
		len++;
	}

	return (len);
}

