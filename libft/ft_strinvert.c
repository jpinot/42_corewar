/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strinvert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 03:00:04 by jagarcia          #+#    #+#             */
/*   Updated: 2018/02/15 03:24:35 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strinvert(const char *str)
{
	char	*new_str;
	int		len;

	len = ft_strlen(str) - 1;
	new_str = ft_strnew(len + 1);
	while (*str)
		new_str[len--] = *str++;
	return (new_str);
}
