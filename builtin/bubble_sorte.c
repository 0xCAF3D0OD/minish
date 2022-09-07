/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sorte.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdi-noce <kdi-noce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 15:26:02 by kdi-noce          #+#    #+#             */
/*   Updated: 2022/06/26 19:17:23 by kdi-noce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

int ft_str_search(char *str, int i, int count)
{
	while (i >= 0)
	{
		// printf("str[%d] = %c\n", i, str[i]);
		if (str[i] == '=')
			count++;
		i--;
	}
	return (count);
}

int	ft_boucle(char *input, char c, int i)
{	
	while (input[i] == c)
		i++;
	return (i);
}

void	ft_swap(char **array, int idx)
{
	char *temp;

	temp = array[idx];
	array[idx] = array[idx + 1];
	array[idx + 1] = temp;
}

int	ft_check_order(char **array)
{
	int	j;

	j = 0;
	while (array[j + 1])
	{
		if (array[j + 1][0] != 0 && array[j][0] > array[j + 1][0])
			return (0);
		j++;
	}
	return (1);
}

void	bubble_sort(char **array)
{
	int	i;

	while (ft_check_order(array) == 0)
	{
		i = 0;
		while (array[i])
		{
			// ft_display(array);
			if (array[i + 1] && array[i + 1][0] != '\0' && array[i][0] > array[i + 1][0])
				ft_swap(array, i);
			i++;
		}
	}
}