#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>

int main(void)
{
	char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};
	pid_t cpid;
	int status, i;

	for (i = 0; i < 5; i++)
	{
		cpid =  fork(); /*Starts the child*/
		if (cpid == -1)
		{
			perror("Child process error ");
			exit(1);
		}
		else if (cpid == 0)
		{
			if (execve(argv[0], argv, NULL) == -1)
			{
				perror("Child process execution error ");
				return (1);
			}
		}
		else
		{
			wait(&status);

		}
	}
	return (0);
}
