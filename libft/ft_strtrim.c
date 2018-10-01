/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 18:55:37 by jagarcia          #+#    #+#             */
/*   Updated: 2017/11/16 09:56:29 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*cpyandret(int i, const char *s)
{
	char *new;

	if (!(new = (char *)malloc(i + 2)))
		return (NULL);
	ft_memcpy(new, s, i + 1);
	new[i + 1] = '\0';
	return (new);
}

char		*ft_strtrim(char const *s)
{
	char	*new;
	int		i;

	if (s)
	{
		i = ft_strlen(s) - 1;
		while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		{
			i--;
			if (i == 0)
			{
				if (!(new = (char *)malloc(1)))
					return (NULL);
				new[0] = 0;
				return (new);
			}
		}
		while (*s == ' ' || *s == '\n' || *s == '\t')
		{
			s++;
			i--;
		}
		return (cpyandret(i, s));
	}
	return (NULL);
}
