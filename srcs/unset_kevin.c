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
		return (0);
	return (1);
}

void	ft_unset_kevin(char **input, t_env *env)
{
	t_env	*tmp;
	int		rec;
	int		i;

	i = 1;
	rec = check_input(input);
	tmp = env;
	if (rec)
		printf("\n");
	else
	{
		while (input[i])
		{
			while(env)
			{
				if (env->next && ft_strcmp(env->next->value, input[i]) == 0)
				{
					tmp = env->next->next;
					free(env->next);
					env->next = tmp;
				}
				env = env->next;
			}
			i++;
		}
	}
}

