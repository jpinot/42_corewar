/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 19:40:35 by jagarcia          #+#    #+#             */
/*   Updated: 2017/11/13 18:24:34 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*scpy;
	char	ccpy;
	size_t	len;

	scpy = (char *)s;
	len = ft_strlen(scpy);
	ccpy = (char)c;
	while (len > 0)
	{
		if (scpy[len] == ccpy)
			return (&scpy[len]);
		len--;
	}
	if (scpy[len] == ccpy)
		return (&scpy[len]);
	return (NULL);
}
