#include "main.h"

/**
 * main - the main function of the program
 * @ac: the  number of arguments passed to the program call
 * @argv: string array containing the program name and args
 * Return: always 0
 */

int main(int ac, char **argv)
{
	const char *usage = "usage: ";

	(void)argv;

	if (isatty(STDIN_FILENO))
	{
		if (ac == 1)
		{
			interactive(argv[0]);	
		}
		else
		{
			write(STDOUT_FILENO, usage, 7);	
		}
	}
	else
	{
		non_interactive(argv[0]);
	}

	return (0);
}

/**
 * non_interactive - for the non interactive mode
 * @str: the command
 */

void non_interactive(char *str)
{
	ssize_t n;
	int status;
	char *buffer = NULL;
	char *argv[2];
	size_t size = 0;
	pid_t cpid;

	n = getline(&buffer, &size, stdin);
	if (n == -1)
		return;

	argv[0] = strtok(buffer, "\n");
	argv[1] = NULL;

	cpid = fork(); /*Child process creation*/
	if (cpid == -1)
		perror(str);
	if (cpid == 0)
	{
		if (execve(argv[0], argv, NULL) == -1)
			perror(str);
	}
	else
		wait(&status);
	free(buffer);
}

/**
 * interactive - for the intercative mode
 * @str: name of the program
 */

void interactive(char *str)
{
	const char *prompt = "#s_shell$ ";
	int n, status;
	char *buffer = NULL;
	char *argv[2];
	size_t size = 0;
	pid_t cpid;

	while (1)
	{
		write(STDOUT_FILENO, prompt, 10);
		n = getline(&buffer, &size, stdin);
		if (n == -1)
		{
			_putchar('\n');
			break;
		}

		argv[0] = strtok(buffer, " \t\n");
		if (!argv[0])
		{
		}
		else
		{
			processes(argv, str);
		argv[1] = NULL;
		cpid = fork(); /*Child process creation*/
		if (cpid == -1)
		{
			perror(str);
			break;
		}
		if (cpid == 0)
		{
			if (execve(argv[0], argv, NULL) == -1)
			{
				perror(str);
				break;
			}
		}
		else
			wait(&status);
		}
	}
	free(buffer);
}
