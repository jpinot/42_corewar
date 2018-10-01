/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invert_bytes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 14:37:56 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/09/25 16:20:40 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "basic_corewar.h"

static void generic_case(void *arr, const size_t size)
{
	char 	*c_arr;
	char 	aux;
	size_t	i;

	c_arr = (char *)arr;
	i = 0;
	while (i < size / 2)
	{
		aux = c_arr[i];
		c_arr[i] = c_arr[size - i -1];
		c_arr[size - i -1] = aux;
		i++;
	}
}

void		invert_bytes(void *arr, const size_t size)
{
	if (size == 1)
		return ;
	else if (size == 2)
		*((uint16_t *)arr) = (((*((uint16_t *)arr) >> 8) & 0x00FF) |
		                      ((*((uint16_t *)arr) << 8) & 0xFF00));
	else if (size == 4)
		*((uint32_t *)arr) = (((*((uint32_t *)arr) >> 24) & 0x000000FF) |
		                      ((*((uint32_t *)arr) >> 8) & 0x0000FF00) |
		                      ((*((uint32_t *)arr) << 8) & 0x00FF0000) |
		                      ((*((uint32_t *)arr) << 24) & 0xFF000000));
	else if (size == 8)
		*((uint64_t *)arr) =
			((((*((uint64_t *)arr) >> 56) & 0x00000000000000FF)) |
		    (((*((uint64_t *)arr) >> 40) & 0x000000000000FF00)) |
            (((*((uint64_t *)arr) >> 24) & 0x0000000000FF0000)) |
            (((*((uint64_t *)arr) >> 8) & 0x00000000FF000000)) |
            (((*((uint64_t *)arr) << 8) & 0x000000FF00000000)) |
            (((*((uint64_t *)arr) << 24) & 0x0000FF0000000000)) |
            (((*((uint64_t *)arr) << 40) & 0x00FF0000000000)) |
            (((*((uint64_t *)arr) << 56) & 0xFF000000000000)));
	else
		generic_case(arr, size);
}
