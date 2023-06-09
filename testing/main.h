#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>

#define BUFFER_SIZE 1024

extern char **environ;

/**
 * struct path_dir - singly linked list of path's directories
 * @dir: a directory in the path
 * @next: points to the next directory in the path
 */

typedef struct path_dir
{
        char *dir;
        struct path_dir *next;
} dir_t;

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
ssize_t _getline(char **buffer, size_t *n, FILE *stream);
void interactive(char *str);
void non_interactive(char *str);
int processes(char *str, char **argv);
int _putchar(char c);
char *_strcpy(char *dest, char *src);
#endif /* MAIN_H */
