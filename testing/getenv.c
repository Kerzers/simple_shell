#include <stdio.h>
#include <stdlib.h>
#include <string.h>
extern char **environ;
char *_getenv(const char *name);
/**
 * main - test example
 *
 * Return : 0
 */
int main()
{
	char *path;

	path = _getenv("PATH");
	printf("%s\n", path);
	return (0);
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
