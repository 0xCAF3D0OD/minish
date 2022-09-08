//
// Created by dino on 08.09.22.
//
#include "minishell.h"

t_env	*ft_lstnew_env(void	*content)
{
	t_env	*r;

	r = (t_env *)malloc(sizeof(t_env));
	if (!r)
		return (NULL);
	r->value = content;
	r->next = 0;
	return (r);
}

t_env	*ft_lstlast_env(t_env *lst)
{
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back_env(t_env **alst, t_env *new)
{
	t_env	*last;

	if (alst)
	{
		if (*alst)
		{
			last = ft_lstlast_env(*alst);
			last->next = new;
		}
		else
			*alst = new;
	}
}