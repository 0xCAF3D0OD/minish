/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 12:26:35 by hsabir            #+#    #+#             */
/*   Updated: 2022/01/02 11:55:05 by 1mthe0wl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

/*
 * copy new into the 2d array
 */

int	copy_args(char **args, char **tmp, char *new)
{
	int	i;

	i = 0;
	while (args[i] != NULL)
	{
		tmp[i] = ft_strdup(args[i]);
		if (!tmp[i])
		{
			double_free(tmp);
			return (0);
		}
		i++;
	}
	tmp[i] = ft_strdup(new);
	if (!tmp[i])
	{
		double_free(tmp);
		return (0);
	}
	return (1);
}

/*
 * append new into a 2d array
 */

char	**append_args(char **args, char *new)
{
	int		i;
	char	**tmp;

	if (!new)
		return (args);
	if (new[0] == '\0')
	{
		free(new);
		return (args);
	}
	i = 0;
	while (args[i] != NULL)
		i++;
	tmp = malloc(sizeof(char *) * (i + 2));
	if (!copy_args(args, tmp, new))
		return (NULL);
	tmp[i + 1] = NULL;
	double_free(args);
	free(new);
	return (tmp);
}

/*
 * Check if there is other separators after,
 * or any other quotes.
 */

int	args_loop(t_vars *vars, int *i)
{
	int	len;
	int	ret;

	ret = 0;
	len = ft_strlen(vars->str);
	while (*i < len)
	{
		if (vars->str[*i] == ' ')
			break ;
		if (is_sep(vars->str[*i]) && get_type(vars->env, *i) != ENVS)
			break ;
		else if (ft_strncmp(&vars->str[*i], "\'", 1) == 0)
		{
			ret = get_c_index((&vars->str[*i] + 1), '\'');
			*i += ret + 1;
		}
		else if (ft_strncmp(&vars->str[*i], "\"", 1) == 0)
		{
			ret = get_c_index((&vars->str[*i] + 1), '\"');
			*i += ret + 1;
		}
		if (ret == -1)
			return (-1);
		*i += 1;
	}
	return (0);
}

int	check_empty(t_vars *vars)
{
	if (!vars->cmd->token[0] && vars->quotes->start != -1)
	{
		printf("minishell: %s: command not found\n", vars->cmd->token[0]);
		return (-1);
	}
	return (0);
}

int	args_to_word(t_vars *vars, t_cmd *current, int i)
{
	int		j;
	char	*tmp;

	j = i + 1;
	if (args_loop(vars, &j) == -1)
		return (quotes_error());
	tmp = substr_quote(vars, i, j - 1);
	if (!tmp)
		free_vars(vars);
	current->token = append_args(current->token, tmp);
	//current->p_cmds = append_args(current->p_cmds, tmp);
	//free(tmp);
	if (!current->token)
		free_vars(vars);
	return (j - i);
}
