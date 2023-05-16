#include "main.h"

dir_t *path_dir_ls(const char *path);
size_t print_list(const dir_t *h);

/**
 *main - test program linked list path directories
 *
 *Return: 0 success
 */

int main()
{
	dir_t *head = NULL;
	const char *path;

	path = getenv("PATH");
	head = path_dir_ls(path);
	print_list(head);
	return(0);
}
/**
 * print_list - prints all the elements of a dir_t list
 * @h: the list to be printed
 * Return: number of nodes
 * If str is NULL, print [0] (nil)
 */
size_t print_list(const dir_t *h)
{
	size_t n = 0;

	while (h)
	{
		if (h->dir)
			printf("%s\n", h->dir);
		else
			printf("[0] (nil)\n");
	n++;
	h = h->next;
	}
	return (n);
}
