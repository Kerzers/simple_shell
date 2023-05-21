#include "main.h"

/**
 * main - the main function of the program
 * @ac: the  number of arguments passed to the program call
 * @argv: string array containing the program name and args
 * @env: environment variable
 * Return: always 0
 */

int main(int ac, char **argv, char **env)
{

	if (isatty(STDIN_FILENO))
	{
		if (ac == 1)
		{
			interactive(argv[0], env);
		}
		if (ac > 1)
		{
			argv++;
			if (cmdLinePath(argv, argv[0]))
			{
				processes(argv[0], argv, env);
			}
			else
				perror(argv[0]);
		}
	}
	else
	{
		non_interactive(argv[0], env);
	}
	return (0);
}

/**
 * non_interactive - for the non interactive mode
 * @str: the command
 * @env: environment variable
 */

void non_interactive(char *str, char **env)
{
	ssize_t n;
	char *buffer = NULL;
	char **argv;
	size_t size = 0;

	n = getline(&buffer, &size, stdin);
	if (n == -1)
		return;

	argv = tokenizer(buffer);
	if (!argv)
	{
		perror(str);
	}
	else
	{
		if (find_path(argv, buffer, str))
		{
			processes(str, argv, env);
			_freeStr(argv, tokenCount(buffer));
		}
	}
	free(buffer);
}

/**
 * interactive - for the intercative mode
 * @str: name of the program
 * @env: environment variable
 */

void interactive(char *str, char **env)
{
	const char *prompt = "#s_shell$ ";
	int n;
	char *buffer = NULL;
	char **argv;
	size_t size = 0;

	while (1)
	{
		write(STDOUT_FILENO, prompt, 10);
		n = getline(&buffer, &size, stdin);
		if (n == -1)
		{
			_putchar('\n');
			break;
		}
		if (*buffer != '\n')
		{	argv = tokenizer(buffer);
			if (!argv)
				continue;
			else if (_strcmp(argv[0], "exit") == 0)
			{
				free(buffer);
				_freeStr(argv, tokenCount(buffer));
				exit(1);
			}
			else if (!find_path(argv, buffer, str))
					continue;
			else
				{
					if (!processes(str, argv, env))
					{
						_freeStr(argv, tokenCount(buffer));
						break;
					}
				}
			}
	}
	free(buffer);
}

/**
 * processes - starts and ends parent and child processes
 * @str: the name of the program
 * @argv: array containing the commands and args
 * @env: environment variable
 * Return: 1 = success, 0 = failure
 */

int processes(char *str, char **argv, char **env)
{
	int status;
	pid_t cpid;

	cpid = fork(); /*Child process creation*/
	if (cpid == -1)
	{
		perror(str);
		return (0);
	}
	if (cpid == 0)
	{
		if (execve(argv[0], argv, env) == -1)
		{
			perror(str);
			return (0);
		}
	}
	else
		wait(&status);
	return (1);
}
/**
 *handle_path - checks if the command exists
 *@cmd: the command
 *Return: pointer to the absolute path of the command (success), NULL (failure)
 */
char *handle_path(char *cmd)
{
	char *abs_path = NULL, *tmp = NULL, *_path = NULL;
	char slach[2] = "/";
	struct stat st;
	const char *path;
	dir_t *head = NULL;

	path = _getenv("PATH");
	if (path)
	{
		head = path_dir_ls(path); /* builds a linked list of PATH directories*/
		while (head)
		{
			_path = _strcat(head->dir, slach);
			tmp = _strcat(_path, cmd);
			abs_path = _strdup(tmp);
			free(tmp);
			free(_path);
			if (stat(abs_path, &st) == 0)
			{
				free_list(head);
				return (abs_path);
			}
			head = head->next;
		}
		free(abs_path);
		free_list(head);
	}

	return (NULL);
}
