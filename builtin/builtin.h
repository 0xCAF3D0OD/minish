/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdi-noce <kdi-noce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 13:40:09 by kdi-noce          #+#    #+#             */
/*   Updated: 2022/06/26 19:33:55 by kdi-noce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stddef.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../srcs/libft/libft.h"
# include "../srcs/printf/ft_printf.h"

typedef struct	s_types
{
	int		quote;
	int 	len;
	int		s1_h;
	int		s2_h;
	int 	s1_l;
	int 	s2_l;
}			t_types;

typedef struct	s_args
{
	int		ac;
	char	**av;
	int		av_len;
}			t_args;

int		the_first_args(char *input);
void	ft_check(char *input, char **env, t_list *list);
t_list	*ft_unset(char *input, t_list **list);

/* EXPORT_BUILTIN */

t_list	*ft_export(char *input, t_list **list);
char	**order_list(t_list *list, char *input);
char	**search_args(char *input, t_list **list, int i);

/* EXPORT_ANNEX_QUOTS */

void	manage_quotation(char **str);
int		height_str(char **str);
char	**return_equal(char **str, int h);
void	add_quotation(char **temp, int h);
void	concat_the_string(char **str, char **temp, int h);

/* ANNEX_FCT */

void	free_them_all(char **str, int h);
void	print_str(char *note1, char *str, char c, int i, char *note2);
char	*realloc_str(char *s1, int len);
char	*fulling_str(char *str, char *temp, int len);
void	print_tab(char **str);

/* BUBBLE_SORTE */

void	bubble_sort(char **array);
int		ft_check_order(char **array);
void	ft_swap(char **array, int idx);
int		ft_boucle(char *input, char c, int i);
int		ft_str_search(char *str, int i, int count);

/* EXPORT_ANNEX_QUOTS_UTILS	*/

void	initializing_variables(t_types *var);
char	*manage_b_and_end_quotation(char *s1, char *s2, int len);
void	print_list(char **str, t_list **list);

/*	BUILTINS_FCT	*/

void	ft_env(t_list *list);
void 	ft_exit(void);
void	ft_pwd(char **env);
void 	ft_echo_n(char *input, int i);
void 	ft_echo(char *input);
t_list	*ft_unset(char *input, t_list **list);

/*	BUILTINS_UTILS	*/

int		check_list(char **str, t_list *list);
void	stock_args_in_list(char **str, t_list **list);
int		check_alpha(char *s1, char *s2);
int		check_if_similar(char **str, int count);
int		check_first_ltr(char *str, int len_str);

#endif