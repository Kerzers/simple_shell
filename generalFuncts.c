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
	tmp = _strdup(buffer);
	token = strtok(tmp, " \"\n\t");

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
		token = strtok(NULL, " \"\t\n");
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

	tmp =  _strdup(str);
	token  = strtok(tmp, " \t\n\"");
	while (token)
	{
		count++;
		token = strtok(NULL, " \"\t\n");
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
		if (_strcmp(name,token) == 0)
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
/**
 *find_path - finds the absolute path of a cmd
 *@argv: array string of command and args
 *Return: 1 (success), otherwise 0
 */
int find_path(char **argv, char *buffer, char *str)
{
	char *abs_path;
	struct stat st;

	if (stat(argv[0], &st) != 0)
	{
		abs_path = handle_path(argv[0]);
					if (!abs_path)
					{
						free(abs_path);
						perror(str);
						_freeStr(argv, tokenCount(buffer));
						return (0);
					}
					else
					{
						free(argv[0]);
						argv[0] = _strdup(abs_path);
						if (!argv[0])
						{
							free(abs_path);
							perror(str);
							_freeStr(argv, tokenCount(buffer));
							return (0);
						}
					}
				}
	free(abs_path);
	return (1);
}
