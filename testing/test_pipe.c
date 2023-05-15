#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>


int main(int ac, char **argv)
{
	char *buffer = NULL;
	size_t n = 0;
	ssize_t br;

	(void)ac;
	if (isatty(0))
	{
		printf("... %s %s\n", argv[0], argv[1]);
	}
	else
	{
		br = getline(&buffer, &n, stdin);
		if (br  == -1)
		{
			return (0);
		}
		else
		{
			printf("%s", buffer);
		}
	/*buffer = malloc(sizeof(char) * 1024);
	if (buffer == NULL)
		return (0);
	read(fd, buffer, 1024);

		printf("%s %s\n", argv[0], buffer);*/
	}
	return (0);
}
