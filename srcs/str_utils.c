/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 11:49:31 by hsabir            #+#    #+#             */
/*   Updated: 2022/01/02 11:19:27 by 1mthe0wl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

/*
 * Find the index of a character
 */

int	get_c_index(char *str, char c)
{
	int	i;
	int len;

	i = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

/*
 * Skip a space
 */

int	trim_spaces(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	return (i);
}

/*
 * Look for special separators,
 * 		60 = <
 * 		62 = >
 * 		124 = |
 */

int	is_sep(char c)
{
	if (c == 60 || c == 62 || c == 32 || c == 124)
		return (1);
	return (0);
}

/*
 * count the number of quotes
 */

int	quote_counter(t_vars *vars, int start, int end)
{
	t_quotes	*tmp;
	int			count;

	count = 0;
	while (start <= end)
	{
		tmp = vars->quotes;
		while (tmp)
		{
			if (start == tmp->start || start == tmp->end)
				count++;
			tmp = tmp->next;
		}
		start++;
	}
	return (count);
}

/*
 * Check if the index is quote
 */

int	is_quote(t_vars *vars, int i)
{
	t_quotes	*tmp;

	tmp = vars->quotes;
	while (tmp)
	{
		if (i == tmp->start || i == tmp->end)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

/*
 * check if the index is quote, otherwise
 * substr the string
 */

char	*substr_quote(t_vars *vars, int start, int end)
{
	int		cut;
	char	*tmp;
	int		i;

	cut = quote_counter(vars, start, end);
	tmp = malloc(sizeof(char) * (end - start - cut + 2));
//	tmp = malloc(sizeof(char) * (end - start + 2));
	if (!tmp)
		return (NULL);
	i = 0;
	while (start <= end)
	{
		if (is_quote(vars, start) == 1)
			start++;
		else
		{
			tmp[i] = vars->str[start];
			i++;
			start++;
		}
	}
	tmp[i] = '\0';
	return (tmp);
}
