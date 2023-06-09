#include "main.h"
#include <string.h>
#include <errno.h>

/**
 *
 */

ssize_t _getline(char **buffer, size_t *n, FILE *stream)
{       
        int fd, i, size = BUFFER_SIZE; 
	ssize_t bRead, count = 0;
	char buf[BUFFER_SIZE];

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
		
		while ((bRead = read(fd, &buf, BUFFER_SIZE)) > 0)
		{		
			count += bRead;
			if (count == bRead)
			{
				*buffer = strdup(buf);
				if (!*buffer)
					return (-1);
			}
			else
			{
				*buffer = strcat(*buffer, buf);
				if (!*buffer)
                                        return (-1);
			}
			
			if (*(*buffer + (count - 1)) == '\n')
			{
				*(*buffer + count) = '\0';
				return(count);
			}

			*buffer = _realloc(*buffer, size, size + BUFFER_SIZE);
			size += BUFFER_SIZE;

			for (i = 0; i < BUFFER_SIZE; i++)
				buf[i] = '\0';
		}
	}
	else
	{
		for (i = 0; i < *n; i++)
                          buffer[i] = '\0';
		while ((bRead = read(fd, &buf, BUFFER_SIZE)) > 0)
                {
			count += bRead;
			if (count == bRead)
			{
				if (*n < bRead)
				{
				*buffer = _realloc(*buffer, *n, *n + BUFFER_SIZE);
				*n += BUFFER_SIZE;
				*buffer = strdup(buf);
				}
				else
				{
				*buffer = strdup(buf);
				return (count);
				}
			}
			else
			{
				if (*n < bRead)
				{
				*buffer = _realloc(*buffer, *n, * + BUFFER_SIZE);
				*n += BUFFER_SIZE;
				*buffer = strcat(*buffer, buf);
				}
				else
				{
					*buffer = strcat(*buffer, buf);
					return (count);
				}
				if (*(*buffer + count - 1) == '\n' && *n == bRead)
				{
					*buffer = realloc(*buffer, *n, *n + 1);				
					*(*buffer + count) = '\0';
					return (count);
				}	
			}
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
