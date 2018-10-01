/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 01:40:25 by jagarcia          #+#    #+#             */
/*   Updated: 2017/11/11 02:07:59 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*dstcpy;
	char	*srccpy;

	dstcpy = dst;
	srccpy = (char *)src;
	while (len > 0 && *srccpy)
	{
		*dstcpy++ = *srccpy++;
		len--;
	}
	if (len > 0 && !(*srccpy))
	{
		while (len > 0)
		{
			*dstcpy++ = '\0';
			len--;
		}
	}
	return (dst);
}
