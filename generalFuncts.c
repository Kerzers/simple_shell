#include "main.h"

/**
 * tokenizer - prepares the array of commands and arguments
 * @buffer: contains the commands and args of the user
 * Returns: array of commands and arguments
 */

char **tokenizer(char *buffer)
{
	char **argv;
	char *token, *tmp;
	int c, i = 0;

	c = tokenCount(buffer);
	if (c == 0)
		return(NULL);
	argv = malloc(sizeof(char *) * (c + 1));
	if (argv == NULL)
		return(NULL);
	tmp = strdup(buffer);
	token = strtok(tmp, " \n\t");

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
		token = strtok(NULL, " \t\n");
	}
	argv[i] = NULL;
	free(tmp);
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
		token = strtok(NULL, " \t\n");
	}

	free(tmp);
	return (count);
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
	char *tmp;
	char *token;
	int i = 0;

	while (env[i])
	{
		tmp = _strdup(env[i]);
		token = strtok(tmp,"=");
		if (strcmp(name,token) == 0)
		{
			token = strtok(NULL, "");
			token = _strdup(token);
			free(tmp);
			return (token);
		}
	i++;
	}
	free(tmp);
	return (NULL);
}
