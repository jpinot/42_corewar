/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnext.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 05:02:27 by jagarcia          #+#    #+#             */
/*   Updated: 2017/11/18 07:43:22 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnext(t_list *list1, t_list *list2, char *cont, int cont_size)
{
	if (!(list1->next = ft_lstnew(cont, cont_size)))
		return (NULL);
	list2 = list1->next;
	return (list2);
}
