#include "main.h"

/**
 *
 */
int main()
{
	int iter = 14;
	char *program = "./hsh";
	char *cmd = "sl";
	char _iter = iter + '0';
	printf("iter before: %d\n", iter);
	write(STDERR_FILENO, program, strlen(program));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, &_iter, sizeof(char));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, strlen(cmd));
	write(STDERR_FILENO, ": not found\n", 12);
	printf("iter : %d\n", iter);
	return (0);
}
