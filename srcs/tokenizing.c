/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 1mthe0wl </var/spool/mail/evil>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 22:55:45 by 1mthe0wl          #+#    #+#             */
/*   Updated: 2022/01/02 11:27:56 by 1mthe0wl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

char	*ft_trim(char *str)
{
	char *ret;

	ret = ft_strtrim(str, " ");
	free(str);
	return (ret);
}


int pipe_counter(char *str, char c)
{
	unsigned int ret;
	size_t i;
	
	i = 0;
	ret = 0;
	while (str[i])
	{
		if (str[i] == c)
			ret++;
		i++;
	}
	return (ret);
}

/*
 * check for the pipes 
 */

void	tokenizing_pipe(t_shell *shell)
{
	int	i;
	int	check_len;

	i = 0;
	check_len = ft_strlen(shell->cmdline);
	//if (check_len <= shell->n_pipes)
	//	printf("minishell: syntax error near unexpected token `%s'\n", shell->cmdline);
	if (shell->n_pipes < check_len)
	{
		shell->tokens = ft_split(shell->cmdline, '|');
		shell->pipe_flag = 1;
		while (i <= shell->n_pipes)
		{
			shell->tokens[i] = ft_trim(shell->tokens[i]);
			if ((ft_strhas(shell->tokens[i], "\'\"")))
				printf("test : %s\n", shell->tokens[i]);
			shell->cmds_pipe[i] = ft_split(shell->tokens[i], ' ');
			//if ((ft_strhas(shell->cmds_pipe[i][1], "\'")))
			//	printf("test : %s\n", shell->cmds_pipe[i][1]);
			i++;
		}
	}
	else
		shell->pipe_flag = 0;
}

/*
 * Check for the the quote type, then parse them.
 */

int	parse_quotes_args(t_vars *vars, int *i, t_cmd *tmp)
{
	int	ret;

	ret = 0;
	if (ft_strncmp(&vars->str[*i], "\'", 1) == 0
			&& get_type(vars->env, *i) != ENVS)
		ret = parse_simple_quote(vars, tmp, *i) + 1;
	else if (ft_strncmp(&vars->str[*i], "\"", 1) == 0
			&& get_type(vars->env, *i) != ENVS)
		ret = parse_double_quote(vars, tmp, *i) + 1;
	else if ((vars->str[*i] == '<' || vars->str[*i] == '>')
			&& get_type(vars->env, *i) != ENVS)
		ret = redirection(vars, tmp, *i);
	*i += ret;
	if (ret == -1 || ret == -254 || ret == -255)
		return (-1);
	return (ret);
}

int	parse_pipes(t_vars *vars, int *i, t_cmd **tmp, int len)
{
	int	ret;

	ret = 0;
	if (ft_strncmp(&vars->str[*i], "|", 1) == 0
			&& get_type(vars->env, *i) != ENVS)
	{
		//printf("str[%c]\n", vars->str[i]);
		if (pipe_handler(vars, *i, len, tmp) == -1)
			return (-1);
		*i += 1;
	}
	else if (vars->str[*i] != ' ')
	{
		ret = args_to_word(vars, *tmp, *i);
		if (ret == -1)
			return (-1);
		*i += ret;
	}
	return (0);
}

/*
 * Check if a pipe exist before or after the quotes,
 * skip the spaces if found,
 */

int	parse_loop(t_vars *vars, int len)
{
	t_cmd	*tmp;
	int		i;
	int		ret;

	tmp = vars->cmd;
	i = 0;
	while (i < len)
	{
		//printf("vars_str before strim : %s\n", &vars->str[i]);
		i += trim_spaces(&vars->str[i]);
		ret = parse_quotes_args(vars, &i, tmp);
		if (ret == -1)
			return (-1);
		else if (ret != 0)
			continue ;
		if (parse_pipes(vars, &i, &tmp, len) == -1)
			return (-1);
	}
	return (0);
}

/*
 * The base of the program here we decide how to handle what
 * the users write. It could be monkey typing so we have to be careful
 * whar we are reciving and how tto manage them.
 * -------------------------------------------
 * The first approach was to handle the pipes at first
 * but we soon realizes that we should have took care of quotes :)
 * ---------------------------------------------------
 * Check if any type 'single', or "double" exist, if yes,
 * so find out its indexes of start and end and its type.
 */

/*int	check_empty(t_vars *vars)
{
	if (!vars->cmd->token[0] && !vars->cmd->redirection[0]
			&& vars->quotes->start != -1)
	{
		printf("minish: %s: command not found\n", *vars->cmd->token);
		g_ptr = 127;
		return (-1);
	}
	else if (!vars->cmd->token[0] && !vars->cmd->redirection[0]
			&& vars->env->start != -1)
	{
		g_ptr = 0;
		return (-1);
	}
	return (0);
}*/

int	tokenizing(t_shell *shell)
{
	t_vars	vars;
	int		len;

	shell->cmd = init_cmd();
	if (!shell->cmd)
	{
		free_envs(shell->env);
		perror("Close");
	}
	init_vars(&vars, shell);
	len = ft_strlen(vars.str);
	parse_quotes(&vars, len);
	len = ft_strlen(vars.str);
	if (parse_loop(&vars, len) == -1)
	{
		//check_empty(&vars) == -1
		c_free_vars(&vars);
		shell->cmd = NULL;
		return (-1);
	}
	free(vars.str);
	free_quotes(vars.quotes);
	free_quotes(vars.env);
	return (0);
}
