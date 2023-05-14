#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
/**
 *print_dir : prints each directory contained in the the environment variable
 * PATH, one directory per line.
 *@path: environment variable PATH
 *
 */
void print_dir(const char *path)
{
	int i = 0;
	char *token;

	if (path == NULL)
	{
		perror("Error");
		exit(1);
	}
	token = strtok((char *)path, ":");
	while (token)
	{
		printf("%s\n", token);
		i++;
		token = strtok(NULL, ":");
	}
}
