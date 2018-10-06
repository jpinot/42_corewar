/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mod.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 15:01:05 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/10/04 01:00:51 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "basic_corewar.h"

int	ft_mod(const int nb, const unsigned int mod)
{
	int aux;

	if (nb >= 0)
		return (nb % mod);
	else
	{
		aux = nb + mod;
		while (aux < 0)
			aux = aux + mod;
	}
	return (aux);
}
