#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void split_str(char **str);

/**
 *
 *
 *
 */
int main(void)
{
        char *str = "Hello world !";

	split_str(&str);

	return (0);
}

/**
 *split_str - splits a string to words
 *@str: a string
 *@delim: a set of bytes that delimit the tokens in the parsed string
 *Return: an array of each word of the string.
 */
void split_str(char **str)
{
        char *word;

	word = strtok(*str, " ");
        while (word)
        {
		printf("%s\n", word);
                word = strtok(NULL, " ");
        }
}
