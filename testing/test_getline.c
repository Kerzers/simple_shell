#include "main.h"
#include <string.h>
#include <errno.h>

ssize_t _getline(char **buffer, size_t *n, FILE *stream);

int main()
{
	char *line;
	size_t n = 5;
	ssize_t readline;

	line = malloc(n * sizeof(char));
	if (!line)
		return (1);
	readline = _getline(&line, &n, stdin);
	if (readline == -1)
        {
                printf("Error %ld\n", readline);
                return (0);
        }

        printf("Buffer: %s\n%ld\n", line, readline);
	free(line);
	return (0);
}



/**
 *
 */

ssize_t _getline(char **buffer, size_t *n, FILE *stream)
{
        int fd;
	size_t i;
        ssize_t bRead, count = 0;
        char buf[10];
	
	printf("n: %ld\n", *n);
        if (stream == stdin)
                fd = STDIN_FILENO;
        else
                return (-1);
	if (*buffer)
	{
		printf("n: %ld\n", *n);
		for (i = 0; i < *n; i++)
                          buffer[i] = '\0';
		printf("n: %ld\n", *n);
                while ((bRead = read(fd, &buf, 10)) > 0)
                {
                        count += bRead;
			printf("count: %ld\n", count);
                        if (count == bRead)
                        {
                                if (*n < (size_t)bRead)
                                {
					printf("n: %ld\n", *n);
                                *buffer = _realloc(*buffer, *n, *n + 10);
				printf("buffer after realloc%s\n", *buffer);
                                *n += 10;
                                *buffer = strdup(buf);
				for (i = 0; i < 10; i++)
                                        buf[i] = '\0';
				if (*buffer)
					printf("....%s\n", *buffer);
                                }
                                else
                                {
                                *buffer = strdup(buf);
				if (*buffer)
                                        printf("1st without realloc....%s\n", *buffer);
                                return (count);
                                }
                        }
                        else
                        {
                                if (*n < (size_t)bRead)
                                {
                                *buffer = _realloc(*buffer, *n, *n + 10);
				printf("buffer after realloc%s\n", *buffer);
                                *n += 10;
                                *buffer = strcat(*buffer, buf);
				for (i = 0; i < 10; i++)
                                        buf[i] = '\0';
				if (*buffer)
                                        printf("----%s\n", *buffer);
                                }
                                else
                                {
                                        *buffer = strcat(*buffer, buf);
					if (*buffer)
                                        	printf("+++++%s\n", *buffer);
                                        return (count);
                             	}
			}
			if (*(*buffer + count - 1) == '\n')
                        {
				*buffer = _realloc(*buffer, *n, *n + 1);
                                *(*buffer + count) = '\0';
                                return (count);
			}
                }
        }
	printf("count before last return %ld\n", count);
	return(count);
}

