//
// Created by Hajar Sabir on 7/11/22.
//

#ifndef FT_DLST_H
#define FT_DLST_H

typedef	struct	s_dlst t_dlst;

t_dlst	*ft_dlstnew(void *content);
void	ft_dlstadd_front(t_dlst **lst, t_dlst *new);

struct	s_dlst
{
	void	*content;
	char	type;
	t_dlst	*next;
	t_dlst	*prev;
};

#endif //FT_DLST_H
