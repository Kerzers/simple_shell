#include <stdio.h>
#include <unistd.h>


int main(int ac, char **argv)
{
	(void)ac;

	if (isatty(0))
	{
		printf("... %s %s\n", argv[0], argv[1]);
	}
	else
	{
		printf("%s %s\n", argv[0], argv[1]);
	}
	return (0);
}
