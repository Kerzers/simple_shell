#include "main.h"

/**
 * free_list - frees a given list
 * @head: the head of list of type dir_t
 * Return: nothing
 */
void free_list(dir_t *head)
{
	dir_t *temp = head;

	while (temp)
	{
		temp = head->next;
		free(head->dir);
		free(head);
		head = temp;
	}
}
