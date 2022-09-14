//
// Created by dino on 14.09.22.
//
#include "../incs/minishell.h"

int	check_input(char **input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		i++;
	}
	printf("input = %d\n", i);
	if (i > 1)
		return (1);
	return (0);
}

t_env	*del_node(t_env *env, char *input)
{
//	t_env *tmp;
	while (env)
	{
		if (ft_strcmp(env->next->value, input) == 0)
		{
			printf("%s\n", env->value);
			env = env->next->next;
			free(env->next);
		}
		env = env->next;
	}
}
void	ft_unset_kevin(char **input, t_env *env)
{
	int rec;
	int i;

	i = 0;
	rec = check_input(input);
	if (rec)
		printf("\n");
	else
	{
		while (input[i])
		{
			while(env)
			{
				if (ft_strcmp(input[i], env->value) == 0)
					env = del_node(env, input[i]);
				env = env->next;
			}
			i++;
		}
	}
}

