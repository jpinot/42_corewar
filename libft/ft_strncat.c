/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 02:09:32 by jagarcia          #+#    #+#             */
/*   Updated: 2017/11/13 15:15:15 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*s1cpy;
	char	*s2cpy;

	s1cpy = s1;
	s2cpy = (char *)s2;
	while (*s1cpy)
		s1cpy++;
	while (n > 0 && *s2cpy)
	{
		*s1cpy++ = *s2cpy++;
		n--;
	}
	*s1cpy = '\0';
	return (s1);
}
