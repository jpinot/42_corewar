/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 23:39:11 by jagarcia          #+#    #+#             */
/*   Updated: 2017/11/12 21:33:09 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int elem, size_t cuant)
{
	char	*str1;

	str1 = (char *)str;
	if (cuant != 0)
	{
		while (cuant)
		{
			*str1 = elem;
			str1++;
			cuant--;
		}
	}
	return (str);
}
