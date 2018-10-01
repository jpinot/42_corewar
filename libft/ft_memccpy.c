/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 03:33:54 by jagarcia          #+#    #+#             */
/*   Updated: 2017/11/10 22:24:33 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char			*dstcpy;
	const char		*srccpy;
	char			c2;

	dstcpy = (char *)dst;
	srccpy = (const char *)src;
	c2 = c;
	if (n != 0)
	{
		while (n > 0)
		{
			*dstcpy = *srccpy;
			if (*srccpy == c2)
			{
				dstcpy++;
				return (dstcpy);
			}
			dstcpy++;
			srccpy++;
			n--;
		}
	}
	return (NULL);
}
