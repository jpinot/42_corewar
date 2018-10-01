/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 04:21:24 by jagarcia          #+#    #+#             */
/*   Updated: 2017/11/18 06:48:18 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*mylist;

	if (!(mylist = (t_list *)ft_memalloc(sizeof(t_list))))
		return (NULL);
	if (content)
	{
		mylist->content = ft_memalloc(content_size);
		ft_memcpy(mylist->content, content, content_size);
		mylist->content_size = content_size;
	}
	else
	{
		mylist->content = NULL;
		mylist->content_size = 0;
	}
	mylist->next = NULL;
	return (mylist);
}
