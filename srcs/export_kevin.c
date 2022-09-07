//
// Created by Kevin Di nocera on 9/7/22.
//
#include "minishell.h"
//char	**search_args(char *input, t_list **list, int i)
//{
//	char **str;
//	int h;
//	int l;
//	int	count;
//
//	h = 0;
//	l = 0;
//	i = 1;
//	count = 0;
//	count = ft_str_search(input, i, count);
//	str = ft_split(input, ' ');
//	h = height_str(str);
//	if (check_if_similar(str, count) == 1)
//		printf("\n");
//	manage_quotation(str);
//	if (the_first_args(input) == 1)
//		stock_args_in_list(str, list);
//	if (the_first_args(input) == 2)
//		return (str);
//	print_tab(str);
//	return (NULL);
//}
//
//char	**order_list(t_list *list, char *input)
//{
//	char	**str;
//	int		len_str;
//	int		len_list;
//	int		h;
//	t_list	*nlst = list;
//
//	len_str = 0;
//	h = 0;
//	str = NULL;
//	len_list = ft_lstsize(list);
//	str = ft_calloc(len_list + 1, sizeof(char *));
//	while (list)
//	{
//		len_str = ft_strlen((char *)list->content);
//		str[h] = ft_calloc(len_str + 1, sizeof(char));
//		str[h] = (char *)list->content;
//		list = list->next;
//		h++;
//	}
//	if (the_first_args(input) == 0 || the_first_args(input) == 1)
//		print_list(str, &nlst);
//	if (the_first_args(input) == 2)
//		return (str);
//	return (NULL);
//}

//int	len_args(char **input, t_env *env)
//{
//	int	i;
//
//	i = 0;
//	while (input[i])
//		i++;
//	if (i == 1)
//		return (1);
//	return (0);
//}
void	order_str(char **str)
{
	int i;

	i = -1;
	bubble_sort(str);
	while (str[++i])
		printf("declare -x %s\n", str[i]);
}

void	print_export(t_env *env)
{
	char	**str;
	int 	len_env;
	int 	len_str;
	int 	i;

	i = 0;
	len_env = ft_lstsize((t_list *)env);
	str = ft_calloc(len_env + 1, sizeof (char *));
	while (env)
	{
		len_str = ft_strlen((char *)env->value);
		str[i] = ft_calloc(len_str + 1, sizeof (char *));
		str[i] = (char *)env->value;
		env = env->next;
		i++;
	}
	order_str(str);
}

int	len_args(char **input)

void	ft_export_kevin(char **input, t_env *env)
{
	int	i;
	int len;

	i = 0;
	len = len_args(input, env);
	print_export(env);
//	while (env)
//	{
//		printf("%s\n", env->value);
//		env = env->next;
//	}
//	while (input[i])
//	{
//		printf("input = %s\n", input[i]);
//		i++;
//	}
//	if (i == 6)
//		order_list(*list, input);
//	else
//		search_args(input, list, i);
//
//	return (NULL);
}