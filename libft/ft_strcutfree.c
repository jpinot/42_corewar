/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cutstrfree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <jagarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 21:09:27 by jagarcia          #+#    #+#             */
/*   Updated: 2018/02/19 12:29:07 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcutfree(char *str, int start, int end)
{
	char	*new;

	if (!str)
		return (NULL);
	if (end <= start || end < 0 || start < 0)
		return (str);
	if (!(new = ft_strnew(ft_strlen(str) - (end - start))) || !str)
		return (NULL);
	ft_strncpy(new, str, start);
	ft_strcat(new, str + end);
	ft_strdel(&str);
	return (new);
}
