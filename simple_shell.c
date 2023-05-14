#include "main.h"

/**
 * main - the main function of the program
 * @ac: the  number of arguments passed .to the program call
 * @argv: string array containing the program name and args
 * Return: always 0
 */

int main(int ac, char **argv)
{
        ssize_t n;
        size_t size = 0;
        char *buffer = NULL;
	pid_t cpid;
	char *argv[2];
	int status;

	if (ac == 1)
	{
		interactive(argv[0]);
	}
	
	
	while (1)
	{
		printf("#cisfun$ ");
		n = getline(&buffer, &size, stdin);
		if (n == -1)
                break;
	argv[0] =strtok(buffer, "\n");
	argv[1] = NULL;
	cpid = fork();
	if (cpid == -1)
	{
		perror("Error");
		break;
	}else if (cpid == 0)
	{
		if (execve(argv[0], argv, NULL) == -1)
    		{
        	perror("Error:");
		break;
 		}
	}
	else
		wait(&status);
	}
        free(buffer);
        return (0);

}

/**
 *interactive - for the intercative mode
 */

void interactive(char *cmd)
{
	char *prompt = "#s_shell$ ";
	int n;
	char *buffer = NULL, *cmdCpy;
	size_t size = 0;

	while (1)
	{
		write(STDOUT_FILENO, prompt, 9);
		n = getline(&buffer, &size, stdin);
		if (n == -1)
		{
			perror("User input");
			exit(1);
		}

		_strcpy(cmdCpy, cmd);
	}
}
