/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 10:26:23 by hsabir            #+#    #+#             */
/*   Updated: 2021/12/31 19:55:51 by hsabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

t_cmd	*last_cmd(t_cmd *cmd)
{
	if (!cmd)
		return (NULL);
	while (cmd->next)
		cmd = cmd->next;
	return (cmd);
}

char	**init_cmd_token(void)
{
	char	**tmp;

	tmp = malloc(sizeof(char *));
	if (!tmp)
		return (NULL);
	tmp[0] = NULL;
	return (tmp);
}

t_cmd	*init_cmd(void)
{
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd->token = init_cmd_token();
	cmd->redirection = init_cmd_token();
	if (!cmd->token || !cmd->redirection)
		return  (NULL);
	cmd->next = NULL;
	cmd->path = NULL;
	cmd->in = 0;
	cmd->out = 1;
	return (cmd);
}

void	free_cmd(t_cmd *cmd)
{
	t_cmd	*tmp;

	while (cmd != NULL)
	{
		if (cmd->token)
			double_free(cmd->token);
		tmp = cmd->next;
		free(cmd);
		cmd = NULL;
		cmd = tmp;
	}
}
