#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

/**
 *main - looks for files in the current PATH
 *@ac: number of args
 *@av: strings vector
 *Return: 0 (Success)
 */
int main(int ac, char **av)
{
	unsigned int i = 1;
	struct stat st;

    if (ac != 2)
    {
        printf("Usage: %s filename ...\n", av[0]);
        return (1);
    }
    while (av[i])
    {
	    if (stat(av[i], &st) == 0)
	    {
