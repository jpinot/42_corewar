/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utf8.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 02:05:22 by jagarcia          #+#    #+#             */
/*   Updated: 2018/02/01 00:56:42 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*ft_7f(wchar_t num)
{
	char	*str;

	if (!(str = ft_strnew(1)))
		return (NULL);
	str[0] = num;
	return (str);
}

static char	*ft_7ff(wchar_t num)
{
	char	*str;

	if (!(str = ft_strnew(2)))
		return (NULL);
	str[0] = (((num & 0x7C0) >> 6) + 0xC0);
	str[1] = ((num & 0x3F) + 0x80);
	return (str);
}

static char	*ft_ffff(wchar_t num)
{
	char	*str;

	if (!(str = ft_strnew(3)))
		return (NULL);
	str[0] = (((num & 0xF000) >> 12) + 0xE0);
	str[1] = (((num & 0xFC0) >> 6) + 0x80);
	str[2] = ((num & 0x3F) + 0x80);
	return (str);
}

static char	*ft_1fffff(wchar_t num)
{
	char	*str;

	if (!(str = ft_strnew(4)))
		return (NULL);
	str[0] = (((num & 0x1C0000) >> 18) + 0xF0);
	str[1] = (((num & 0x3F000) >> 12) + 0x80);
	str[2] = (((num & 0xFC0) >> 6) + 0x80);
	str[3] = ((num & 0x3F) + 0x80);
	return (str);
}

char		*ft_utf8(wchar_t num)
{
	if (num < 0x7F)
		return (ft_7f(num));
	if (num >= 0x7F && num <= 0x7FF)
		return (ft_7ff(num));
	if (num > 0x7FF && num <= 0xFFFF)
		return (ft_ffff(num));
	if (num > 0xFFFF && num <= 0x1FFFFF)
		return (ft_1fffff(num));
	return (0);
}
