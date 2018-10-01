/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asterisc_format.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 16:05:12 by jagarcia          #+#    #+#             */
/*   Updated: 2018/02/23 01:23:01 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int			exception(char *command, int pos)
{
	int		i;

	i = 0;
	while (!ft_isdigit(command[pos + i]) || command[pos + i] == '0')
	{
		if (command[pos + i] == '.')
		{
			while (ft_isdigit(command[pos + i]))
				i++;
		}
		if (!command[pos + i])
			return (1);
		while (ft_isdigit(command[pos + i]))
		{
			i++;
			if (!ft_isdigit(command[pos + i]) && command[pos + i] != '$')
				return (0);
		}
		i++;
	}
	if (pos == 0 || command[pos - 1] != '.')
		return (0);
	return (1);
}

static void			modify_comm(char **command, int pos, int dolar, va_list *ap)
{
	void	*tmp;
	int		aux;
	char	*inser;

	if (!dolar)
		aux = va_arg(ap[1], int);
	else
	{
		tmp = ft_locate_date(*command + pos + 1, 5, ap[0], ap[1]);
		aux = *((int *)tmp);
		ft_memdel(&tmp);
	}
	*command = ft_strcutfree(*command, pos, pos + 1);
	if (aux == 0)
	{
		if (!exception(*command, pos))
			return ;
	}
	inser = ft_strjoinfree(ft_itoa(aux), ft_strdup(","));
	if (pos >= 1 && (*command)[pos - 1] != '.')
		inser = ft_strjoinfree(ft_strdup(","), inser);
	*command = ft_strinsertfree(*command, inser, pos);
}

void				ft_asterisc_format(char **command, va_list *ap)
{
	char	*tmp;
	int		i;

	while ((tmp = ft_strchr(*command, '*')))
	{
		if (ft_isdigit(tmp[1]) && tmp[1] != 0)
		{
			i = 1;
			while (ft_isdigit(tmp[i]))
				i++;
			if (tmp[i] == '$')
				modify_comm(command, tmp - *command, i, ap);
			else
				modify_comm(command, tmp - *command, 0, ap);
		}
		else
			modify_comm(command, tmp - *command, 0, ap);
	}
}
