/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 11:05:09 by hsabir            #+#    #+#             */
/*   Updated: 2022/01/01 16:22:54 by hsabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

void	init_vars(t_vars *vars, t_shell *shell)
{
	vars->cmd = shell->cmd;
	vars->str = shell->cmdline;
	vars->env_vars = shell->env;
	vars->quotes = init_quotes(-1, -1, NONE);
	vars->env = init_quotes(-1, -1, NONE);
	if (!vars->quotes || !vars->env)
	{
		free_envs(vars->env_vars);
		free_cmd(vars->cmd);
		free(vars->str);
		if (vars->quotes)
			free_quotes(vars->quotes);
		if (vars->env)
			free_quotes(vars->env);
	}
}

void	c_free_vars(t_vars *vars)
{
	if (vars->cmd)
		free_cmd(vars->cmd);
	if (vars->str)
		free(vars->str);
	if (vars->quotes)
		free_quotes(vars->quotes);
	if (vars->env)
		free_quotes(vars->env);
}

void	free_vars(t_vars *vars)
{
	if (vars->cmd)
		free_cmd(vars->cmd);
	if (vars->str)
		free(vars->str);
	if (vars->quotes)
		free_quotes(vars->quotes);
	if (vars->env_vars)
		free_envs(vars->env_vars);
	if (vars->env)
		free_quotes(vars->env);
}
