/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <jagarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 14:54:12 by jagarcia          #+#    #+#             */
/*   Updated: 2018/02/12 16:41:01 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_memjoinfree(void *str1, void *str2, size_t l1, size_t l2)
{
	char	*new;
	char	*s1;
	char	*s2;

	s1 = (char *)str1;
	s2 = (char *)str2;
	if (s1 && s2)
	{
		if (!(new = ft_strnew(l1 + l2)))
			return (NULL);
		ft_memcpy(new, s1, l1);
		ft_memcpy(new + l1, s2, l2);
		ft_strdel(&s1);
		ft_strdel(&s2);
		return (new);
	}
	return (NULL);
}
