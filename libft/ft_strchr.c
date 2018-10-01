/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 19:40:35 by jagarcia          #+#    #+#             */
/*   Updated: 2017/11/11 21:06:09 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char *scpy;
	char ccpy;

	scpy = (char *)s;
	ccpy = (char)c;
	while (*scpy)
	{
		if (*scpy == ccpy)
			return (scpy);
		scpy++;
	}
	if (*scpy == ccpy)
		return (scpy);
	return (NULL);
}
