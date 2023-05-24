#include "main.h"

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
