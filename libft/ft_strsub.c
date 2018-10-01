/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 18:21:12 by jagarcia          #+#    #+#             */
/*   Updated: 2017/11/16 09:56:02 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;

	if (s)
	{
		i = start;
		new = ft_strnew(len);
		if (new == NULL)
			return (NULL);
		while (i - start < len)
		{
			new[i - start] = s[i];
			i++;
		}
		new[i - start] = '\0';
		return (new);
	}
	return (NULL);
}
