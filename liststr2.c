#include "main.h"

/**
 *list_len - Returns the number of elements
 *in a linked listint_t list
 *@h: A pointer to the head of the list
 *
 *
 *Return: the number of elements in the listint_t list
 */

size_t list_len(const list_t *h)
{
    size_t nodes = 0;

    while (h)
    {
        nodes++;
        h = h->next;
    }
    return (nodes);
}

/**
 *list_to_strings - Returns the number of elements
 *@head: A pointer to the head of the list
 *
 *Return: the number of elements in the listint_t list
 */
char **list_to_strings(list_t *head)
{
    list_t  *node = head;
    size_t i = list_len(head), j;
    char **strs;
    char *str;

    if (!head || !i)
        return (NULL);
    strs = malloc(sizeof(char *) * (i + 1));
    if (!strs)
        return (NULL);
    for (i = 0; node; node = node->next, i++)
    {
        str = malloc(_strlen(node->str) + 1);
        if (!str)
        {
            for (j = 0; j < i; j++)
                free(strs[j]);
            free(strs);
            return (NULL);
        }
        str = _strcpy(str, node->str);
        strs[i] = str;
    }
    strs[i] = NULL;
    return (strs);
}

/**
* print_list - prints all the elements of a list
*
* @h:pointer to the list
*
*Return: the number of nodes
*/

size_t print_list(const list_t *h)
{
    size_t count = 0;

    while (h)
    {
        _puts(convert_number(h->num, 10, 0));
        _putchar(':');
        _putchar(' ');
        _puts(h->str ? h->str : "(nil)");
        _puts("\n");
        h = h->next;
        count++;
    }

    return (count);
}

/**
 *node_starts_with - find matching node
 *@node: A pointer to the head of the list
 *@prefix: string to match
 * @c: next char
 *
 *Return: matching node or null
 */
list_t *node_starts_with(list_t *node, char *prefix, char c)
{
    char *p = NULL;

    while (node)
    {
        p = starts_with(node->str, prefix);
        if (p && ((c == -1) || (*p == c)))
            return (node);
        node = node->next;
    }
    return (NULL);
}

/**
 *get_node_index - Returns the index of a node
 *@h: A pointer to the head of the list
 *@n: the node
 *
 *Return: the number of elements in the listint_t list
 */
ssize_t get_node_index(list_t *h, list_t *n)
{
    size_t i = 0;
    while (h)
    {
        if (h == n)
            return i;
        h = h->next;
        i++;
    }
    return (-1);
}