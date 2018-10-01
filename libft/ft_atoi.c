/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 19:02:00 by jagarcia          #+#    #+#             */
/*   Updated: 2018/06/29 12:17:06 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		convert(const char *str)
{
	int n;
	int i;

	i = 0;
	n = 0;
	while (str[i] >= '0' && str[i] <= '9')
		n = (n * 10) + (str[i++] - '0');
	return (n);
}

int				ft_atoi(const char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if ((str[i] == ' ') || (str[i] == '\f') || (str[i] == '\n') ||
				(str[i] == '\r') || (str[i] == '\t') || (str[i] == '\v'))
			i++;
		else if (str[i] == '+' || str[i] == '-' ||
				(str[i] >= '0' && str[i] <= '9'))
		{
			if (str[i] == '-')
				return (-(convert(str + (++i))));
			else if (str[i] == '+')
				return (convert(str + (++i)));
			return (convert(str + i));
		}
		else
			return (0);
	}
	return (0);
}
