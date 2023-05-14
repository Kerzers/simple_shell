#include "main.h"
#include <stdio.h>
dir_t *add_node_end(dir_t **head, const char *str);

/**
 *path_dir_ls - builds a linked list of the PATH directories.
 *@path: the value of PATH
 *Return: linked list of the PATH directories.
 */
dir_t path_dir_ls(const char *path)
{
	dir_t **head;
	const char *token;

	
       	token = strtok((char *)path, ":");
        while (token)
        {
        	add_node_end(head, token);
                i++;
                token = strtok(NULL, ":");
        }
	return (*head)
}
