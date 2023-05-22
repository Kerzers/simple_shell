#include <string.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include "main.h"

/**
 * main - reads line and prints it in terminal
 *
 *Return: 0 (Sucess)
 */
int main(void)
{
        ssize_t n;
        size_t size = 0;
        char *buffer = NULL;
/*	pid_t cpid;
	char *argv[2];
	int status;*/

	printf("#cisfun$ ");
        n = _getline(&buffer, &size, stdin);
        if (n == -1)
	{
		printf("Error %ld\n", n);
                return (0);
	}

	printf("Buffer: %s\n", buffer);

	/*argv[0] =strtok(buffer, "\n");
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
		wait(&status);*/
        free(buffer);
        return (0);
}
