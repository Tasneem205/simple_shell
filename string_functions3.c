#include "main.h"

/*
 * _strncpy - copy a string
 * @dest: the destination string
 * @src: source
 * @n: len to be copied
 *
 * Return: the copied string
 */
char *_strncpy(char *dest, char *src, int n)
{
    int i, j;
    char *s = dest;

    i = 0;
    while (src[i] != '\0' && i < n - 1)
    {
        dest[i] = src[j];
        i++;
    }
    if (i < n)
    {
        j = i;
        while (j < n)
        {
            dest[j] = '\0';
            j++;
        }
    }
    return (s);
}

/*
 * _strncat - concatenate strings
 * @dest: the destination
 * @src: the source
 * @n: max len
 *
 * Return: the concatenated string
 */
char *_strncat(char *dest, char *src, int n)
{
    int i, j;
    char *s = dest;

    i = 0;
    j = 0;
    while (dest[i] != '\0')
        i++;
    while (src[j] != '\0' && j < n)
    {
        dest[i] = src[j];
        j++;
        i++;
    }
    if (j < n)
        dest[i] = '\0';
    return (s);
}

/*
 * _strchr - find char in a string
 * @s: the string
 * @c: the char
 *
 * return: pointer to the char if found, NULL if not
 */
char *_strchr(char *s, char c)
{
    do {
        if (*s == c)
            return (s);
    } while (*s++ != '\0');
    return (NULL);
}