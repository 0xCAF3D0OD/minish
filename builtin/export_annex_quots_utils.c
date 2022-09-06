/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_annex_quots_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdi-noce <kdi-noce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 19:16:10 by kdi-noce          #+#    #+#             */
/*   Updated: 2022/06/26 19:29:26 by kdi-noce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

void	initializing_variables(t_types *var)
{
	var->s1_h = 0;
	var->s2_h = 1;
	var->s1_l = 0;
	var->s2_l = 0;
	var->len = 0;
}

char	*manage_b_and_end_quotation(char *s1, char *s2, int len)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	if (s2[0] == 0)
		return (NULL);
	s1[0] = s2[0];
	while (i < len)
	{
		if (i == 1)
		{
			s1[i] = '"';
			i++;
		}
		s1[i] = s2[j];
		if (i == len - 1)
			s1[i] = '"';
		i++;
		j++;
	}
	s1[i] = 0;
	return (s1);
}

void	print_list(char **str, t_list **list)
{
	int	h;

	h = 0;
	bubble_sort(str);
	if (*str && !*list)
		printf("1\n");
	while (str[h] && *list)
	{
		(*list)->content = str[h];
		printf("declare -x %s\n", (char *)(*list)->content);
		*list = (*list)->next;
		h++;
	}
}