/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ajust_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 06:58:25 by jagarcia          #+#    #+#             */
/*   Updated: 2018/06/08 19:07:39 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ajust_num_hex_oct_bin(int *siz_cuant, char *variable, int len)
{
	int	neg;

	neg = 0;
	if (*variable == '-')
		neg = 1;
	if (!siz_cuant[1] && *variable == '0')
	{
		ft_strdel(&variable);
		variable = ft_strdup("\0");
		len = ft_strlen(variable);
	}
	siz_cuant[0] = siz_cuant[0] > siz_cuant[1] ?
		siz_cuant[0] : siz_cuant[1] + neg;
	if (siz_cuant[0] < len)
		siz_cuant[0] = len;
	if (siz_cuant[1] >= 0)
	{
		if (siz_cuant[1] <= len - neg)
			siz_cuant[1] = len - neg;
	}
	return ;
}

static void	ajust_gfloat(int *siz_cuant, int len, int exp)
{
	siz_cuant[1] -= siz_cuant[1] ? 1 : 0;
	if (siz_cuant[0] < siz_cuant[1])
		siz_cuant[0] = siz_cuant[1];
	if (!siz_cuant[1])
		siz_cuant[1] = 1;
	if (len - exp < -4 || (len - exp) > siz_cuant[1])
		siz_cuant[0] += 5;
}

static void	ajust_float(int *siz_cuant, char *variab, char type, int len)
{
	int exp;

	len -= 4;
	exp = ft_atoi(ft_strchr(variab, 'e') + 2);
	if (siz_cuant[1] < 0)
		siz_cuant[1] = 6;
	if (siz_cuant[1])
		siz_cuant[1]++;
	if (type == 'E')
	{
		if (siz_cuant[0] < siz_cuant[1] + 5)
			siz_cuant[0] = siz_cuant[1] + 5;
		return ;
	}
	if (type == 'G')
	{
		ajust_gfloat(siz_cuant, len, exp);
		return ;
	}
	if (exp > 16)
		siz_cuant[0] = siz_cuant[1] + 1;
	else if (siz_cuant[0] < len - exp + siz_cuant[1])
		siz_cuant[0] = len - exp + siz_cuant[1] - 1;
	return ;
}

static void	ajust_char_string(int *siz_cuant, char *variable, int type, int len)
{
	if (siz_cuant[1] > len || siz_cuant[1] < 0)
		siz_cuant[1] = len;
	if ((!siz_cuant[0] || siz_cuant[0] < siz_cuant[1]) && siz_cuant[1])
		siz_cuant[0] = siz_cuant[1];
	if (!*variable && type == 'C')
	{
		if (!siz_cuant[0])
			siz_cuant[0] = 1;
		siz_cuant[1] = 1;
	}
}

void		ft_ajust_params(int *siz_cuant, char *variable, char *comm)
{
	int t;
	int	len;

	len = ft_strlen(variable);
	t = ft_toupper(comm[ft_strlen(comm) - 1]);
	if (t == 'D' || t == 'X' || t == 'B' || t == 'O' || t == 'U' || t == 'I')
		return (ajust_num_hex_oct_bin(siz_cuant, variable, len));
	else if (t == 'F' || t == 'G' || t == 'E')
		return (ajust_float(siz_cuant, variable, t, len));
	else if (t == 'C' || t == 'S')
		return (ajust_char_string(siz_cuant, variable, t, len));
	return ;
}
