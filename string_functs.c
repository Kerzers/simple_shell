#include "main.h"
/**
 *_strcpy - copies the string pointed to by src to the
 * buffer pointed to by dest
 *@dest: pointer as a parameter
 *@src: pointer as a parameter
 * Return: the pointer to dest
 */

char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return (dest);
}
/**
 * myStrLen - returns the length of a string
 * @str: the string ti0 be counted
 * Return: the length of the string in question
 */

int myStrLen(const char *str)
{
	const char *theStr = str;
	int n = 0;

	if (str == NULL)
		return (0);

	while (*theStr)
	{
		n++;
		theStr++;
	}

	return (n);
}
/**
 * _strcat - concatenates 2 strings
 * @dest: destination string, terminating by '\0'
 * @src: a string to be append at dest
 * Return: a pointer to the resulting string dest
 */
char *_strcat(char *dest, char *src)
{
	int i = 0;
	int len1, len2;
	char *final = NULL;

	if (!src || !dest)
		return (NULL);
	len1 = myStrLen(dest);
	len2 = myStrLen(src);

	final = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!final)
		return (NULL);
	for (i = 0; i < len1; i++)
		final[i] = dest[i];
	for (; i < len1 + len2; i++)
		final[i] = src[i - len1];
	final[len1 + len2] = '\0';
	return (final);
}
/**
 * _strdup - duplicates a string
 * @src: string to be duplicated
 * Return: A pointer to the newly allocated string,
 * or a null pointer if an error occurred.
 */
char *_strdup(char *src)
{
	char *dest = NULL;

	if (!src)
		return (NULL);
	dest = malloc(sizeof(char) * (myStrLen(src) + 1));
	if (!dest)
		return (NULL);
	_strcpy(dest, src);
	return (dest);
}

/**
 * _strcmp - compares two strings to see if they are the same
 * @s1: the one str
 * @s2: the other str
 * Return: the result
 */
int _strcmp(const char *s1, const char *s2)
{
	int i = 0;

	if (s1 == NULL || s2 == NULL)
		return (-1);

	if (myStrLen(s2) != myStrLen(s1))
		return (-1);


	while (s1[i] && s2[i])
	{
		if (s1[i] == s2[i])
		{
			i++;
		}
		else
			return (-1);
	}
	return (0);
}
