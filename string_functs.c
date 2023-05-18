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

int myStrLen(char *str)
{
	char *theStr = str;
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
	int j;

	while (dest[i])
	{
		i++;
	}
	for (j = 0; src[j] != '\0'; j++)
	{
		dest[i] = src[j];
		i++;
	}
	dest[i] = '\0';
	return (dest);
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
