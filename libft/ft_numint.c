/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 23:35:14 by jagarcia          #+#    #+#             */
/*   Updated: 2018/03/23 23:40:12 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_numint(int *array, int length, int search)
{
	int	i;

	i = 0;
	while (i < length)
	{
		if (array[i] == search)
			return (1);
		i++;
	}
	return (0);
}
