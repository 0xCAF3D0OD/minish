/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 17:02:39 by hsabir            #+#    #+#             */
/*   Updated: 2021/12/31 14:28:52 by hsabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

void	swap_fds(int in, int out)
{
	if (in != 0)
		dup_and_close(in, 0);
	if (out != 1)
		dup_and_close(out, 1);
}

void	close_unused_fd(t_shell *shell, int fd)
{
	t_cmd	*ptr;

	ptr = shell->cmd->next;
	if (ptr)
		close_error(fd);
	while (ptr)
	{
		if (ptr->in != 0)
			close_error(ptr->in);
		if (ptr->out != 1)
			close_error(ptr->out);
		ptr = ptr->next;
	}
}
int	fd_set_in_out(t_shell *shell, int *fd, int first)
{
	if (!first)
	{
		if (shell->cmd->in != 0)
			close_error(fd[0]);
		else
			shell->cmd->in = fd[0];
	}
	if (pipe(fd) == -1)
	{
		perror("FD_Set pipe error\n");
		return (0);
	}
	if (shell->cmd->next)
		shell->cmd->out = fd[1];
	else
	{
		close_error(fd[0]);
		close_error(fd[1]);
	}
	return (1);
}

