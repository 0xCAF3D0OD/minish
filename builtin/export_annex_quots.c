/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_annex_quots.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdi-noce <kdi-noce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 18:59:21 by kdi-noce          #+#    #+#             */
/*   Updated: 2022/06/26 19:29:17 by kdi-noce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

void	concat_the_string(char **str, char **temp, int h)
{
	t_types var;

	initializing_variables(&var);
	while (++var.s1_h < h)
	{
		var.len = ft_strlen(str[var.s1_h]);
		str[var.s1_h] = realloc_str(str[var.s1_h], var.len);
		var.s1_l = -1;
		var.s2_l = 0;
		var.quote = 0;
		while (++var.s1_l < var.len + 2)
		{
			if (var.quote == 0)
			{				
				while (str[var.s1_h][var.s1_l] != '=' && var.s1_l < var.len + 1)
					var.s1_l++;
				var.quote = 1;
			}
			str[var.s1_h][var.s1_l] = temp[var.s2_h][var.s2_l];
			var.s2_l++;
		}
		var.s2_h++;
	}
	free_them_all(temp, h);
}

void	add_quotation(char **temp, int h)
{
	char	**str;
	int	i;
	int	l;
	int	j;

	i = 1;
	j = 0;
	printf("%d\n", h);
	str = ft_calloc(h, sizeof(char *));
	while (i < h)
	{
		l = ft_strlen(temp[i]);
		str[i] = ft_calloc(l + 3, sizeof(char *));
		temp[i] = manage_b_and_end_quotation(str[i], temp[i], l + 2);
		free(str);
		i++;
	}
}

char	**return_equal(char **str, int h)
{
	char	**temp;
	int		i;
	int		l;

	i = 1;
	l = 0;
	temp = ft_calloc(h, sizeof(char *));
	while (i < h)
	{
		l = ft_strlen(str[i]);
		temp[i]= ft_calloc(l + 3, sizeof(char *));
		temp[i] = ft_strchr(str[i], '=');
		i++;
	}
	return (temp);
}

int		height_str(char **str)
{	
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	manage_quotation(char **str)
{
	char **temp;
	int	l;
	int i;
	int h;

	l = 0;
	i = 0;
	h = height_str(str);
	temp = return_equal(str, h);
	add_quotation(temp, h);
	concat_the_string(str, temp, h);
}