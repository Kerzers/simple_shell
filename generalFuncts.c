#include "main.h"

/**
 *_strcpy - copies the string pointed to by src to the
 * buffer pointed to by dest
 *@dest: pointer as a parameter
 *@src: pointer as a parameter
 * Return: the pointer to dest
 */

char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return (dest);
}

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

/**
 *_getenv - gets an environment variable
 *@name: environment variable
 *Return: the value of environment variable
 *
 */
char *_getenv(const char *name)
{
	char **env = environ;
	char *token;
	int i = 0;


	while (env[i])
	{
		token = strtok(env[i],"=");
		if (strcmp(name,token) == 0)
		{
			token = strtok(NULL, "");
			return (token);
		}
	i++;
	}
	return (NULL);
}

/**
 *path_dir_ls - builds a linked list of the PATH directories.
 *@path: the value of PATH
 *Return: linked list of the PATH directories.
 */
dir_t *path_dir_ls(const char *path)
{
	dir_t *head = NULL;
	const char *token;


       	token = strtok((char *)path, ":");
        while (token)
        {
        	add_node_end(&head, token);
                token = strtok(NULL, ":");
        }
	return (head);
}
