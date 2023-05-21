#include "main.h"
#include <errno.h>

/**
 *
 */

ssize_t _getline(char **buffer, size_t *n, FILE *stream)
{       
        int fd;
	ssize_t bRead;
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
		for (i = 0; i < 1024; i++)
		{
			bRead = read(fd, *buffer[i], 1);
			if (*buffer[i] != EOF)
				return (i);
		}

	}
	else /* User allocated buffer size dynamically */
	{
		myBuff = malloc(sizeof(char) * 1024);
		if (!myBuff)

		bRead = read(fd, *buffer, *n);
		if (bRead == -1)


	}
}
