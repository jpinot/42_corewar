/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cutstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <jagarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 18:23:20 by jagarcia          #+#    #+#             */
/*   Updated: 2018/02/19 12:27:03 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcut(char *str, int start, int end)
{
	char	*new;

	if (!str)
		return (NULL);
	if (end <= start || start < 0 || end < 0)
		return (str);
	if (!(new = ft_strnew(ft_strlen(str) - (end - start))) || !str)
		return (NULL);
	ft_strncpy(new, str, start);
	ft_strcat(new, str + end);
	return (new);
}
