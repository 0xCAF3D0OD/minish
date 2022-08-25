/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 09:59:11 by hsabir            #+#    #+#             */
/*   Updated: 2022/01/01 14:43:14 by hsabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

t_type	get_type(t_quotes *quotes, int i)
{
	t_quotes	*tmp;

	tmp = quotes;
	while (tmp)
	{
		if (i >= tmp->start && i <= tmp->end)
			return (tmp->type);
		tmp = tmp->next;
	}
	return (NONE);
}

/* ####################################################################### */

int	ft_strhas(char *str, char *set)
{
	int	i;

	while (str && *str)
	{
		i = 0;
		while (set && set[i])
		{
			if (*str == set[i])
				return (1);
			i++;
		}
		str++;
	}
	return (0);
}

/*
 * Since we have defined the index of start and end of the quote
 * we finally set them to the quotes struct.
 */

void	set_quotes_data(t_vars * vars, t_quotes *quotes, t_quotes tmp)
{
	t_quotes	*swap;

	swap = quotes;
	if (quotes->start == -1)
	{
		quotes->start = tmp.start;
		quotes->end = tmp.end;
		quotes->type = tmp.type;
	}
	else
	{
		while (swap->next)
			swap = swap->next;
		swap->next = init_quotes(tmp.start, tmp.end, tmp.type);
		if (!swap->next)
		{
			free_vars(vars);
			perror("Error\n");
			exit(-1);
		}
	}
}

/*
 * Check what type of quotes comes first, then find its end,
 * things to be stocked:
 * 		Type : (Simple/Double)
 * 		start: the index where the quotes starts
 * 		end  : the index of of the second same type of quote
 */

void	parse_quotes(t_vars *vars, int len)
{
	int			i;
	t_quotes	tmp;

	i = 0;
	while(i < len)
	{
		if (ft_strncmp(&vars->str[i], "\'", 1) == 0)
		{
			tmp.start = i;
			tmp.end = get_c_index((vars->str + i + 1), '\'') + i + 1;
			tmp.type = SIMPLE;
			set_quotes_data(vars, vars->quotes, tmp);
			i += tmp.end - tmp.start;
		}
		else if (ft_strncmp(&vars->str[i], "\"", 1) == 0)
		{
			tmp.start = i;
			tmp.end = get_c_index((vars->str + i + 1), '\"') + i + 1;
			tmp.type = DOUBLE;
			set_quotes_data(vars, vars->quotes, tmp);
			i += tmp.end - tmp.start;
		}
		i++;
	}
}

/* ##################################################################### */

int	quotes_error()
{
	printf("minishell: syntax error unclosed quote\n");
	return (-1);
}

void	quote_error_exit(t_vars *vars)
{
	free_vars(vars);
	perror("Error\n");
	exit(EXIT_FAILURE);
}

/*
 * Assign the index of the last quote into j
 * check if after the quote there is something else that left
 * like |, <, or > in the args loop.
 * substr whatever is inside the quotes.
 * append the subed string into cmd->token.
 */

int	parse_simple_quote(t_vars *vars, t_cmd *current, int i)
{
	int		j;
	char	*tmp;

	j = get_c_index((vars->str + i + 1), '\'');
	if (j == -1)
		return (quotes_error());
	j += i + 2;
	if (args_loop(vars, &j) == -1)
		return (quotes_error());
	tmp = substr_quote(vars, i, j - 1);
	if (!tmp)
		quote_error_exit(vars);
	current->token = append_args(current->token, tmp);
	if (!current->token)
		quote_error_exit(vars);
	return (j - i - 1);
}

/*
 * Same thing as simple parsing
 */

int	parse_double_quote(t_vars *vars, t_cmd *current, int i)
{
	int		j;
	char	*tmp;

	j = get_c_index((vars->str + i + 1), '\"');
	if (j == -1)
		return (quotes_error());
	j += i + 2;
	if (args_loop(vars, &j) == -1)
		return (quotes_error());
	tmp = substr_quote(vars, i, j - 1);
	if (!tmp)
		free_vars(vars);
	current->token = append_args(current->token, tmp);
	if (!current->token)
		free_vars(vars);
	return (j - i - 1);
}
