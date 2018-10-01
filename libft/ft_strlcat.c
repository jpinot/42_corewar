/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 01:40:25 by jagarcia          #+#    #+#             */
/*   Updated: 2017/11/13 17:40:09 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t len)
{
	char	*dstcpy;
	char	*srccpy;
	size_t	length;
	size_t	bubble;

	bubble = len;
	length = ft_strlen(dst) + ft_strlen(src);
	dstcpy = dst;
	srccpy = (char *)src;
	while (*dstcpy)
	{
		if (len == 0)
			return (bubble + ft_strlen(src));
		len--;
		dstcpy++;
	}
	while (len > 1 && *srccpy)
	{
		*dstcpy++ = *srccpy++;
		len--;
	}
	*dstcpy = '\0';
	return (length);
}
