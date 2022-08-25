#include <stdio.h>
#include "../incs/minishell.h"

int	ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

char	**sort(char **ev,int n_array)
{
	int i;
	int j;
	char *temp;
	
	i = 0;
	while (i < n_array)
	{
		j = 0;
    		while(j < n_array-1-i)
		{
      			if(ft_strcmp(ev[j], ev[j+1]) > 0)
			{
				temp = ft_strdup(ev[j]);
        			ev[j] = ft_strdup(ev[j+1]);
        			ev[j+1] = ft_strdup(temp);
			}
			j++;
		}
		i++;
	}
	return (ev);
}

int	ft_export(char **cmd, t_shell *shell)
{
	unsigned int i;

	i = 0;
	while(shell->ev[i])
		i++;
	if (cmd[1] == NULL)
	{
//		g_env = sort(shell->ev,i);
		i = 0;
//		while(g_env[i])
		{
//			printf("declare -x %s\n",g_env[i]);
			i++;
		}
	}
	return (1);
}
