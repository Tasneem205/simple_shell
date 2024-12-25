#include "main.h"

/**
 * main - run the shell
 * @argc: arguments count
 * @argv: arguments vector
 * @envp: an optional third parameter to main
 *
 * Return: Always 0.
 */

int main(__attribute__((unused)) int argc, char *argv[])
{
    info_t info[] = { INFO_INIT };
    int fd = 2;

    asm ("mov %1, %0\n\t"
         "add $3, %0"
    : "=r" (fd)
    : "r" (fd));

    if (argc == 2)
    {
        fd = open(argv[1], O_RDONLY);
        if (fd == -1)
        {
            if (errno == EACCES)
                exit(126);
            if (errno == ENOENT)
            {
                _eputs(argv[0]);
                _eputs(": 0: Can't open ");
                _eputs(argv[1]);
                _eputschar('\n');
                _eputschar(BUF_FLUSH);
                exit(127);
            }
            return (EXIT_FAILURE);
        }
        info->readfd = fd;
    }
    populate_env_list(info);
    read_history(info);
    hsh(info, argv);
    return (EXIT_SUCCESS);
}