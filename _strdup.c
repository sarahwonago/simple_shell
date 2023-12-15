#include "shell.h"

/**
 * _strdup - Returns a pointer to new memory-allocated space containing a copy.
 * @strtodup: String to be duplicated.
 *
 * Return: A pointer to the new duplicated string.
 */
char *_strdup(char *strtodup)
{
    char *copy;
    int len, a;

    if (strtodup == 0)
        return (NULL);

    for (len = 0; strtodup[len]; len++)
        ;

    copy = malloc((len + 1) * sizeof(char));

    for (a = 0; a <= len; a++)
        copy[a] = strtodup[a];

    return (copy);
}
