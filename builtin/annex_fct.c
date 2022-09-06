/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   annex_fct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdi-noce <kdi-noce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 19:07:07 by kdi-noce          #+#    #+#             */
/*   Updated: 2022/06/26 19:34:08 by kdi-noce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

void	print_tab(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		printf("str[%d] = %s\n", i, str[i]);
		i++;
	}
}

void	free_them_all(char **str, int h)
{
	int	i;

	i = 0;
	while (i < h)
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
}

void	print_str(char *note1, char *str, char c, int i, char *note2)
{
	if (c == 0)
		printf("%d: %s[%s]	note -> '%s'\n", i, note1, str, note2);
	else if (c != 0)
		printf("%d: %s[%s]	'%c' note -> '%s'\n", i, note1, str, c, note2);
}

char	*fulling_str(char *str, char *temp, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		str[i] = temp[i];
		i++;
	}
	return (str);
}

char	*realloc_str(char *s1, int len)
{
	char	*s2;

	s2 = (char *)ft_calloc(len + 2, sizeof(char *));
	s2 = s1;
	s1 = (char *)ft_calloc(len + 2, sizeof(char *));
	s1 = fulling_str(s1, s2, len + 2);
	free(s2);
	return (s1);
}