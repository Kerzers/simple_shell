#include "main.h"

/**
 * __exit - exits fom the program
 * @argv: array holds commnads
 * @buffer: user input
 */

void __exit(char **argv, char *buffer)
{
	free(buffer);
	_freeStr(argv, tokenCount(buffer));
	exit(0);
}

/**
 * counter - check if commands are similar
 * @len: length
 * @argv: arguments
 * Return: the count
 */

int counter(int len, char **argv)
{
	int count = 0, i = 0;

	while (i <= len - 1)
	{
		if (_strcmp(argv[i], "/bin/ls") == 0 || _strcmp(argv[i], "ls") == 0)
		{
			i++;
			count++;
		}
		else
			break;
	}
	return (count);
}
