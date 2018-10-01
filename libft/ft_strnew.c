/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 23:40:49 by jagarcia          #+#    #+#             */
/*   Updated: 2017/11/16 09:53:42 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*box;
	char	*cpy;
	size_t	i;

	i = 0;
	box = (void *)malloc(size + 1);
	if (box == NULL)
		return (NULL);
	while (i < size)
		box[i++] = 0;
	box[i] = 0;
	cpy = box;
	return (cpy);
}
