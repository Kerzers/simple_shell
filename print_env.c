#include "main.h"

/**
 *print_env - prints environ
 *
 *
 */
void print_env(void)
{
	char **env = environ;

	while (*env)
	{
		write(1, *env, myStrLen(*env));
		_putchar('\n');
		env++;
	}
}
