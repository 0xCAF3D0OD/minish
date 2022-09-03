/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 1mthe0wl </var/spool/mail/evil>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 21:41:20 by 1mthe0wl          #+#    #+#             */
/*   Updated: 2022/01/02 15:11:17 by 1mthe0wl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

int	exec_pipe_cmd(t_shell *shell, char **env, int fd_in)
{
	char	**ptr;
	(void)env;

	child_handler(shell);
	shell->cmd->pid = fork();
	if (shell->cmd->pid == 0)
	{
		close_unused_fd(shell, fd_in);
		redirection_handler(shell);
		swap_fds(shell->cmd->in, shell->cmd->out);
		if (shell->error)
			exit(EXIT_FAILURE);
//		if (exec_built_in(shell, 1)) TODO: execute built-ins here
//			exit(l_status);
		shell->cmd->path = check_cmd(*shell->cmd->token, shell);
		//shell->ret = get_path_exec(shell);
		//printf("path : %s\n", shell->cmd->path);
		//if (shell->ret > 0)
		if (!shell->cmd->path)
		{
			free_cmd(shell->cmd);
			exit (EXIT_FAILURE);
		}
		//printf("Path : %s", shell->cmd->path);
		ptr = get_env_array(shell->env);
		//printf("ENV : %s\n", *ptr);
		execve(shell->cmd->path, shell->cmd->token, ptr);
		perror(*shell->cmd->token);
		exit(EXIT_FAILURE);
	}
	else if (shell->cmd->pid == -1)
		perror("pipe execution fork\n");
	return (0);
}

void	exec_path_cmd(char *path, t_shell *shell)
{
	int		status;
	pid_t	pid;
	pid_t	child_pid;

	status = 0;
	pid = fork();
	if (pid == 0)
	{
		execv(path, shell->cmd->token);
	}
	else if (pid > 0)
		child_pid = waitpid(pid, &status, 0);
}
