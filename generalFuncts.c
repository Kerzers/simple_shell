#include "main.h"

/**
 * tokenizer - prepares the array of commands and arguments
 * @buffer: contains the string...
 * @count: number of tkens in the string
 * Returns: array of commands and argmuments
 */

char **tokenizer(char *buffer, int count)
{
	char **argv;
	char *token;
	int c;

	c = tokenCount(buffer);
	if (c == 0)
		return(NULL);
	argv = malloc(sizeof(char *) * (c + 1));
	if (argv == NULL)
		return(NULL);

	token = strtok();
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
	char *token;

	token  = strtok(strdup(str), " \t\n");
	if (token)
	{
		count++;
		token = strtok(NULL, " \t\n");
	}
	else
		return (count);
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
