#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>


int main(int ac, char **argv)
{
	int fd;
	char *buffer;
	ssize_t n;

	(void)ac;
	if (isatty(0))
	{
		printf("... %s %s\n", argv[0], argv[1]);
	}
	else
	{
		fd = open(stdin, O_RDONLY);
		if (fd == -1)
		{
			perror(argv[0]);
		}
	buffer = malloc(sizeof(char) * 1024);
	if (buffer == NULL)
		return (0);
	read(fd, buffer, 1024);

		printf("%s %s\n", argv[0], buffer);
	}
	return (0);
}
