#include "main.h"

/**
 * errors - displays errors in stderr
 * @program: program's name
 * @iter: numbers of prompt typed by the user
 * @cmd: command's name
 */
void errors(char *program, int iter, char *cmd)
{
	write(STDERR_FILENO, program, myStrLen(program));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, &iter, sizeof(iter));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, myStrLen(cmd));
	write(STDERR_FILENO, ": not found\n", 12);
}

/**
 *handle_sigint - handle the ^C
 *@sig: signal number
 *
 */
void handle_sigint(int sig)
{
	const char *prompt = "#s_shell$ ";

	(void)sig;
	_putchar('\n');
	write(STDOUT_FILENO, prompt, 10);
}
/**
 *handle_sigtstp - handle the ^Z
 *@sig: signal number
 *
 */
void handle_sigtstp(int sig)
{
	const char *prompt = "#s_shell$ ";

	(void)sig;
	write(STDOUT_FILENO, prompt, 10);
}
