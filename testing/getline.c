#include "main.h"
#include <errno.h>

/**
 *
 */

ssize_t _getline(char **buffer, size_t *n, FILE *stream)
{       
        int fd; 
	int size = 100;
	ssize_t bRead, count = 0;

        if (stream == stdin)
                fd = STDIN_FILENO;
        else
                return (-1);

        if (*buffer == NULL)
        {
		*n = 0;
		*buffer = malloc(sizeof(char) * size);
                if (!*buffer)
                        return(-1);
	printf("Before the bRead\n");		
		bRead = read(fd, *buffer, size);
		if (bRead == -1)
			return (bRead);
		count += bRead;
	printf("bRead: %ld\n", bRead);
		while (bRead != 0)
		{
			if (bRead < size)
			{
				printf("Count returned inside loop: %ld\n", count);
				printf("buff inside return after realloc: %s\n", *buffer);
				return (count);
			}
			printf("buffer inside while before realloc: %s\n", *buffer);
			*buffer = _realloc(*buffer, size, size + 100);
			size += 100;
			printf("buff inside while after realloc: %s\n", *buffer);
			bRead = read(fd, *buffer, size);
			if (bRead == -1)
				return (bRead);
			count += bRead;
			printf("Count inside while after realloc: %ld\n", count);
		}
	}
	printf("Count returned outside: %ld\n", count);
	return (count);
	/*
	else User allocated buffer size dynamically 
	{
		myBuff = malloc(sizeof(char) * 1024);
		if (!myBuff)

		bRead = read(fd, *buffer, *n);
		if (bRead == -1)
	}*/
}
