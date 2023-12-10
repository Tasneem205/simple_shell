#include <stdio.h>
#include "main.h"

/**
 * main - run the shell
 * @argc: arguments count
 * @argv: arguments vector
 * @envp: an optional third parameter to main
 * Return: Always 0.
 */

int main(int argc, char *argv[], char *envp[])
{
	program_name = argv[0];
	environ = envp;
	paths = tokenize(_get_env("PATH"), ":");
	exit_flag = false;

	if (isatty(STDIN_FILENO))
	{
		while (true)
		{
			/* display prompt */
			write(STDOUT_FILENO, "> ", 2);
			perform_cmd();
			/* if exit flag was set */
			if (exit_flag)
				break;
		}
	}
	/* if there is echo or pipe, just perform and finish */
	else
	{
		get_perform_cmd();
	}

	free_tokens(paths);
	return (0);
}
