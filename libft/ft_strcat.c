/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 02:09:32 by jagarcia          #+#    #+#             */
/*   Updated: 2017/11/13 15:11:57 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	char unsigned	*s1cpy;

	s1cpy = (char unsigned *)s1;
	while (*s1cpy)
		s1cpy++;
	while (*s2)
		*s1cpy++ = *s2++;
	*s1cpy = '\0';
	return (s1);
}
