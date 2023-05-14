#include <unistd.h>
#include "simpleShell.h"

/**
 * _strcpy - copies strings to each other
 * @a: ...
 * @b: ...
 * Return: ...
 */

char *_strcpy(char *a, char *b)
{
	if (a == NULL || b == NULL)
		return (NULL);

	while (*b)
	{
		*a = *b;
		a++;
		b++;
	}
	*a = '\0';
	return (a);
}

/**
 * wrF - writes to stdout
 * @str: ....
 */

void wrF(char *str, char *strB, int u)
{
	writerFunct(str);
	write(1, ":", 1);
	write(1, " ", 1);
	wrD(u);
	write(1, ":", 1);
	write(1, " ", 1);
	writerFunct(strB);
	write(1, ":", 1);
	write(1, " ", 1);
	writerFunct("not found\n");
}

/**
 * wrD - writes digit ot numbers to stout
 * @u:the numner
 */

void wrD(int u)
{
	char b[20];
	int i = 0, j = 0;
	char v;

	while(u > 0)
	{
		b[i] = (u % 10) + '0';
		i++;
		u /= 10;
	}

	for (j = 0; j < i / 2; j++)
	{
		v = b[j];
		b[j] = b[i - j - 1];
		b[i - j - 1] = v;
	}

	b[i] = '\0';

	writerFunct(b);
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
