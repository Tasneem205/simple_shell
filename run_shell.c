#include "main.h"

/**
 * perform_cmd - gets the command and start performing it
 *
 * Return: always 0
 */

void perform_cmd(void)
{
	char *line = NULL;
	size_t len = 0;
	int read;
	char **args;

	/* first, we get the command using getline() */
	read = getline(&line, &len, stdin);
	/* if getline failed e.g. EOF (end_of_file) was there, we end */
	if (read == -1)
	{
		fflush(stdin);
		free(line);
		perror(prog_name);
		return;
	}

	/* let's tokenize the command into args */
	args = tokenize(line, " \t\n");
	/* check for builtins and perform them */
	if (cmd_is(args[0], "exit"))
		exit_flag = true;  /* just mark the exit flag */
	else if (cmd_is(args[0], "env"))
		print_env();
	/* we make sure the command exists. if it fails, we stop */
	else if (!cmd_exists(args[0]))
		perror(prog_name);
	/* now, we're sure that the command exists, so we execute it */
	else
		execute(args);
	/*check for builtins and perform them*/
	if (cmd_is(args[0], "exit"))
		exit_flag = true;
	else if (cmd_is(args[0], "env"))
		print_env();
	else if (!cmd_exists(args[0]))
		perror(prog_name);
	else
		execute(args);
	free_tokens(args);
	free(line);
}

/**
 * execute - poerforms the cmd using excev
 *@args: the command line arguments
 *
 *Return: always true
 */
void execute(char **args)
{
	int wstatus = 0, cpid = 0;

	/* we fork the process so that our process remains and program continues */
	cpid = fork();
	if (cpid == -1)
	{
		/* fork was not successful */
		perror("fork");
	}
	else if (cpid == 0)
	{
		/* we're in the child process, so execute */
		execve(args[0],
		(char * const *) args,
		(char * const *) environs);
		/* if execve returns, there is something wrong */
		perror(prog_name);
		exit(EXIT_FAILURE);
	}
	else
	{
		/* we're in the main process, so we wait for the child to finish */
		wait(&wstatus);
	}
}

