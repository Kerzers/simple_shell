#include <stdio.h>
#include <stdlib.h>
#include <string.h>
extern char **environ;
void print_dir(const char *path);
char *_getenv(const char *name);
/**
 * main - test example
 *
 * Return : 0
 */
int main()
{
        const char *path;

        path = getenv("PATH");
        printf("%s\n", path);
	print_dir(path);
        return (0);
}
