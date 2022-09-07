//
// Created by Kevin Di nocera on 9/7/22.
//
#include "minishell.h"

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

