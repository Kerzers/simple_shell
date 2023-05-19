#include <stdlib.h>
#include "main.h"

/**
 * _freeStr - free memory
 * @mem: the memory to be freed
 */

void _freeStr(char **mem , int n)
{
	int i = 0;

	for(; i <= n; i++)
	{
		free(mem[i]);
	}
	free(mem);
}
