//
// Created by Hajar Sabir on 7/11/22.
//

#include "libft.h"

void	ft_dlstadd_front(t_dlst **lst, t_dlst *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
		(*lst)->prev = new;
	}
}

/* Initialise a new doubly linked list */
t_dlst	*ft_dlstnew(void *content)
{
	t_dlst	*tmp;

	tmp = (t_dlst *) malloc(sizeof(t_dlst));
	if (!tmp)
		return (NULL);
	tmp->content = content;
	tmp->next = NULL;
	tmp->prev = NULL;
	return (tmp);
}