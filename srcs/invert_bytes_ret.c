/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invert_bytes_ret.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 13:41:53 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/09/29 13:49:02 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "basic_corewar.h"

long		invert_bytes_ret(const long num, const size_t size)
{
	long arr;

	arr = num;
	if (size == 1)
		return (arr);
	else if (size == 2)
		arr = (long)((((uint16_t)arr >> 8) & 0x00FF) |
		                      (((uint16_t)arr << 8) & 0xFF00));
	else if (size == 4)
		arr = (long)((((uint32_t)arr >> 24) & 0x000000FF) |
		                      (((uint32_t)arr >> 8) & 0x0000FF00) |
		                      (((uint32_t)arr << 8) & 0x00FF0000) |
		                      (((uint32_t)arr << 24) & 0xFF000000));
	else if (size == 8)
		arr = (long)
			(((((uint64_t)arr >> 56) & 0x00000000000000FF)) |
		    ((((uint64_t)arr >> 40) & 0x000000000000FF00)) |
            ((((uint64_t)arr >> 24) & 0x0000000000FF0000)) |
            ((((uint64_t)arr >> 8) & 0x00000000FF000000)) |
            ((((uint64_t)arr << 8) & 0x000000FF00000000)) |
            ((((uint64_t)arr << 24) & 0x0000FF0000000000)) |
            ((((uint64_t)arr << 40) & 0x00FF0000000000)) |
            ((((uint64_t)arr << 56) & 0xFF000000000000)));
	return (arr);
}
