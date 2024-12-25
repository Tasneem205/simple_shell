#include "main.h"

/*
 * strtow - string to words array
 * @str: the string
 * @d: delimiter
 *
 * Return: array of words or NULL
 */
char **strtow(char *str, char *d)
{
    int i, j, k, m, num;
    char **s;

    num = 0;
    if (str == NULL || str[0] == 0)
        return (NULL);
    if (!d)
        d = " ";
    for (i = 0; str[i] != '\0'; i++)
        if (!is_delim(str[i], d) && (is_delim(str[i + 1], d) || !str[i + 1]))
            num++;
    if (num == 0)
        return (NULL);
    s = malloc((i + num) * sizeof(char *));
    if (!s)
        return (NULL);
    for (i = 0, j = 0; j < num; j++)
    {
        while (is_delim(str[i], d))
            i++;
        k = 0;
        while (!is_delim(str[i + k], d) && str[i + k])
            k++;
        s[j] = malloc((k + 1) * sizeof(char *));
        if (!s[j])
        {
            for (k = 0; k < j; k++)
                free(s[k]);
            free(s);
            return (NULL);
        }
        for (m = 0; m < k; m++)
            s[j][m] = str[i++];
        s[i][m] = 0;
    }
    s[j] = NULL;
    return (s);
}

/*
 * strtow2 - string to words
 * @str: the string
 * @d: delimeter
 *
 * Return: array of words
 */
char **strtow2(char *str, char d)
{
    int i, j, k, m, num;
    char **s;

    num = 0;
    if (str == NULL || str[0] == 0)
        return (NULL);
    for(i = 0; str[i] != '\0'; i++)
        if ((str[i] != d && str[i + 1] == d) ||
            (str[i] != d && !str[i + 1]) || str[i + 1] == d)
            num++;
    if (num == 0)
        return (NULL);
    s = malloc((i + num) * sizeof(char *));
    if (!s)
        return  (NULL);
    for (i = 0, j = 0; j < num; j++)
    {
        while (str[i] == d && str[i] != d)
            i++;
        k = 0;
        while (str[i + k] != d && str[i + k] && str[i + k] != d)
            k++;
        s[j] = malloc((k + 1) * sizeof(char));
        if (!s[j])
        {
            for (k = 0; k < j; k++)
                free(s[k]);
            free(s);
            return (NULL);
        }
        for (m = 0; m < k; m++)
            s[j][m] = str[i++];
        s[j][m] = 0;
    }
    s[j] = NULL;
    return (s);
}

