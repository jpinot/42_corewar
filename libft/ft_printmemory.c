/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printmemory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <jagarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 04:01:34 by jagarcia          #+#    #+#             */
/*   Updated: 2018/02/19 11:35:46 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

#define L_ENDIAN_H "=================LITTLE ENDIAN=================\n\n"

static void	ft_printbyte(size_t j, char **aux)
{
	char	*n;
	size_t	len_n;

	if (!(n = ft_itoa(j + 1)))
		return ;
	len_n = ft_strlen(n);
	ft_strcpy(*aux, "  Byte ");
	(*aux) += 7;
	ft_strcpy(*aux, n);
	(*aux) += len_n;
	ft_memset(*aux, ' ', 5 - len_n);
	(*aux) += 5 - len_n;
	ft_strdel(&n);
}

static void	ft_printhex(char *n, char **aux, size_t j)
{
	ft_strcpy(*aux, "  ");
	(*aux) += 2;
	ft_memset(*aux, ((n[j] & 0xF0) >> 4) > 9 ? ((n[j] & 0xF0) >> 4) - 10 + 'A' :
			((n[j] & 0xF0) >> 4) + 48, 1);
	(*aux)++;
	ft_strcpy(*aux, "    ");
	(*aux) += 4;
	ft_memset(*aux, (n[j] & 0xF) > 9 ? (n[j] & 0xF) - 10 + 'A' :
			(n[j] & 0xF) + 48, 1);
	(*aux)++;
	ft_strcpy(*aux, "  | ");
	(*aux) += 4;
}

static void	ft_printbin(char *n, char **aux, size_t j)
{
	char	*bin;
	char	*num;

	if (!(num = ft_strnew(1)))
		return ;
	ft_strcpy(*aux, "0000 0000 | ");
	num[0] = (n[j] & 0xF0) >> 4;
	bin = ft_dectobin(num, 1);
	if (ft_strlen(bin) != 0)
		ft_strncpy((*aux) + 4 - ft_strlen(bin), bin, ft_strlen(bin));
	ft_strdel(&bin);
	if (!(num = ft_strnew(1)))
		return ;
	num[0] = n[j] & 0xF;
	bin = ft_dectobin(num, 1);
	if (ft_strlen(bin) != 0)
		ft_strncpy((*aux) + 9 - ft_strlen(bin), bin, ft_strlen(bin));
	ft_strdel(&bin);
	(*aux) += 12;
}

static void	ft_print_littleendian(char *n, size_t len, char *str)
{
	size_t	i;
	size_t	j;
	char	*aux;

	i = 0;
	aux = str;
	ft_strcpy(aux, L_ENDIAN_H);
	aux += 49;
	while (i < len)
	{
		j = i;
		while (((j % 4) || (j == i)) && (j < len))
			ft_printbyte(j++, &aux);
		ft_memset(aux++, '\n', 1);
		j = i;
		while (((j % 4) || (j == i)) && (j < len))
			ft_printhex(n, &aux, j++);
		ft_memset(aux++, '\n', 1);
		j = i;
		while (((j % 4) || (j == i)) && (j < len))
			ft_printbin(n, &aux, j++);
		ft_memset(aux++, '\n', 1);
		i += (j - i);
	}
}

char		*ft_printmemory(void *mem, size_t len)
{
	char	*n;
	char	*str;
	size_t	i;

	i = 0;
	n = (char *)mem;
	if (!(str = ft_strnew(98 + (len * 36) + (len / 4) +
					((len % 4) ? 1 : 0) + 100)))
		return (NULL);
	ft_print_littleendian(n, len, str);
	return (str);
}
