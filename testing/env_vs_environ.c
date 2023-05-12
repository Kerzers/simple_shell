#include <stdio.h>

extern char **environ;
/**
 * main - prints the environment using env and environ
 *
 * Return: Always 0.
 */
int main(int ac, char **av, char **env)
{
    unsigned int i;
    char **envir = environ;

    printf("Print environment using env\n");
    i = 0;
    while (env[i] != NULL)
    {
        printf("%s\n", env[i]);
        i++;
    }
    printf("Print environment using environ\n");
    i = 0;
    while (envir[i] != NULL)
    {
        printf("%s\n", envir[i]);
        i++;
    }
    return (0);
}
