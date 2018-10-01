/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 04:34:49 by jagarcia          #+#    #+#             */
/*   Updated: 2018/02/15 07:18:04 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static	void	*selector(char *com, va_list ap, va_list ap2)
{
	if (com[ft_strlen(com) - 1] == 'c' || com[ft_strlen(com) - 1] == 'C')
		return (ft_locate_date(com, 7, ap, ap2));
	return (ft_locate_pointer(com, ap, ap2));
}

static void		modify_len(wchar_t *wvariable, int *siz_cuant)
{
	int	i;
	int cuant;

	i = 0;
	cuant = 0;
	while (wvariable[i] && siz_cuant[1] >= 0)
	{
		cuant += ft_strlen_free((ft_utf8(wvariable[i++])));
		if (cuant > siz_cuant[1])
		{
			cuant -= ft_strlen_free((ft_utf8(wvariable[i - 1])));
			siz_cuant[1] = cuant;
			break ;
		}
	}
}

char			*ft_wchar(va_list ap, va_list ap2, int *siz_cuant, char *comm)
{
	wchar_t		*wvariable;
	char		*res;
	int			i;

	i = 0;
	if (!(wvariable = (wchar_t *)selector(comm, ap, ap2)))
		return (ft_strdup("(null)"));
	res = ft_strnew(0);
	while (wvariable[i])
	{
		if ((wvariable[i] >= 0xd800 && wvariable[i] < 0xd800 + 2048)
				|| wvariable[i] >= 0x11ffff || wvariable[i] < 0)
			return (NULL);
		if (!(res = ft_strjoinfree(res, ft_utf8(wvariable[i++]))))
			return (NULL);
	}
	if (ft_toupper(comm[ft_strlen(comm) - 1] == 'C'))
	{
		free(wvariable);
		return (res);
	}
	modify_len(wvariable, siz_cuant);
	return (res);
}
