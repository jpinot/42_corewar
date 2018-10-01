/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 21:44:13 by jagarcia          #+#    #+#             */
/*   Updated: 2017/11/11 22:44:02 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	char	*s1cpy;
	char	*s2cpy;
	char	*bubble;

	s1cpy = (char *)s1;
	s2cpy = (char *)s2;
	if (ft_strlen(s2cpy) == 0)
		return (s1cpy);
	while (*s1cpy)
	{
		if (*s1cpy == *s2cpy)
		{
			bubble = s1cpy;
			while (*bubble++ == *s2cpy++)
			{
				if (!*s2cpy)
					return (s1cpy);
			}
		}
		if (s2 != s2cpy)
			s2cpy = (char *)s2;
		s1cpy++;
	}
	return (NULL);
}
