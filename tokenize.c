#include "shell.h"

/**
 * tokenize - Tokenizes a buffer.
 * @buffer: Buffer to tokenize.
 * @delimiter: Delimiter to tokenize too.
 *
 * Return: Pointer to an array of pointers to the tokens.
 */

char **tokenize(char *buffer, char *delimiter)
{
    char **tokens = NULL;
    size_t a = 0, mcount = 10;

    if (buffer == NULL)
        return (NULL);

    tokens = malloc(sizeof(char *) * mcount);
    if (tokens == NULL)
    {
        perror("Fatal Error");
        return (NULL);
    }

    while ((tokens[a] = strtok(buffer, delimiter)) != NULL)
    {
        a++;

        if (a == mcount)
        {
            tokens = _realloc(tokens, &mcount);
            if (tokens == NULL)
            {
                perror("Fatal Error");
                return (NULL);
            }
        }

        buffer = NULL;
    }

    return (tokens);
}
