/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 21:44:13 by jagarcia          #+#    #+#             */
/*   Updated: 2017/11/18 01:33:03 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	char	*s1cpy;
	char	*s2cpy;
	char	*bubble;
	int		bubble2;

	if (ft_strlen(s2) == 0)
		return ((char *)s1);
	s1cpy = (char *)s1;
	s2cpy = (char *)s2;
	while (*s1cpy && len != 0)
	{
		if (*s1cpy == *s2cpy)
		{
			bubble = s1cpy;
			bubble2 = len;
			while ((*bubble++ == *s2cpy++) && bubble2-- > 0)
				if (!*(s2cpy))
					return (s1cpy);
		}
		if (s2 != s2cpy)
			s2cpy = (char *)s2;
		s1cpy++;
		len--;
	}
	return (NULL);
}
