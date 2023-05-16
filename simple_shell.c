#include "main.h"

/**
 * main - the main function of the program
 * @ac: the  number of arguments passed to the program call
 * @argv: string array containing the program name and args
 * Return: always 0
 */

int main(int ac, char **argv)
{
	/*const char *usage = "usage: ";*/


	if (isatty(STDIN_FILENO))
	{
		if (ac == 1)
		{
			interactive(argv[0]);	
		}
		if (ac > 1)	
		{
			argv++;
			processes(argv[0], argv);
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
	char *buffer = NULL;
	char *argv[2];
	size_t size = 0;

	n = getline(&buffer, &size, stdin);
	if (n == -1)
		return;

	argv[0] = strtok(buffer, "\n");
	argv[1] = NULL;
	processes(str, argv);
	free(buffer);
}

/**
 * interactive - for the intercative mode
 * @str: name of the program
 */

void interactive(char *str)
{
	const char *prompt = "#s_shell$ ";
	int n, num, a;
	char *buffer = NULL;
	char **argv;
	char *abs_path = NULL;
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
		num = tokenCount(buffer);
		argv = tokenizer(buffer, num);

		for (a = 0; a < (num + 1); a++)
		{
			argv[a] = malloc(sizeof(char *) * );
		}

		argv[0] = strtok(buffer, " \t\n");
		abs_path = handle_path(argv[0]);
		printf("%s\n", abs_path);
		if (!abs_path)
		{
			perror(str);
		}
		else
		{	
		argv[0] = abs_path;
		argv[1] = NULL;
		if (!argv[0])
		{
		}
		else
		{
			if (!processes(str, argv))
				break;
		}
		}
	}
	free(buffer);
}

/**
 * processes - starts and ends parent and child processes
 * @str: the name of the program
 * @argv: array containing the commands and args
 * Return: 1 = success, 0 = failure
 */

int processes(char *str, char **argv)
{
	int status;
	pid_t cpid;

	cpid = fork(); /*Child process creation*/
	if (cpid == -1)
	{
		perror(str);
		return(0);
	}
	if (cpid == 0)
	{
		if (execve(argv[0], argv, NULL) == -1)
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
 *@str: the command
 *Return: pointer to the absolute path of the command (success), NULL (failure)
 */
char *handle_path(char *cmd)
{
	char *abs_path = NULL,*_path = NULL;
	char slach[2] = "/";
	struct stat st;
	const char *path;
	dir_t *head = NULL;

	if (stat(cmd, &st) == 0)
		return (cmd);
	path = _getenv("PATH");
	printf("%s\n", path);
	head = path_dir_ls(path); /* builds a linked list of PATH directories*/
	/*print_list(head);*/
	while (head)
	{
		_path = strcat(head->dir, slach);
		printf("%s\n", _path);
		abs_path = strdup(strcat(_path, cmd));
		printf("%s\n", abs_path);
		if (stat(abs_path, &st) == 0)
		{	printf("%s\n", abs_path);
			free_list(head);
			return (abs_path);
		}
	head = head->next;
	}
	return (NULL);
}
