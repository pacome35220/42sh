/*
** EPITECH PROJECT, 2018
** shell
** File description:
** shell
*/

#pragma once

#include <limits.h>
#include <sys/types.h>
#include "parser.h"

#define	DEFAULT		"\033[00m"
#define	GREEN		"\033[0;32m"
#define	BLUE		"\033[0;34m"
#define	RED		"\033[31;1m"

#define	SHRC		".42shrc"

#define	FLAGS_R		(O_CREAT | O_RDWR | O_TRUNC)
#define	FLAGS_DR	(O_CREAT | O_RDWR | O_APPEND)
#define	MODE		(S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH)

#define	IS_NEG(x)	(x >> (sizeof(int) * CHAR_BIT - 1))
#define	IS_SEPARATOR(x)	(x == ' ' || x == '\t')
#define	IS_NUM(x)	(x >= '0' && x <= '9')
#define	IS_LETTER(x)	((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z'))
#define	IS_ALPHA(x)	(IS_LETTER(x) || IS_NUM(x))

typedef struct
{
	char		*delim;
	char		*end;
	enum id_delim	id;
	enum type_delim type;
} delim_tab_t;

typedef struct
{
	char		*alias;
	char		**cmd;
} alias_t;

typedef struct
{
	sep_list_t	*list;
	alias_t		*alias;
	char		**env;
	char		**path;
	pid_t		pgid;
	int		last_return;
	int		save_fd[2];
} shell_t;

typedef struct
{
	int	(*func)(shell_t *shell, int argc, char **argv);
	char	*cmd;
} builtin_t;

void	signal_ign(bool mdr);
bool	init_struct(shell_t *shell, char **env);
void	load_42shrc(shell_t *shell);
bool	input_parser(shell_t *shell, int fd);
void	print_prompt(shell_t *shell);
int	shell_close(shell_t *shell, int fd, bool mdr);
void	free_list(shell_t *shell);

/*
**	EXEC
*/

void	my_exec(shell_t *shell, sep_list_t *list);
int	exec_pipe(shell_t *shell, pipe_list_t *list);
void	open_pipe(pipe_list_t *pipe_list);
char	*transform_token(shell_t *shell, token_list_t *token);
bool	transform_tokens_to_argv(shell_t *shell, pipe_list_t *pipe);
void	close_pipe(pipe_list_t *pipe_list);
bool	is_builtin(char **argv);
int	exec_builtin(shell_t *shell, pipe_list_t *pipe);
bool	pipe_redir_fd(pipe_list_t *pipe);
bool	redir_fd(pipe_list_t *pipe);
bool	double_left_redir(pipe_list_t *pipe);
pid_t	exec_command(shell_t *shell, pipe_list_t *pipe, pid_t pgid);
int	wait_pipe(pipe_list_t *pipe, pid_t pgid, shell_t *shell);

/*
**	EXEC/TRANSFORM_TOKEN
*/

char	**get_alias(char **argv, alias_t *alias);
char	**get_glob(char **argv, token_list_t *token);
char	*get_last_return(char *str, shell_t *shell);
char	*get_tilde(char *token);
char	*get_var(char *str, shell_t *shell);

/*
**	BUILTIN
*/

int	my_alias(shell_t *shell, int argc, char **argv);
int	my_builtins(shell_t *shell, int argc, char **argv);
int	my_cd(shell_t *shell, int argc, char **argv);
int	my_echo(shell_t *shell, int argc, char **argv);
int	my_env(shell_t *shell, int argc, char **argv);
int	my_exit(shell_t *shell, int argc, char **argv);
int	my_getenv(shell_t *shell, int argc, char **argv);
int	my_kill(shell_t *shell, int argc, char **argv);
int	my_setenv(shell_t *shell, int argc, char **argv);
int	my_unsetenv(shell_t *shell, int argc, char **argv);
int	my_where(shell_t *shell, int argc, char **argv);
int	my_which(shell_t *shell, int argc, char **argv);
int	my_whoami(shell_t *shell, int argc, char **argv);

/*
**	ENV
*/

char	**copy_env(char **env);
ssize_t get_id_env(char **env, char *name);
char	*shell_getenv(char **env, char *name);

extern delim_tab_t	delim_tab[];
extern builtin_t	builtin_tab[];
extern char		*signal_list[];
