/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <jagarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 04:29:17 by jagarcia          #+#    #+#             */
/*   Updated: 2018/07/03 23:02:00 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char		check_arr(char type, char *str, int pos, int i)
{
	int		j;
	char	*aux;

	j = 0;
	if (!(aux = ft_strsub(str, pos, i - pos)))
		return (0);
	while (j < 10)
	{
		if (!(ft_strcmp(type ? g_colors[j] : g_formats[j], aux)))
		{
			ft_strdel(&aux);
			return (1);
		}
		j++;
	}
	if ((ft_atoi(aux + 2) <= (type ? 255 : 9)) && !ft_strncmp("C:", aux, 2)
			&& ft_issdigit(aux + 2))
	{
		ft_strdel(&aux);
		return (2);
	}
	ft_strdel(&aux);
	return (0);
}

static int		check_com(char *str, int pos, int len)
{
	int		i;
	char	bool;

	bool = 0;
	i = pos;
	while (i < len)
	{
		if (str[i] == ',')
		{
			if (!(check_arr(0, str, pos, i)) || bool++)
				return (0);
			pos = i + 1;
		}
		if (str[i] == '}')
		{
			if ((check_arr(1, str, pos, i) && bool) ||
				((check_arr(1, str, pos, i) ||
				check_arr(0, str, pos, i)) && !bool))
				return (i);
			return (0);
		}
		i++;
	}
	return (0);
}

static char		*select_num(char type, char *str, int start, int end)
{
	char	*aux;
	int		i;

	if (!(aux = ft_strsub(str, start, end - start)))
		return (NULL);
	i = 0;
	while (i < (type ? 8 : 10))
	{
		if (!(ft_strcmp(type ? g_colors[i] : g_formats[i], aux)))
		{
			aux[0] = type ? 'm' : ';';
			aux[1] = '\0';
			return (ft_strjoinfree(ft_itoa(i), aux));
		}
		i++;
	}
	i = ft_atoi(aux + 2);
	aux[0] = type ? 'm' : ';';
	aux[1] = '\0';
	return (ft_strjoinfree(ft_itoa(i), aux));
}

static char		*apply_com(char *str, int start, int end, int *len)
{
	char	*new;
	char	*aux;
	char	*res;

	if (!(ft_strncmp("eoc}", str + start, 4)))
		new = ft_strcpy(ft_strnew(7), "\033[0m");
	else
	{
		new = ft_strcpy(ft_strnew(5), "\033[");
		aux = ft_strchr(str + start, ',');
		if (aux && ft_strchr(str + start, '}') > aux)
			new = ft_strjoinfree(new, select_num(0, str, start,
					(int)((aux++) - str)));
		else
			aux = str + start;
		new = ft_strjoinfree(new, ft_strcpy(ft_strnew(5), "38;5;"));
		new = ft_strjoinfree(new, select_num(1, str, (int)(aux - str), end));
	}
	if (!new)
		return (NULL);
	*len = *len - (end - start - 1) + ft_strlen(new);
	res = ft_strcat(ft_strncpy(ft_strnew(*len), str, start - 1), new);
	res = ft_strcat(res, str + end + 1);
	ft_strdel(&new);
	return (res);
}

char			*ft_colors(char *str, int *len)
{
	int		i;
	int		end;
	char	*aux;

	if ((int)ft_strlen(str) != (*len))
		return (str);
	i = 0;
	while (i < *len)
	{
		if (str[i] == '{')
		{
			if ((end = check_com(str, i + 1, *len)) && str[i + 1] != '}')
			{
				aux = str;
				if (!(str = apply_com(str, i + 1, end, len)))
					return (NULL);
				free(aux);
			}
			i++;
		}
		else
			i++;
	}
	return (str);
}
