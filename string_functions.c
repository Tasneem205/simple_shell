#include "main.h"


/**
 * _strlen - count length of a string
 * @s: string to count
 *
 * Return: length of string
 */
int _strlen(char *s)
{
    int n = 0;

    while (s[n] != '\0')
        n++;

    return (n);
}

/**
 * _strcmp - compare two strings
 * @s1: string 1
 * @s2: string two
 *
 * Return: comparison
 */
int _strcmp(char *s1, char *s2)
{
    while (*s1 && *s2)
    {
        if (*s1 != *s2)
            return (*s1 - *s2);
        s1++;
        s2++;
    }
    if (*s1 == *s2)
        return (0);
    return (*s1 < *s2 ? -1 : 1);
}

/**
 * starts_with - find if needle starts with haystack
 * @haystack: haystack
 * @needle: the needle
 *
 * Return: address of the next char
 */
char *starts_with(const char *haystack, const char *needle)
{
    while (*needle)
        if (*needle++ != *haystack++)
            return (NULL);
    return ((char *)haystack);
}

/**
 * _strcat - concatenate
 * @dest: destination
 * @src: source
 *
 * Return: pointer to the destination buffer
 */
char *_strcat(char *dest, char *src)
{
    char *ret = dest;

    while (*dest)
        dest++;
    while (*src)
        *dest++ = *src++;
    *dest = *src;
    return (ret);
}