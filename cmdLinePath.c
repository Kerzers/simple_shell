#include "main.h"

/**
 *cmdLinePath - finds the absolute path of a cmd
 *@argv: array string of command and args
 *@str: name of the program
 *Return: 1 (success), otherwise 0
 */
int cmdLinePath(char **argv, char *str)
{
	char *abs_path;
	struct stat st;

	if (stat(argv[0], &st) != 0)
	{
		abs_path = handle_path(argv[0]);
		if (!abs_path)
		{
			free(abs_path);
			perror(str); /* ./hsh : 1 :  argv[0]: not found*/
			return (0);
		}
		else
		{
			/*free(argv[0]);*/
			argv[0] = _strdup(abs_path);
			if (!argv[0])
			{
				free(abs_path);
				perror(str);
				free(argv[0]);
				return (0);
			}
			else
				free(abs_path);
		}
	}
	return (1);
}
