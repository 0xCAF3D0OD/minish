//
// Created by Kevin Di nocera on 9/7/22.
//
#include "minishell.h"

int	count_line(t_env *env)
{
	int	i = 0;
	while (env)
	{
		env = env->next;
		i++;
	}
	return (i);
}

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
	char	*str;
	int		len;
	int		i;

	len = 0;
	i = 1;
	while (env)
	{
		str = ft_strdup(env->value);
 		len = ft_strlen(input[i]);
		if (ft_strncmp(input[i], env->value, len) == 0)
		{
			return (1);
			break ;
		}
		env = env->next;
	}
	free(str);
	return (0);
}

int	len_input(char **str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char *manage_comas(char *str, char *temp, int j)
{
	int count;
	int i;

	count = 1;
	i = -1;
	while (str[++i])
	{
		if (str[i] == '=' && count == 1)
		{
			temp[j] = str[i];
			j++; i++;
			temp[j] = '"';
			j++;
			count--;
		}
		temp[j] = str[i];
		j++;
	}
	temp[j] = '"';
	temp[j + 1] = 0;
	return (temp);
}

void	manage_args(char **input, t_env *env)
{
	int		i;
	int		j;
	char	**str;

	i = 1;
	j = 0;
	str = ft_calloc(sizeof (char *), len_input(input));
	while (input[i])
	{

		str[i] = ft_calloc(sizeof (char *), ft_strlen(input[i]) + 2);
		str[i] = manage_comas(input[i], str[i], j);
		if (check_simil(input, env) != 0 && input[i + 1])
			i++;
		else if (input[i + 1] == 0 && check_simil(input, env) != 0)
			break ;
		ft_lstadd_back_env(&env, ft_lstnew_env(ft_strdup(input[i])));
//		ft_lstadd_back_env(&env, ft_lstnew_env(ft_strdup(str[i])));
		i++;
	}
	i = -1;
	while (str[++i])
	{
		free(str[i]);
		str = NULL;
	}
}

void	print_export(t_env *env, int len_env, char **str)
{
	int	i;

	i = 0;
	len_env = ft_lstsize_env(env);
	str = ft_calloc(len_env + 1, sizeof (char *));
	while (env)
	{
		str[i] = ft_strdup(env->value);
		env = env->next;
		i++;
	}
	i = -1;
	bubble_sort(str);
	display_str(str);
	while (str[++i])
	{
		free(str[i]);
		str[i] = NULL;
	}
}

int	check_args(char **input)
{
	int	i;

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
//	t_env *export;
	int		len_env;
	char	**str;
	int		len;
	int		ret;

	str = NULL;
	len = len_args(input);
	len_env = 0;
	if (len == 0)
	{
		print_export(env, len_env, str);
		return;
	}
	ret = check_args(input);
	if (len > 0 && ret == 0)
		manage_args(input, env);
}

