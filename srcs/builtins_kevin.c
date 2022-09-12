/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_fct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdi-noce <kdi-noce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 18:29:16 by kdi-noce          #+#    #+#             */
/*   Updated: 2022/06/29 17:42:27 by kdi-noce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

void	ft_env_from_kevin(char **input)
{
	int i;

	i = -1;
	while (input[++i])
		printf("env: %s\n", input[i]);
}

int	ft_pwd_kevin(void)
{
	printf("%s\n", getcwd(NULL, 100));
	return (1);
}

void 	ft_echo_n(char **input, int i)
{
	while (input[++i])
		printf("%s", input[i]);
}

int		arg_counter(char **input)
{
	int i;

	i = 0;
	while (input[i])
		i++;
	return (i);
}

void 	ft_echo_from_kevin(char **input) {
	int i;
	int j;
	int count;

	i = -1;
	j = 0;
	count = arg_counter(input);
	while (input[++i])
	{
		if (count == 1)
		{
			printf("\n");
			break ;
		}
		if ((ft_strcmp("echo", input[i]) == 0) && count > 1)
			i++;
		if (ft_strcmp("-n", input[i]) == 0)
		{
			ft_echo_n(input, i++);
			break;
		}
		printf("%s ", input[i]);
		if (input[i + 1] == 0)
			printf("\n");
	}
}

void	env_add_back(t_env **lst, t_env *new)
{
	t_env	*ptr;

	if (!lst)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		ptr = ft_lstlast_env(*lst);
		ptr->next = new;
	}
}

t_env	*new_env(char	*name, char *value)
{
	t_env	*env;

	env = malloc(sizeof(t_env));
	env->name = name;
	env->value = value;
	env->next = NULL;
	return (env);
}

void	updatepwd(t_shell *shell, char *pwd)
{
	t_env	*tmp;

	tmp = shell->env;
	while (tmp)
	{
		if (!ft_strcmp(tmp->name, "PWD"))
			getcwd(tmp->value, 100);
		else if (!ft_strcmp(tmp->name, "OLDPWD"))
		{
			tmp->value = pwd;
			pwd = NULL;
		}
		tmp = tmp->next;
	}
	if (pwd)
	{
		tmp = new_env("OLDPWD", pwd);
		env_add_back(&shell->env, tmp);
	}
	free(pwd);
}

int	ft_cd_kevin(char **cmd, t_shell *shell)
{
	static char	*pwd;

	if (!pwd)
		pwd = malloc(sizeof(char) * 100);
	getcwd(pwd, 100);
	if (cmd[0] == NULL)
		cmd[0] = ft_strdup(getenv("HOME"));
//	if (chdir(cmd[0]) != 0)
//	{
//		printf("cd: no such file or directory: %s\n", cmd[0]);
//		return (0);
//	}
	updatepwd(shell, pwd);
	return (1);
}