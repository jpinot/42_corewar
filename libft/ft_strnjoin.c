/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 02:40:10 by jagarcia          #+#    #+#             */
/*   Updated: 2018/02/19 12:34:49 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoin(const char *s1, const char *s2, unsigned int n)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	str = NULL;
	i = 0;
	j = 0;
	if (!(str = ft_strnew(ft_strlen(s1) + n)))
		return (NULL);
	while (s1[j])
		str[i++] = s1[j++];
	j = 0;
	while (j < n)
		str[i++] = s2[j++];
	return (str);
}
