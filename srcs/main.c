/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:28:25 by hsabir            #+#    #+#             */
/*   Updated: 2022/01/02 15:04:48 by 1mthe0wl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

int	l_ret = 0;

void check_leaks();

void	init_line(t_shell *shell)
{
	if (!shell->cmdline)
		init_prompt(shell);
	signal(SIGQUIT, SIG_IGN);
	rl_replace_line("",0);
	shell->cmdline = readline("minish> ");
	if (!shell->cmdline)
	{
		if (shell->cmdline != NULL)
			free_struct(shell);
		rl_clear_history();
		exit (EXIT_SUCCESS);
	}
	while (!(ft_strlen(shell->cmdline)))
	{
		free(shell->cmdline);
		init_line(shell);
	} 
}

void	init_shell(t_shell *shell, char **env)
{
	shell->cmdline = NULL;
	shell->env = get_envs(env);
	shell->cmd = NULL;
	shell->std_in = 0;
	shell->std_out = 0;
	tcgetattr(0, &shell->term);
}

void	exit_fct(t_shell *shell)
{
	if (shell->cmdline && !(ft_strncmp(shell->cmdline, "exit", 4)))
	{
		if (ft_strlen(shell->cmdline) != 4)
		{
			rl_clear_history();
			printf("exit\n");
			perror("minish");
			exit (l_ret);
		}
		if (ft_strlen(shell->cmdline) == 4)
		{
			//free_struct(&shell);
			rl_clear_history();
			printf("exit\n");
			exit (l_ret);
		}
	}
}

int	main(int argc, char **argv, char **env)
{
	t_shell	shell;
	(void)argc;
	(void)argv;

//	init_ascii();
	init_shell(&shell, env);
	while (1)
	{
		parrent_handler();
		init_line(&shell);
		exit_fct(&shell);
		if (shell.cmdline)
		{
			add_history(shell.cmdline);
			if (tokenizing(&shell) == -1)
				continue ;
			if (*shell.cmd->token || *shell.cmd->redirection)
			{
				parsing(&shell, env);
			}
		}
//		free(shell.cmdline);
	}
	free_struct(&shell);
	check_leaks();
	return (0);
}
