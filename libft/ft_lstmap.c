/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 05:16:58 by jagarcia          #+#    #+#             */
/*   Updated: 2017/11/16 07:52:01 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newlist;
	t_list	*tmp;
	t_list	*cpynewlist;

	if (lst)
	{
		tmp = (*f)(lst);
		if (!(newlist = ft_lstnew(tmp->content, tmp->content_size)))
			return (NULL);
		cpynewlist = newlist;
		while (lst->next)
		{
			lst = lst->next;
			tmp = (*f)(lst);
			if (!(cpynewlist->next = ft_lstnew(tmp->content,
							tmp->content_size)))
				return (NULL);
			cpynewlist = cpynewlist->next;
		}
	}
	else
		return (NULL);
	return (newlist);
}
