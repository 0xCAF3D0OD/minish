/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:35:03 by hsabir            #+#    #+#             */
/*   Updated: 2022/01/02 15:04:58 by 1mthe0wl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <string.h>
# include <stdlib.h>
# include <sys/wait.h>
# include "libft.h"
# include <signal.h>
# include <termios.h>
# include <fcntl.h>
# include <sys/stat.h>

extern int l_ret;
//extern char	**g_env;
typedef struct s_quotes	t_quotes;
typedef struct s_cmd	t_cmd;
typedef struct s_env	t_env;
typedef enum	s_builtin_cmd
{
	N_B_IN,
	ECHO_M,
	CD_M,
	PWD_M,
	EXPORT_M,
	UNSET_M,
	ENV_M,
}	t_builtin_cmd;

typedef enum	s_red_type
{
	HEREDOC,
	REDIRECT_IN,
	REDIRECT_OUT,
	REDIRECT_D_OUT,
}	t_red_type;

typedef enum	s_type
{
	SIMPLE,
	DOUBLE,
	NONE,
	ENVS
}	t_type;

typedef struct	s_env
{
	char	*name;
	char	*value;
	t_env	*next;
}	t_env;

typedef struct	s_quotes
{
	int	start;
	int	end;
	t_type	type;
	t_quotes	*next;
}	t_quotes;

typedef struct	s_vars
{
	t_cmd		*cmd;
	t_quotes	*quotes;
	t_quotes	*env;
	t_env		*env_vars;
	char		*str;
	int			*last_ret;
}	t_vars;

typedef struct	s_cmd
{
	char	**token;
	char	**redirection;
	char	*path;
	int		pid;
	int		in;
	int		out;
	t_cmd	*next;
}	t_cmd;

typedef struct	s_shell
{
	t_cmd	*cmd;
	char	*cmdline;
	char	**tokens;
//	int		ret;
	int		std_in;
	int		std_out;
	int		error;
	t_env	*env;
	int		n_pipes;
	__attribute__((unused)) int		pipe_flag;
	__attribute__((unused)) int		pipe_cmd_exist;
	__attribute__((unused)) char	*cmds;
	__attribute__((unused)) char	**cmds_pipe[1024];
	char	*prompt;
	char	**ev;
//	char	**exp;
	struct termios term;
}	t_shell;

int	check_path_env(t_env **env, char *name);
int	get_path_exec(t_shell *shell);
t_env	*get_envs(char **m_env);
char	**get_env_array(t_env *env);
t_type	get_type(t_quotes *quotes, int i);
void	free_envs(t_env *env);
void	parrent_handler(void);
t_cmd	*last_cmd(t_cmd *cmd);
void	wait_all_process(t_cmd *cmd);
void	child_handler(t_shell *shell);
int exec_built_in(t_shell *shell, int in_fork);
char	*check_cmd(char *cmd, t_shell *shell);
void	free_all(t_shell *shell, int exit_p, char *str);
void	swap_fds(int in, int out);
void	dup_and_close(int fd_in, int fd_out);
int	is_builtin(char *arg);
void	redirection_handler(t_shell *shell);
void	close_unused_fd(t_shell *shell, int fd);
int	ft_strcmp(char *s1, char *s2);
void	close_error(int fd);
void	close_fds(t_cmd *cmd);
int	fd_set_in_out(t_shell *shell, int *fd, int first);
int	parse_heredoc(char *delim, t_shell *shell, t_cmd *ptr);
int	redirection_type(char *redirection);
int	redirection(t_vars *vars, t_cmd *current, int i);
int	tokenizing(t_shell *shell);
int	pipe_counter(char *str, char c);
void	blocksig(int sig, void *ptr);
//parsing
void	parsing(t_shell *shell, char **env);
int fork_pipes (int n, char ***argv, char **env, t_shell *shell);
//int	fork_pipes(int n, char *argv, char **env);
//prompt
void	init_prompt(t_shell *shell);

//exec
void	exec_path_cmd(char *path, t_shell *shell);
int		exec_pipe_cmd(t_shell *shell, char **env, int fd_in);

//piping
__attribute__((unused)) void	get_pipes(t_shell *shell);
int	pipe_handler(t_vars *vars, int i, int len, t_cmd **tmp);
//builtin
int	ft_env(t_shell *shell);
int	ft_echo(char **cmd);
int     ft_cd(char **cmd, t_shell *shell);
int	ft_export(char **cmd, t_shell *shell);
//builtin from Kevin
void 	ft_echo_from_kevin(char **input);
void	ft_env_from_kevin(char **input);
void	ft_export_kevin(char **input, t_env *env);
//ft_lst_kevin
t_env	*ft_lstnew_env(void	*content);
t_env	*ft_lstlast_env(t_env *lst);
void	ft_lstadd_back_env(t_env **alst, t_env *new);
int		ft_lstsize_env(t_env *lst);
//export_kevin

//annexe_kevin
void	bubble_sort(char **array);
//Init ascii
void	init_ascii(void);
//Free
void	free_struct(t_shell *shell);
int		double_free(char **array);
//Error
void	print_error(char *str);

//char	**g_env;

//quotes/
int	parse_simple_quote(t_vars *vars, t_cmd *current, int i);
int	parse_double_quote(t_vars *vars, t_cmd *current, int i);
int	ft_strhas(char *str, char *set);
void	set_quotes_data(t_vars *vars, t_quotes *quotes, t_quotes tmp);
void	parse_quotes(t_vars *vars, int len);
int	quotes_error();

//str_utils
int		get_c_index(char *str, char c);
int		trim_spaces(char *str);
int		is_sep(char c);
int		quote_counter(t_vars *vars, int start, int end);
int		quote_is_data(t_vars *vars, int i);
char	*substr_quote(t_vars *vars, int start, int end);

//cmd_utils
char	**init_cmd_token(void);
t_cmd	*init_cmd(void);
void	free_cmd(t_cmd *cmd);

//quotes_utils
t_quotes	*init_quotes(int start, int end, t_type type);
void		free_quotes(t_quotes *quotes);

//vars_utils
void	init_vars(t_vars *vars, t_shell *shell);
void	c_free_vars(t_vars *vars);
void	free_vars(t_vars *vars);

//args_utils
int	args_loop(t_vars *vars, int *i);
char	**append_args(char **args, char *new);
int	check_empty(t_vars *vars);
int	args_to_word(t_vars *vars, t_cmd *current, int i);
#endif
