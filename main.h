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
#include <limits.h>

/**
 * struct path-dir - singly linked list of path's directories
 * @dir: a directory in the path
 * @next: points to the next directory in the path
 */


typedef struct path-dir
{
        char *dir;
        struct path-dir *next;
} dir_t;

#endif /* MAIN_H */
