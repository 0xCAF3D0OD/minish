/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 14:03:26 by hsabir            #+#    #+#             */
/*   Updated: 2021/12/30 17:26:27 by hsabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

void	print_error(char *str)
{
	printf("%s\n", str);
}

void	close_error(int fd)
{
	if (close(fd) == -1)
		perror("Close\n");
}

void	close_fds(t_cmd *cmd)
{
	while (cmd)
	{
		if (cmd->in != 0)
			close_error(cmd->in);
		if (cmd->out != 1)
			close_error(cmd->out);
		cmd = cmd->next;
	}
}
