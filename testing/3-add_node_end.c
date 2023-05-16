#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 *add_node_end - adds a node at the end of a dir_t list
 *@head: double pointer to the head of list
 *@str: string to be duplicated
 *Return: a pointer to the new element, or NULL if it failed
 */
dir_t *add_node_end(dir_t **head, const char *str)
{
	dir_t *new = NULL;
	dir_t *last = *head;

	new = malloc(sizeof(dir_t));
	if (new == NULL)
		return (NULL);
	new->dir = strdup(str);
	new->next = NULL;
	if (*head == NULL)
	{
		*head = new;
		return (new);
	}
	while (last->next)
		last = last->next;
	last->next = new;
	return (new);
}
