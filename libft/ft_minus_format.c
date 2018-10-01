/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minus_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 20:28:34 by jagarcia          #+#    #+#             */
/*   Updated: 2018/02/21 20:33:48 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_minus_format(char *command)
{
	int		i;

	i = 0;
	while (command[i])
	{
		if (command[i] == '-' && i >= 0 && command[i - 1] != '.')
			return (1);
		i++;
	}
	return (0);
}
