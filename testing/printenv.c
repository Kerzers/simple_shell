#include <stdio.h>

extern char **environ;
/**
 * main - prints the environment with environ
 *
 * Return: Always 0.
 */
int main()
{
    unsigned int i;
    char **env = environ;

    i = 0;
    while (env[i] != NULL)
    {
        printf("%s\n", env[i]);
        i++;
    }
    return (0);
}
