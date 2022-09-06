/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdi-noce <kdi-noce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 19:18:48 by kdi-noce          #+#    #+#             */
/*   Updated: 2022/06/26 19:34:13 by kdi-noce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

int	check_list(char **str, t_list *list)
{
	int h;
	int	len;
	char *s;

	while (list)
	{
		h = 1;
		len = ft_strlen((char *)list->content);
		s = (char *)ft_calloc(len, sizeof(char *));
		s = (char *)list->content;
		while (str[h])
		{
			if (check_alpha(str[h], s) == 0)
			{
				return (1);
				free(s);
				break ;
			}	
			h++;
		}
		list = list->next;
	}
	return (0);
}

void	stock_args_in_list(char **str, t_list **list)
{
	int	h;
	
	h = 1;
	printf("%d\n", check_list(str, *list));
	if (check_list(str, *list) == 0)
	{
		while (str[h])
		{
			ft_lstadd_back(list, ft_lstnew(str[h]));
			h++;
		}
	}
}

int	check_alpha(char *s1, char *s2)
{
	int	count;
	int	i;
	int	j;

	i = 0;
	count = 0;
	while (s2[count])
		count++;
	while (s1[i])
	{
		j = 0;
		while(s2[j])
		{
			if (s2[j] == s1[i])
			{
				count--;
				break ;
			}
			j++;
		}
		i++;
	}
	if (count != 0)
		return (1);
	else
		return (0);
}

int	check_if_similar(char **str, int count)
{
	char	*s;
	int		i;

	i = 1;
	s = NULL;
	s = (char *)ft_calloc(count, sizeof(char *));
	while (str[i] && str[i + 1] && count > 1)
	{
		s = str[i];
		if (check_alpha(s, str[i + 1]) != 0)
			i++;
		else
		{
			return (1);
			break ;
		}
	}
	free(s);
	return (0);
}

int	check_first_ltr(char *str, int len_str)
{
	int	i;
	int rank;

	i = 0;
	rank = 0;

	while (i < len_str)
	{
		rank += 127 - str[i];
		i++;
	}
	printf("%d\n", rank);
	return (rank);
}