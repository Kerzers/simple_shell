#include "main.h"
#include <errno.h>

/**
 *
 */

ssize_t _getline(char **buffer, size_t *n, FILE *stream)
{       
        int fd, size = 1024;
	ssize_t bRead;
	char *newBuffer;
	size_t readSize;
	char *myBuff;

        if (stream == stdin)
                fd = STDIN_FILENO;
        else
                return (-1);

        if (buffer = NULL)
        {
		*n = 0;
		*buffer = malloc(sizeof(char) * 1024);
                if (!*buffer)
                        return(-1);
		for (i = 0; i < size; i++)
		{
			bRead = read(fd, *buffer[i], 1);
			if (bRead == -1)
			{
				return (-1);
			}
			if (*buffer[i] == EOF)
			{
				bRead = (ssize_t)i;
				return (bRead);
			}
		}

		newBuffer = _realloc();

	}
	else /* User allocated buffer size dynamically */
	{
		myBuff = malloc(sizeof(char) * 1024);
		if (!myBuff)

		bRead = read(fd, *buffer, *n);
		if (bRead == -1)


	}
}
