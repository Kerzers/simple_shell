#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "simpleShell.h"
#include <unistd.h>

/**
 * _strcat - combines strings to one
 * @a: the dest
 * @b: srci
 * Return: the combined string
 */

char *_strcat(char *a, char *b)
{
	char *dest_end = a + strlen(a);

	while (*b != '\0')
	{
		*dest_end = *b;
		dest_end++;
		b++;
	}
	*dest_end = '\0';
	return (a);
}

/**
 * searchCmd - find a command from PATH
 * @cmdPath: path to cmd or name of cmd
 * Return: 1 if found and 0 if not
 */
char *searchCmd(char *cmdPath)
{
	char *tok2, *tmp, *en;

	if (cmdPath == NULL)
		return (NULL);

	if (access(cmdPath, X_OK) == 0)
		return (cmdPath);

	en = _getenv("PATH");
		if (en == NULL)
		{
			return (NULL);
		}

		tok2 = strtok(en, ":");
		while (tok2 != NULL)
		{
			tmp = tempMaker(tok2);
			_strcat(tmp, "/");
			_strcat(tmp, cmdPath);

			if (access(tmp, X_OK) == 0)
				return (tmp);
			tok2 = strtok(NULL, ":");
		}
	return (NULL);
}

/**
 * _getenv - returns the required enviromental variable
 * @str: the name of the environmental variable to look for
 * Return: the value of the envrment
 */

char *_getenv(const char *str)
{
	char *tok, *tmp;
	int i = 0;
	char **my_env = environ;

	while (my_env[i] != NULL)
	{
		tmp = tempMaker(my_env[i]);
		if (tmp == NULL)
			return (NULL);

		tok = strtok(tmp, "=");
		if (tok != NULL)
		{
			if ((_strcmp(str, tok) == 1))
			{
				tmp = tempMaker(my_env[i]);
				if (tmp == NULL)
					return (NULL);
				strtok(tmp, "=");
				return (strtok(NULL, ""));
			}
		}
		i++;
	}
	return (NULL);
}

/**
 * _strcmp - compares two strings to see if they are the same
 * @s1: the one str
 * @s2: the other str
 * Return: the result
 */
int _strcmp(const char *s1, char *s2)
{
	/*check the lengths*/
	if (strlen(s1) != strlen(s2))
		return (0);

	while (*s1)
	{
		if (*s1 == *s2)
		{
			s1++;
			s2++;
		}
		else
			return (0);
	}
	return (1);
}

/**
 * tempMaker - makes a copy of the original string
 * @str: the original sstring
 * Return: the new string
 */
char *tempMaker(char *str)
{
	char *tmp = NULL;

	tmp = malloc(strlen(str));
	if (tmp == NULL)
	{
		perror("Err allocating memory for tmp");
		return (NULL);
	}
	strcpy(tmp, str);
	return (tmp);
}
