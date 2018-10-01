/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 10:32:42 by jagarcia          #+#    #+#             */
/*   Updated: 2017/11/13 21:26:15 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	char unsigned	*s1cpy;
	char unsigned	*s2cpy;
	int				j;

	s1cpy = (char unsigned *)s1;
	s2cpy = (char unsigned *)s2;
	j = 0;
	while (s1cpy[j])
	{
		if (s1cpy[j] == s2cpy[j])
			j++;
		else
			return (s1cpy[j] - s2cpy[j]);
	}
	return (s1cpy[j] - s2cpy[j]);
}
