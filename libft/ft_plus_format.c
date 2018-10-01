/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plus_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 06:41:32 by jagarcia          #+#    #+#             */
/*   Updated: 2018/02/12 15:02:43 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char		*an_space(char *str)
{
	char *new_str;

	if (*(str + 1) == '-')
	{
		if (!(new_str = ft_strdup(str + 1)))
			return (NULL);
	}
	else if (!(new_str = ft_strjoin("+", str + 1)))
		return (NULL);
	ft_strdel(&str);
	return (new_str);
}

static char	*plus_float(char *str, int *siz_cuant)
{
	char	*new_str;

	if (*str == ' ')
		return (an_space(str));
	if (*str == '0' && ft_isdigit(*(str + 1)))
	{
		*str = '+';
		return (str);
	}
	if ((unsigned long)siz_cuant[0] < ft_strlen(str) + 1)
		siz_cuant[0]++;
	if (!(new_str = ft_strjoin("+", str)))
		return (NULL);
	ft_strdel(&(str));
	return (new_str);
}

static char	*plus_normal(char *str, int *siz_cuant)
{
	char	*new_str;

	if (*str == ' ')
		return (an_space(str));
	if (*str == '0' && ft_isdigit(*(str + 1)) && siz_cuant[1] < 0)
	{
		*str = '+';
		return (str);
	}
	if ((unsigned long)siz_cuant[0] < ft_strlen(str) + 1)
		siz_cuant[0]++;
	if (!(new_str = ft_strjoin("+", str)))
		return (NULL);
	ft_strdel(&(str));
	return (new_str);
}

char		*ft_plus_format(char *command, char *str, int *siz_cuant)
{
	if (*str != '-')
		if (ft_strchr(command, '+'))
		{
			if (command[ft_strlen(command) - 1] == 'f')
				return (plus_float(str, siz_cuant));
			return (plus_normal(str, siz_cuant));
		}
	return (str);
}
