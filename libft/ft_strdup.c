/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 11:55:57 by jagarcia          #+#    #+#             */
/*   Updated: 2018/05/12 20:53:55 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*str1;
	int		len;
	int		i;

	if (!src)
		return (NULL);
	len = ft_strlen(src);
	if (!(str1 = (char *)malloc(sizeof(*str1) * (len + 1))))
		return (NULL);
	i = 0;
	while (src[i])
	{
		str1[i] = src[i];
		i++;
	}
	str1[i] = '\0';
	return (str1);
}
