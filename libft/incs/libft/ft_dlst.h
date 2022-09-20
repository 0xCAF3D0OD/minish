/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdi-noce <kdi-noce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 16:22:48 by kdi-noce          #+#    #+#             */
/*   Updated: 2022/09/20 19:13:07 by kdi-noce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
