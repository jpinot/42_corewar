/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_round.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <jagarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 05:48:56 by jagarcia          #+#    #+#             */
/*   Updated: 2018/03/23 19:31:08 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*resize_str(char *str, char ac)
{
	char	*new;

	if (ac)
	{
		if (!(new = ft_strnew(ft_strlen(str) + 1)))
			return (NULL);
		new[0] = '1';
		ft_strcpy(new + 1, str);
		ft_strdel(&str);
		return (new);
	}
	return (str);
}

static char	*apply_round(char *str, int pos, char is_neg)
{
	char	ac;

	str = is_neg ? str + 1 : str;
	ac = 0;
	while ((pos + 1) > 0)
	{
		if ((str[pos] >= '5' || ac) && pos >= 0)
		{
			pos--;
			if (++(str[pos]) > '9')
			{
				str[pos] = '0';
				ac = 1;
			}
			else
			{
				ac = 0;
				break ;
			}
		}
		else
			break ;
	}
	str = is_neg ? str - 1 : str;
	return (resize_str(str, ac));
}

char		*ft_round(char *str, int pos, char *comm)
{
	char	*e_pos;

	if (ft_toupper(comm[ft_strlen(comm) - 1]) == 'F')
	{
		e_pos = ft_strchr(str, 'e');
		pos = pos + (e_pos - str) + ft_atoi(e_pos + 1) - (pos ? 1 : 0);
	}
	if (pos > (int)ft_strlen(str) - 3)
		return (str);
	return (apply_round(str, pos, (*str == '-') ? 1 : 0));
}
