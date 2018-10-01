/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_pos_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 06:55:23 by jagarcia          #+#    #+#             */
/*   Updated: 2017/11/24 07:08:22 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sort_pos_int(int *arr)
{
	int				min;
	unsigned int	i;

	while (*arr >= 0)
	{
		i = 1;
		while (arr[i] >= 0)
		{
			if (arr[i] < *arr)
			{
				min = arr[i];
				arr[i] = *arr;
				*arr = min;
			}
			i++;
		}
		arr++;
	}
}
