/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   annex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdi-noce <kdi-noce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 18:16:27 by kdi-noce          #+#    #+#             */
/*   Updated: 2022/06/26 19:34:05 by kdi-noce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

// int	check_first_ltr(char *str, int len_str)
// {
// 	int	i;
// 	int rank;

// 	i = 0;
// 	rank = 0;

// 	while (i < len_str)
// 	{
// 		rank += 127 - str[i];
// 		i++;
// 	}
// 	printf("%d\n", rank);
// 	return (rank);
// }

// void	ft_add_str(char *av)
// {
// 	int	i;

// 	i = 0;
// 	while (av[i])
// 	{
// 		printf("%c", av[i]);
// 		i++;
// 	}
// }

// void	stock_args(char *input, t_list **list, int i, int len)
// {
// 	char *str;
// 	int	h;
	
// 	h = i;
// 	i = 0;
// 	str = malloc(sizeof(char *) * len);
// 	printf("input = %s\n", input);
// 	while (i <= h)
// 		str[i] = input[i], i++;

// 	// str = *ft_split(input, ' ');
// 	printf("str = %s\n", str);
// }

// void	search_args(char *input, t_list **list)
// {
// 	static int	count;
// 	int	i;
// 	int len;

// 	i = 6;
// 	count = 0;
// 	while(input[i])
// 		i++;
// 	len = i;
// 	i = 6;
// 	i = ft_boucle(input, ' ', i);
// 	while (input[i])
// 	{
// 		if ((input[i + 1] == ' ' && input[i + 2] != ' ') || input[i + 1] == 0)
// 		{
// 			stock_args(input, list, i, len);
// 		}
// 		i++;
// 	}

// char	**define_str(int i, char *input)
// {
// 	char **str;
// 	int	h;
// 	int l;
// 	int count;

// 	h = 0;
// 	l = 0;
// 	count = 0;
// 	str = NULL;
// 	count = ft_str_search(input, i, count);
// 	printf("%d", h);
// 	while (h <= count)
// 	{
// 		printf("%d", h);
// 		str[h] = (char *) malloc(sizeof(char *) * (i + 1));
// 		h++;
// 	}
// 	return (str);
// }

// int	*check_alpha_args(char **str, int count)
// {
// 	int *tab;
// 	int	h;
// 	int	l;
// 	int	i;

// 	h = 0;
// 	l = 0;
// 	i = 0;
// 	printf("%d\n", count);
// 	tab = (int *)ft_calloc(count, sizeof(int));
// 	while (tab[i])
// 		printf("%d\n", i++);
// 	while(h <= count)
// 	{
// 		printf("%s\n", str[h]);
// 		if (str[h][0] >= 65 && str[h][0] <= 90)
// 		{
// 			i = str[h][0];
// 			tab[h] = ((i - 90) + 25) + 1;
// 		}
// 		h++;
// 	}
// 	return (tab);
// }

		// while (str[i][j] && i > 0)
		// {
		// 	while (str[i][j] != '=')
		// 		j++;
		// 	str[i][j] = temp[k][l];
		// 	print_str("str2", str[i], j, "in the while");
		// 	j++;
		// }