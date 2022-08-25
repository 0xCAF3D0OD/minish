/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 19:21:59 by hsabir            #+#    #+#             */
/*   Updated: 2022/01/02 11:28:56 by 1mthe0wl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

void	sig_child(int sig)
{
	(void)sig;
}

void	child_handler(t_shell *shell)
{
	tcsetattr(0, TCSANOW, &shell->term);
	signal(SIGINT, &sig_child);
	signal(SIGQUIT, &sig_child);
}

/* ########################################## */

void	sig_parrent(int sig)
{
	if (sig == SIGINT)
	{
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
//		*g_env = 1;
	}
}

void	parrent_handler(void)
{
	struct termios terminos;

	tcgetattr(0, &terminos);
	terminos.c_lflag &= ~ECHOCTL;
	tcsetattr(0, TCSANOW, &terminos);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, &sig_parrent);
}

/* ################################################# */

int	last_pid(t_cmd *cmd)
{
	cmd = last_cmd(cmd);
	return (cmd->pid);
}

void	return_sig(int status, int *nl)
{
	*nl = 1;
	if (WTERMSIG(status) == SIGINT)
		l_ret = 130;
	if (WTERMSIG(status) == SIGQUIT)
	{
		ft_putstr_fd("Quit: 3\n", 2);
		l_ret = 131;
	}
}

void	wait_all_process(t_cmd *cmd)
{
	int	status;
	int	nl;

	nl = 0;
	waitpid(last_pid(cmd), &status, 0);
	if (WIFSIGNALED(status))
		return_sig(status, &nl);
	else
		l_ret = WEXITSTATUS(status);
	while (waitpid(cmd->pid, &status, 0) != -1)
	{
		if (WIFSIGNALED(status) && WTERMSIG(status) != SIGPIPE)
			nl = 1;
		cmd = cmd->next;
	}
	if (nl == 1)
		write(1, "\n", 1);
}
