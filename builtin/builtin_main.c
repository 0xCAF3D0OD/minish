/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdi-noce <kdi-noce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 17:36:05 by kdi-noce          #+#    #+#             */
/*   Updated: 2022/06/26 19:30:07 by kdi-noce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

void	ft_printexp(t_list *list)
{
	while (list)
	{
		printf("declare - x %s\n", (char *) list->content);
		list = list->next;
	}
}

void	ft_lstenv(char **env, t_list *list)
{
	int		args;

	args = 0;
	while (env[args])
	{
		ft_lstadd_back(&list, ft_lstnew(env[args]));
		args++;
	}
}

int	the_first_args(char *input)
{
	int	i;

	i = 0;
	while (input[i] != ' ' && input[i])
		i++;
	if (ft_strncmp("export", input, i) == 0)
		return (1);
	if (ft_strncmp("unset", input, i) == 0)
		return (2);
	if (ft_strncmp("echo", input, i) == 0)
		return (3);
	if (ft_strncmp("pwd", input, i) == 0)
		return (4);	
	if (ft_strncmp("exit", input, i) == 0)
		return (5);
	if (ft_strncmp("env", input, i) == 0)
		return (6);	
	return (0);
}

void ft_check(char	*input, char **env, t_list *list)
{
	(void) env;
	if (the_first_args(input) == 1)
		ft_export_1(input, &list);
	if (the_first_args(input) == 2)
		ft_unset(input, &list);
	if (the_first_args(input) == 3)
		ft_echo_2(input);
	if (the_first_args(input) == 4)
		ft_pwd(env);
	if (the_first_args(input) == 5)
		ft_exit();
	if (the_first_args(input) == 6)
		ft_env_2(list);
}

//int	main(int argc, char **argv, char **env)
//{
//	t_list	list;
//	char	*input;
//
//	(void)	argc;
//	(void)	argv;
//	ft_lstenv(env, &list);
//	while(1)
//	{
//		input = readline("minishell ˜ ");
//		ft_check(input, env, &list);
//	}
//	return (0);
//}
