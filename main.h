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

extern char **environ;

/**
 * struct path_dir - singly linked list of path directories
 * @dir: a directory in the path
 * @next: points to the next directory in the path
 */

typedef struct path_dir
{
        char *dir;
        struct path_dir *next;
} dir_t;

void interactive(char *str, char **env);
int tokenCount(char *str);
void non_interactive(char *str, char **env);
int processes(char *str, char **argv, char **env);
int _putchar(char c);
char *handle_path(char *cmd);
size_t print_list(const dir_t *h);
dir_t *path_dir_ls(const char *path);
void free_list(dir_t *head);
char **tokenizer(char *buffer);
int myStrLen(const char *str);
void _freeStr(char **mem, int n);
int find_path(char **argv, char *buffer, char *str);
dir_t *add_node_end(dir_t **head, char *str);
char *_getenv(const char *name);
char *_strdup(char *src);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
int cmdLinePath(char **argv, char *str);
int _strcmp(const char *s1, const char *s2);
#endif /* MAIN_H */
