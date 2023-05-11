#include <stdio.h>
#include <string.h>


char **split_str(char *str, char *delim);

/**
 *
 *
 *
 */
int main(void)
{
        char *str = "Hello world !";
        char *delim = " ";
        char **words;

        words = split_str(str, delim);
        printf("%s\n", words[0]);

	return (0);
}

/**
 *split_str - splits a string to words
 *@str: a string
 *@delim: a set of bytes that delimit the tokens in the parsed string
 *Return: an array of each word of the string.
 */
char **split_str(char *str, char *delim)
{
        char **word = NULL;
        int i = 0;

	word = malloc(100 * sizeof(char *));

        word[i] = strtok(str, delim);
        while (word[i])
        {
		i++;
                word[i] = strtok(NULL, delim);
        }

	return (word);
}
