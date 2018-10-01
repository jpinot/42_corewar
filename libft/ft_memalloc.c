/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 23:40:49 by jagarcia          #+#    #+#             */
/*   Updated: 2017/11/14 18:20:10 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*box;
	char	*cpy;
	size_t	i;

	i = 0;
	box = (void *)malloc(size);
	if (box == NULL)
		return (NULL);
	while (i < size)
		box[i++] = 0;
	cpy = box;
	return ((void *)cpy);
}
