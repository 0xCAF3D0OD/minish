//
// Created by Kevin Di nocera on 9/7/22.
//
#include "minishell.h"

//
//char *put_comas(char *str)
//{
//	int count;
//	char *str2;
//	int i;
//	int j;
//	int len;
//
//	i = 0;
//	j = 0;
//	count = 1;
//	len = ft_strlen(str);
//	str2 = calloc (len + 2, sizeof (char *));
//	while (str[i])
//	{
//		if (str[i] == '=' && count == 1)
//		{
//			str2[j] = str[i];
//			j++; i++;
//			str2[j] = '"';
//			j++;
//			count--;
//		}
//		str2[j] = str[i];
//		i++;
//		j++;
//	}
//	str2[j] = '"';
//	str2[j + 1] = 0;
//	i = 0;
//	j = 0;
//	while (str2[j])
//	{
//		str[i] = str2[j];
//		i++;
//		j++;
//	}
//	free(str2);
//	return (str);
//}
//
//void	print_tab(char **str)
//{
//	int i;
//
//	i = -1;
//	while (str[++i])
//		printf("declare -x %s\n", str[i]);
//}
//
//t_env	*ft_str_env(t_env *env, char **str, char **input)
//{
//
//	int len;
//	int	i;
//	int j;
//
//	i = -1;
//	j = 1;
//	while (str[++i])
//	{
//		len = ft_strlen(str[i]);
//		if (ft_strncmp(str[i], input[j], len + 1) == 0)
//		{
//			ft_lstadd_back_env(&env, ft_lstnew_env(str[i]));
//			j++;
//		}
//	}
//	return (env);
//}

//t_env	*manage_args(char **input, t_env *env)
//{
//	char	**str;
//	t_env	*start;
//	int 	len_env;
//	int 	len_str;
//	int 	i;
//	int		j;
//
//	i = 0;
//	j = 1;
//	len_env = 0;
//	len_str = 0;
//	str = NULL;
//	start = env;
////	str = lst_cp(env, len_env, len_str, str);
//	bubble_sort(str);
//	while (str[i])
//		i++;
//	while (input[j])
//	{
//		len_str = ft_strlen(input[j]);
//		str[i] = ft_calloc(len_str + 1, sizeof (char *));
//		str[i] = input[j];
//		str[i] = put_comas(str[i]);
//		i++;
//		j++;
//	}
//	str[i] = 0;
//	env = ft_str_env(env, str, input);
//	env = start;
////	print_tab(str);
//	free(str);
//	return (env);
//}

void	display_env(t_env *env)
{
	while (env)
	{
		printf("env = %s\n", env->value);
		env = env->next;
	}
}

void	display_str(char **str)
{
	int i = -1;

	while (str[++i])
		printf("declare -x %s\n", str[i]);
}

int	len_args(char **input)
{
	int i;
	int count;

	i = -1;
	while (input[++i])
		count = i;
	return (count);
}

int	check_equal(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
		{
			return (0);
			break;
		}
		i++;
	}
	return (1);
}

int 	check_simil(char **input, t_env *env)
{
	int		len;
	int		i;

	len = 0;
	i = 1;
	while (env)
	{
		printf("%s	->	%s\n", env->value, input[i]);
		len = ft_strlen(input[i]);
		if (ft_strncmp(input[i], env->value, len) == 0)
		{
			printf("%s	->	%s\n", env->value, input[i]);
			return (1);
		}
		env = env->next;
	}
	return (0);
}

void	manage_args(char **input, t_env *env)
{
	int	i;
	int ret;

	i = 1;
	ret = 0;
	while (input[i])
	{
		if ((ret = check_simil(input, env)) != 0)
			printf("i++\n"), i++;
		ft_lstadd_back_env(&env, ft_lstnew_env(input[i]));
		i++;
	}
//	display_env(env);
}

char	**lst_cp(t_env *env, int len_env, int len_str, char **str)
{
	int i;

	i = 0;
	len_env = ft_lstsize_env(env);
	str = ft_calloc(len_env + 1, sizeof (char *));
	while (env)
	{
		len_str = ft_strlen((char *)env->value);
		str[i] = ft_calloc(len_str + 1, sizeof (char *));
		str[i] = (char *)env->value;
		env = env->next;
		i++;
	}
	return (str);
}

void	print_export(t_env *env)
{
	char **str = NULL;
	int len_env = 0;
	int len_str = 0;

	str = lst_cp(env, len_env, len_str, str);
	bubble_sort(str);
	display_str(str);
}

int	check_args(char **input)
{
	int i;

	i = 1;
	while (input[i])
	{
		if (check_equal(input[i]) != 0)
		{
			printf("export: '%s': not a valid identifier\n", input[i]);
			return (1);
		}
		i++;
	}
	return (0);
}

void	ft_export_kevin(char **input, t_env *env)
{
	int len;
	int ret;

	len = len_args(input);
	if (len == 0)
		print_export(env);
	ret = check_args(input);
	if (len > 0 && ret == 0)
		manage_args(input, env);
}

