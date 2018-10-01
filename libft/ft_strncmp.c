/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 10:32:42 by jagarcia          #+#    #+#             */
/*   Updated: 2017/11/16 07:12:58 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	char unsigned	*s1cpy;
	char unsigned	*s2cpy;
	int				j;

	s1cpy = (char unsigned *)s1;
	s2cpy = (char unsigned *)s2;
	j = 0;
	if (n == 0)
		return (0);
	while (s1cpy[j] && s2cpy[j] && n-- > 0)
	{
		if (s1cpy[j] == s2cpy[j] && n > 0)
			j++;
		else if (s1cpy[j] != s2cpy[j])
			return (s1cpy[j] - s2cpy[j]);
	}
	return (s1cpy[j] - s2cpy[j]);
}
