/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putthepoint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <jagarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 05:20:16 by jagarcia          #+#    #+#             */
/*   Updated: 2018/02/23 17:59:55 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*for_f(char *str, int *siz_cuant)
{
	char	*new;
	int		pos;
	char	*aux;
	int		tmp;

	aux = ft_strchr(str, 'e');
	pos = aux - str - 1 + ft_atoi(aux + 1);
	ft_memset(aux, '0', ft_strlen(aux));
	tmp = 0;
	if (ft_abs((pos + 1) % ft_strlen(str)) < siz_cuant[0])
		tmp = siz_cuant[1] - ft_abs((pos + 1) % ft_strlen(str));
	if (!(new = ft_strnew(ft_strlen(str) + 1 + ((pos < 0) ? (-pos) : 0) + tmp)))
		return (NULL);
	ft_memset(new, '0', ft_strlen(str) + 1 + ((pos < 0) ? (-pos) : 0) + tmp);
	if (pos >= 0)
		ft_strncpy(new, str, pos + 1);
	new[(pos < 0) ? 1 : (pos + 1)] = '.';
	ft_strncpy(new + ((pos < 0) ? (-pos + 1) : (pos + 2)), str +
			((pos < 0) ? 0 : (pos + 1)), ft_strlen(str +
			((pos < 0) ? 0 : (pos + 1))));
	new = ft_strsub(new, 0, ft_strchr(new, '.') - new + siz_cuant[1]);
	return (new);
}

static char	*for_e(char *str, int *siz_cuant)
{
	char	*new;
	char	*aux;
	int		len;

	aux = ft_strchr(str, 'e');
	len = (aux - str - 1) + ft_atoi(aux + 1);
	if (!(new = ft_memset(ft_strnew(siz_cuant[1] + 5), '0', siz_cuant[1] + 5)))
		return (NULL);
	new[0] = str[0];
	if (siz_cuant[1])
	{
		new[1] = '.';
		ft_strncpy(new + 2, str + 1, siz_cuant[1] - 1);
	}
	new[siz_cuant[1] + 1] = 'e';
	new[siz_cuant[1] + 2] = (len < 0) ? '-' : '+';
	aux = ft_itoa(ft_abs(len));
	ft_strcpy(new + ((ft_abs(len) > 9) ? 3 : 4) + siz_cuant[1], aux);
	ft_strdel(&aux);
	return (new);
}

static char	*for_g_f(char *str, int *siz_cuant, int len, char *comm)
{
	char *new;

	if (!(new = for_f(str, siz_cuant)))
		return (NULL);
	if (ft_strchr(comm, '#'))
		return (new);
	if (ft_strchr(new, '.') - new >= siz_cuant[1])
		new = ft_strcutfree(new, siz_cuant[1], ft_strlen(new));
	else
	{
		siz_cuant[1]++;
		if (siz_cuant[0] < siz_cuant[1])
			siz_cuant[0] = siz_cuant[1];
	}
	len = ft_strlen(new) - 1;
	while (len >= 0 && (new[len] == '0' || new[len] == '.'))
	{
		if (len < siz_cuant[0])
			siz_cuant[0]--;
		if (new[len] == '.')
			return (ft_memset(new + len, 0, 1) - len);
		else
			new[len--] = 0;
	}
	return (new);
}

static char	*for_g_e(char *str, int *siz_cuant, int len, char *comm)
{
	char	*new;
	char	*aux;

	if (!(new = for_e(str, siz_cuant)))
		return (NULL);
	if (siz_cuant[1] == 1)
		siz_cuant[0]--;
	if (ft_strchr(comm, '#'))
		return (new);
	len = ft_strchr(new, 'e') - new - 1;
	while (len >= 0 && (new[len] == '0' || new[len] == '.'))
		len--;
	if (!(aux = ft_strncpy(ft_strnew(len + 5), new, len + 1)))
		return (NULL);
	ft_strcpy(aux + (len + 1), ft_strchr(new, 'e'));
	ft_strdel(&new);
	return (aux);
}

char		*ft_putthepoint(char *str, int *siz_cuant, char *comm)
{
	char	type;
	char	neg;
	char	*aux;
	int		len;

	neg = 0;
	if (*str == '-')
		neg = 1;
	type = ft_toupper(comm[ft_strlen(comm) - 1]);
	if (type == 'F')
		aux = for_f(str + neg, siz_cuant);
	else if (type == 'E')
		aux = for_e(str + neg, siz_cuant);
	else if ((len = (ft_strchr(str, 'e') - str) +
			ft_atoi(ft_strchr(str, 'e') + 1)) < -4 || len > siz_cuant[1])
		aux = for_g_e(str + neg, siz_cuant, len, comm);
	else
		aux = for_g_f(str + neg, siz_cuant, len, comm);
	ft_strdel(&str);
	if (neg && aux)
		aux = ft_strjoinfree(ft_strdup("-"), aux);
	if (siz_cuant[0] < (int)ft_strlen(aux))
		siz_cuant[0] = ft_strlen(aux);
	return (aux);
}
