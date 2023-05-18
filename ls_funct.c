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
/**
 *add_node_end - adds a node at the end of a dir_t list
 *@head: double pointer to the head of list
 *@str: string to be duplicated
 *Return: a pointer to the new element, or NULL if it failed
 */
dir_t *add_node_end(dir_t **head, char *str)
{
	dir_t *new = NULL;
	dir_t *last = *head;

	new = malloc(sizeof(dir_t));
	if (new == NULL)
		return (NULL);
	new->dir = _strdup(str);
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
/**
 *path_dir_ls - builds a linked list of the PATH directories.
 *@path: the value of PATH
 *Return: linked list of the PATH directories.
 */
dir_t *path_dir_ls(const char *path)
{
	dir_t *head = NULL;
	char *token;


       	token = strtok((char *)path, ":");
        while (token)
        {
        	add_node_end(&head, token);
                token = strtok(NULL, ":");
        }
	return (head);
}
