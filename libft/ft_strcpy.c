/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 00:56:35 by jagarcia          #+#    #+#             */
/*   Updated: 2017/11/11 01:19:19 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	char *dstcpy;
	char *srccpy;

	dstcpy = dst;
	srccpy = (char *)src;
	while (*srccpy)
		*dstcpy++ = *srccpy++;
	*dstcpy = '\0';
	return (dst);
}
