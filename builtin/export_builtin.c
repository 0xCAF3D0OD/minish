/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdi-noce <kdi-noce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:32:12 by kdi-noce          #+#    #+#             */
/*   Updated: 2022/07/01 18:00:30 by kdi-noce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

char	**search_args(char *input, t_list **list, int i)
{
	char **str;
	int h;
	int l;
	int	count;

	h = 0;
	l = 0;
	i = 1;
	count = 0;
	count = ft_str_search(input, i, count);
	str = ft_split(input, ' ');
	h = height_str(str);
	if (check_if_similar(str, count) == 1)
		printf("\n");
	manage_quotation(str);
	if (the_first_args(input) == 1)
		stock_args_in_list(str, list);
	if (the_first_args(input) == 2)
		return (str);
	print_tab(str);
	return (NULL);
}

char	**order_list(t_list *list, char *input)
{
	char	**str;
	int		len_str;
	int		len_list;
	int		h;
	t_list	*nlst = list;

	len_str = 0;
	h = 0;
	str = NULL;
	len_list = ft_lstsize(list);
	str = ft_calloc(len_list + 1, sizeof(char *));
	while (list)
	{
		len_str = ft_strlen((char *)list->content);
		str[h] = ft_calloc(len_str + 1, sizeof(char));
		str[h] = (char *)list->content;
		list = list->next;
		h++;
	}
	if (the_first_args(input) == 0 || the_first_args(input) == 1)
		print_list(str, &nlst);
	if (the_first_args(input) == 2)
		return (str);
	return (NULL);
}

char	*ft_export_1(char **input, t_list **list)
{
	int		i;

	i = 0;
	while (input[i])
		i++;
	if (i == 6)
		order_list(*list, input);
	else
		search_args(input, list, i);
	return (NULL);
}