#include "main.h"

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
 * tokenizer - prepares the array of commands and arguments
 * @buffer: contains the string...
 * Returns: array of commands and argmuments
 */

char **tokenizer(char *buffer)
{
	char **argv;
	char *token;
	int c, i = 0;

	c = tokenCount(buffer);
	if (c == 0)
		return(NULL);
	printf("\n%d\n", c);
	argv = malloc(sizeof(char *) * (c + 1));
	if (argv == NULL)
		return(NULL);

	token = strtok(buffer, " \n\t");

	for (i = 0; token || i < c; i++)
	{
		argv[i] = malloc(sizeof(char) * (myStrLen(token) + 1));
		if (!argv[i])
		{
			for(; i >= 0; i--)
				free(argv[i]);
			free(argv);
			return (NULL);
		}
		_strcpy(argv[i], token);
		printf("\n%s\n", argv[i]);
		token = strtok(NULL, " \t\n");
	}
	printf("\n%d\n", c);
	argv[i] = NULL;
	return (argv);
}

/**
 * tokenCount
 *  - counts the number of tokens produced form a string
 *  @str: the string thta geneartes the tokens
 *  Return: the number of tokens generated
 */

int tokenCount(char *str)
{
	int count = 0;
	char *token, *tmp;

	if (!str)
		return (0);

	tmp =  strdup(str);
	token  = strtok(tmp, " \t\n");
	while (token)
	{
		count++;
		printf("%d %s\n", count, token);
		token = strtok(NULL, " \t\n");
	}

	free(tmp);
	return (count);
}

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
 *_getenv - gets an environment variable
 *@name: environment variable
 *Return: the value of environment variable
 *
 */
char *_getenv(const char *name)
{
	char **env = environ;
	char *token;
	int i = 0;


	while (env[i])
	{
		token = strtok(env[i],"=");
		if (strcmp(name,token) == 0)
		{
			token = strtok(NULL, "");
			return (token);
		}
	i++;
	}
	return (NULL);
}
