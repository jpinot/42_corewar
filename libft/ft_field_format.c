/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_field_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 21:13:24 by jagarcia          #+#    #+#             */
/*   Updated: 2018/09/30 22:26:03 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int		take_num(char *comm, int *len)
{
	while (*len >= 0 && (ft_isdigit(comm[*len])))
	{
		(*len)--;
		if (*len > 0 && comm[*len] == '-' && comm[*len - 1] == '.')
			(*len)--;
	}
	if (*len >= 0 && ((comm[(*len)] != '.' && ft_atoi(comm + *len + 1) != 0) ||
				comm[(*len)] == ','))
	{
		(*len)++;
		return (0);
	}
	return (1);
}

static int		take_size(char *comm, int len)
{
	while (len >= 0)
	{
		if (comm[len] == '$')
		{
			len--;
			while (len >= 0 && ft_isdigit(comm[len]))
				len--;
			if (len < 0)
				return (0);
		}
		else if (ft_isdigit(comm[len]))
		{
			if (!take_num(comm, &len))
				break ;
		}
		if (len >= 0 && comm[len] != '$')
			len--;
	}
	return (ft_atoi(comm + (len < 0 ? 0 : len)));
}

void			ft_field_format(int *size_cuant,
		char **command, va_list *ap)
{
	int		len;

	if (ft_strchr(*command, '*'))
		ft_asterisc_format(command, ap);
	len = ft_strlen(*command) - 1;
	size_cuant[0] = take_size(*command, len);
	while (len >= 0 && (*command)[len] != '.')
		len--;
	if (len >= 0)
		size_cuant[1] = ft_atoi(*command + len + 1);
	if (len < 0 || size_cuant[1] < -1)
		size_cuant[1] = -1;
}
