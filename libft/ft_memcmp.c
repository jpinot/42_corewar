/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 23:41:27 by jagarcia          #+#    #+#             */
/*   Updated: 2017/11/13 01:23:52 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1cpy;
	unsigned char	*s2cpy;
	int				bubble;

	s1cpy = (unsigned char *)s1;
	s2cpy = (unsigned char *)s2;
	while (n > 0)
	{
		bubble = (*s1cpy) - (*s2cpy);
		if (bubble == 0)
		{
			s1cpy++;
			s2cpy++;
			n--;
		}
		else
			return (bubble);
	}
	return (0);
}
