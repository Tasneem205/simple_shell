#include "main.h"

/*
 * _strcpy - copy string
 * @dest: destination
 * @src: source string
 *
 * Return: the destination
 */
char *_strcpy(char *dest, char *src)
{
    int i = 0;

    if (dest == src || src == 0)
        return (dest);
    while (src[i])
    {
        dest[i] = src[i];
        i++;
    }
    return (dest);
}

/*
 * _strdup - duplicate string
 * @str: string to be duplicated
 *
 * Return: pointer to the duplicate
 */
char *_strdup(const char *str)
{
    int len = 0;
    char *ret;

    if (str == NULL)
        return (NULL);
    while (*str++)
        len++;
    ret = malloc(sizeof(char) * (len + 1));
    if (!ret)
        return (NULL);
    for (len++; len--;)
        ret[len] = *--str;
    return (ret);
}

/**
 * _puts - prints a given string followed by a new line
 * @s: string to print
 */
void _puts(char *s)
{
    int i;

    if (!s)
        return;
    for (i = 0; s[i] != '\0'; i++)
        putchar(s[i]);
}

/*
 * _putchar - prints character to stdout
 * @c: the char
 *
 * Return: 1 if true;
 */
int _putchar(char c)
{
    static int i;
    static char buf[WRITE_BUF_SIZE];

    if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
    {
        write(1, buf, 1);
        i = 0;
    }
    if (c != BUF_FLUSH)
        buf[i++] = c;
    return (1);
}