/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_fct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdi-noce <kdi-noce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 18:29:16 by kdi-noce          #+#    #+#             */
/*   Updated: 2022/06/29 17:42:27 by kdi-noce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

void	ft_env_from_kevin(char **input)
{
	int i;

	i = -1;
	while (input[++i])
		printf("env: %s\n", input[i]);
}
//
//void	ft_pwd(char **env)
//{
//
//	while (*env)
//	{
//		if (ft_strncmp("PWD", *env, 3) == 0)
//			printf("%s\n", *env + 4);
//		env++;
//	}
//}
//
void 	ft_echo_n(char **input, int i)
{
	while (input[++i])
		printf("%s", input[i]);
}

int		arg_counter(char **input)
{
	int i;

	i = 0;
	while (input[i])
		i++;
	return (i);
}

void 	ft_echo_from_kevin(char **input) {
	int i;
	int j;
	int count;

	i = -1;
	j = 0;
	count = arg_counter(input);
	while (input[++i])
	{
		if (count == 1)
		{
			printf("\n");
			break ;
		}
		if ((ft_strcmp("echo", input[i]) == 0) && count > 1)
			i++;
		if (ft_strcmp("-n", input[i]) == 0) {
			ft_echo_n(input, i++);
			break;
		}
		printf("%s ", input[i]);
		if (input[i + 1] == 0)
			printf("\n");
	}
}

void	ft_export_kevin(char **input)
{
	int i;

	i = 0;
	while (input[i])
		printf("%s", input[i++]);
}
//
//void 	ft_exit(void)
//{
//	exit(1);
//}
//
//t_list	*ft_unset(char *input, t_list **list)
//{
//	int		i;
//	int		x;
//	char 	**str;
//	char	**search;
//
//	i = 0;
//	while (input[i])
//		i++;
//	search = search_args(input, list, i);
//	str = order_list(*list, input);
//	i = 0;
//	x = 1;
//	if (!(str))
//		return (NULL);
//	// while (search[x])
//	// {
//	// 	printf("search[%d] = %s\n", x, search[x]);
//	// 	x++;
//	// }
//	while (search[x])
//		print_str("unset", search[x], 0, i, "end"), x++;
//	while (str[i])
//	{
//		while (search[x])
//		{
//			while (ft_strcmp(search[x], str[i]) != 0)
//			{
//				i++;
//				print_str("unset", str[i], 0, i, "end");
//			}
//			print_str("unset", str[i], 0, i, "end");
//			str[i] = NULL;
//			print_str("unset", str[i], 0, i, "end");
//			if (x > 1)
//				x++;
//			else
//				break ;
//		}
//	}
//
//	// while (str[i])
//	// 	printf("%s\n", str[i++]);
//	return (NULL);
//}