#include "shell.h"

/**
 * add_value - create a new environment variable string
 * @key: variable name
 * @value: variable value
 *
 * Return: Pointer to the new string, or NULL if memory allocation fails.
 */

char *add_value(char *key, char *value)
{
    unsigned int l1, l2, a, b;
    char *new;

    l1 = _strlen(key);
    l2 = _strlen(value);
    new = malloc(sizeof(char) * (l1 + l2 + 2));
    
    if (new == NULL)
        return (NULL);
    for (a = 0; key[a] != '\0'; a++)
        new[a] = key[a];
    new[a] = '=';
    for (b = 0; value[b] != '\0'; b++)
        new[a + 1 + b] = value[b];
    new[a + 1 + b] = '\0';
    
    return (new);
}
