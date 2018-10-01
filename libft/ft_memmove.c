/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 17:24:38 by jagarcia          #+#    #+#             */
/*   Updated: 2017/11/13 00:27:40 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dstcpy;
	const char	*srccpy;

	dstcpy = (char *)dst;
	srccpy = (char *)src;
	if ((dst < src) && len != 0)
	{
		while (len > 0)
		{
			*dstcpy++ = *srccpy++;
			len--;
		}
	}
	else if ((dst > src) && len != 0)
	{
		while (len > 0)
		{
			dstcpy[len - 1] = srccpy[len - 1];
			len--;
		}
	}
	return (dst);
}
