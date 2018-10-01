/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 15:28:40 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/09/25 16:20:41 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "basic_corewar.h"

static void	cast_value(const unsigned int pos, const unsigned char prev_siz, t_arg *arg)
{
	if (arg->len == 1)
		*((int8_t *)(arg->arg)) = *((int8_t *)(g_mem + pos + 2 + prev_siz));
	else if (arg->len == 2)
		*((int16_t *)(arg->arg)) = *((int16_t *)(g_mem + pos + 2 + prev_siz));
	else if (arg->len == 4)
		*((int32_t *)(arg->arg)) = *((int32_t *)(g_mem + pos + 2 + prev_siz));
	else if (arg->len == 8)
		*((int64_t *)(arg->arg)) = *((int64_t *)(g_mem + pos + 2 + prev_siz));
}

void		get_arg(const unsigned char ocp, const unsigned int pos, const unsigned char prev_siz, t_arg *arg)
{
	unsigned char i;

	if (!(arg->len = get_size_arg(ocp, arg->n_arg, arg->dir_size)))
		return ;
	arg->type = (ocp & (0xC0 >> (2 * arg->n_arg))) >> (2 * (3 - arg->n_arg));
	ft_memset(arg->arg, 0, MAX_ARG_LEN);
	if ((pos + 2 + prev_siz + arg->len) < MEM_SIZE)
		cast_value(pos, prev_siz, arg);
	else
	{
		i = 0;
		while (i < arg->len)
		{
			arg->arg[i] = g_mem[(pos + 2 + prev_siz + i) % MEM_SIZE];
			i++;
		}
	}
}
