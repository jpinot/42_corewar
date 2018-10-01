/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_space_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 06:28:21 by jagarcia          #+#    #+#             */
/*   Updated: 2018/02/12 15:04:38 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*space_float(char *command, char *str, int *siz_cuant)
{
	char *new_str;

	if (ft_search_zero_format(command) && (*str == '0') &&
		(ft_isdigit(*(str + 1))))
	{
		*str = ' ';
		return (str);
	}
	if ((unsigned long)siz_cuant[0] < ft_strlen(str) + 1)
		siz_cuant[0]++;
	if (!(new_str = ft_strjoin(" ", str)))
		return (NULL);
	ft_strdel(&str);
	return (new_str);
}

static char	*space_normal(char *command, char *str, int *siz_cuant)
{
	char *new_str;

	if (ft_search_zero_format(command) && (*str == '0') &&
		(ft_isdigit(*(str + 1))) && siz_cuant[1] == -1)
	{
		*str = ' ';
		return (str);
	}
	if ((unsigned long)siz_cuant[0] < ft_strlen(str) + 1)
		siz_cuant[0]++;
	if (!(new_str = ft_strjoin(" ", str)))
		return (NULL);
	ft_strdel(&str);
	return (new_str);
}

char		*ft_space_format(char *command, char *str, int *siz_cuant)
{
	if (*str != '-')
		if (ft_strchr(command, ' '))
		{
			if (command[ft_strlen(command) - 1] == 'f')
				return (space_float(command, str, siz_cuant));
			return (space_normal(command, str, siz_cuant));
		}
	return (str);
}
