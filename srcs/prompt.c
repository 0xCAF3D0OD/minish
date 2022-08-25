/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 1mthe0wl </var/spool/mail/evil>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 15:13:59 by 1mthe0wl          #+#    #+#             */
/*   Updated: 2021/12/19 15:45:31 by lgyger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

char	*get_path(char *path)
{
	int		size;
	char	*ptr;

	size = 1024;
	path = (char *)malloc((size_t)size);
	if (path)
		ptr = getcwd(path, (size_t)size);
	else
		exit (EXIT_FAILURE);
	return (ptr);
}

void	init_prompt(t_shell *shell)
{
	char	*user;
	char	*path = NULL;
	//char	*prompt;
	//t_shell	*shell;

	user = getenv("USER");
	if (!user)
		exit (EXIT_FAILURE);
	path = get_path(path);
	shell->prompt = ft_calloc(sizeof(char), 1024);
	//shell->prompt = (char *)malloc(1024);
	ft_strlcat(shell->prompt, "[", ft_strlen(shell->prompt) + 2);
	ft_strlcat(shell->prompt, user, ft_strlen(shell->prompt) + ft_strlen(user) + 1);
	ft_strlcat(shell->prompt, "@", ft_strlen(shell->prompt) + 2);
	ft_strlcat(shell->prompt, path, ft_strlen(shell->prompt) + ft_strlen(path)+ 1);
	ft_strlcat(shell->prompt, "] ~ ", ft_strlen(shell->prompt) + 5);
	free (path);
	//free(user);
	//return (shell->prompt);
	//printf("%s\n", prompt);
}
