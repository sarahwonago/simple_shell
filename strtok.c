#include "shell.h"

/**
 * strtok - Tokenize a string based on a delimiter.
 * @str: The string to tokenize.
 * @delim: The delimiter to tokenize against.
 *
 * Return: A pointer to the next token or NULL if no more tokens are found.
 */
char *strtok(char *str, const char *delim)
{
    static char *_start;
    static char *_token;
    unsigned int a;

    if (str != NULL)
       _token = str;
    _start = _token;
    if (_start == NULL)
        return (NULL);
    for (a = 0; _token[a] != '\0'; a++)
    {
        if (check_match(_token[a], delim) == 0)
            break;
    }
    if (_token[a] == '\0' || _token[a] == '#')
    {
        _token = NULL;
        return (NULL);
    }
    _start = _token + a;
    _token = _start;
    for (a = 0; _token[a] != '\0'; a++)
    {
        if (check_match(_token[a], delim) == 1)
            break;
    }
    if (_token[a] == '\0')
        _token = NULL;
    else
    {
        _token[a] = '\0';
        _token = _token + a + 1;
        if (*_token == '\0')
            _token = NULL;
    }
    return (_start);
}
