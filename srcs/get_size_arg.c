/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_size_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 17:03:16 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/09/25 16:20:40 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "basic_corewar.h"

unsigned char	get_size_arg(const unsigned char ocp, const unsigned char n_arg, const unsigned int dir_size)
{
	unsigned char type;

	type = (ocp & (0xC0 >> (2 * n_arg))) >> (2 * (3 - n_arg));
	if (type == REG_CODE)
		return (1);
	if (type == DIR_CODE)
		return (dir_size ? DIR_SIZE : IND_SIZE);
	if (type == IND_CODE)
		return (IND_SIZE);
	else
		return (0);
}
