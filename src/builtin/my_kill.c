/*
** EPITECH PROJECT, 2018
** my_kill
** File description:
** my_kill
*/

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"
#include "error.h"
#include "my.h"

const char *kill_usage[] =
{
	"Usage:\n\tkill -signum pid\n",
	"Send the process identified by PID the signal named by SIGNUM.",
	NULL
};

static int print_kill_usage(void)
{
	for (size_t i = 0; kill_usage[i] != NULL; i++)
		printf("%s\n", kill_usage[i]);
	return (EXIT_FAILURE);
}

int my_kill(shell_t *shell, int argc, char **argv)
{
	int signal = 0;
	pid_t pid;

	(void) shell;
	if (argc != 3) {
		printf(argc > 3 ? TOO_ARG : FEW_ARG, argv[0]);
		return (EXIT_FAILURE);
	}
	if (!my_atoi(&signal, argv[1]) || !IS_NEG(signal))
		return (print_kill_usage());
	if (!my_atoi(&pid, argv[2]))
		return (print_kill_usage());
	if (kill(pid, -signal) == -1)
		return (perror(NULL), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
