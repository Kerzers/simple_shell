#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 *add_node - adds a node at the beginning of a list dir_t
 *@head: double pointer to the head of list
 *@str: string to be duplicated
 *Return: a pointer to the new element, or NULL if it failed
 */
dir_t *add_node(dir_t **head, const char *str)
{
	dir_t *new = NULL;

	new = malloc(sizeof(dir_t));
	if (new == NULL)
		return (NULL);
	new->dir = strdup(str);
	new->next = *head;
	*head = new;
	return (new);
}
