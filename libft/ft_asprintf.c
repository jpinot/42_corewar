/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 20:10:07 by jagarcia          #+#    #+#             */
/*   Updated: 2018/02/23 16:24:51 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int		exec_command(char *str, va_list *ap, size_t len, char **res)
{
	char			*command;
	int				aux;
	int				n;

	n = 0;
	if (!str)
		return (len);
	if ((aux = ft_findend(str)) < 0)
		if (!(aux = ft_strlen(str) - 1))
			return (len);
	if (!(command = ft_strsub(str, 1, aux)))
		return (-1);
	n = ft_strchr(g_types, command[ft_strlen(command) - 1]) - g_types;
	if (n < 0)
	{
		aux = ft_error_type(command, ap, res, len);
		return (aux);
	}
	aux = (*g_type_func[n])(command, ap, res, len);
	return (aux);
}

static int		ft_printf_body(va_list *ap, const char *str, char **res)
{
	char	*aux;
	char	*head;
	int		len;
	int		aux_len;
	char	*aux_res;

	head = (char *)str;
	len = 0;
	while (1)
	{
		aux = ft_strchr(head, '%');
		aux_len = (int)((aux - head) < 0 ? (int)ft_strlen(head) : aux - head);
		aux_res = ft_memmove(ft_strnew(len + aux_len), *res, len);
		ft_memmove(aux_res + len, head, aux_len);
		if ((aux_len = exec_command(aux, ap, len + aux_len, &aux_res)) < 0)
			return (-len);
		len = aux_len;
		ft_strdel(res);
		*res = aux_res;
		head = aux > 0 ? aux + ft_findend(aux) + 1 : head + ft_strlen(head);
		if (!aux || ft_findend(aux) < 0)
			break ;
	}
	return (len);
}

int				ft_asprintf(char **buffer, const char *str, ...)
{
	char		*res;
	va_list		ap[2];
	int			len;

	len = 0;
	va_start(ap[0], str);
	va_copy(ap[1], ap[0]);
	res = NULL;
	len = ft_printf_body(ap, str, &res);
	if (len < 0)
	{
		write(1, res, -len);
		len = -1;
	}
	else if (len == 0 && !res)
		return (-1);
	else
	{
		res = ft_colors(res, &len);
		*buffer = ft_strdup(res);
	}
	va_end(ap[0]);
	va_end(ap[1]);
	ft_strdel(&res);
	return (len);
}
