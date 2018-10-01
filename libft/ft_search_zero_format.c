/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_zero_format.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 02:47:28 by jagarcia          #+#    #+#             */
/*   Updated: 2018/02/17 03:51:08 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_search_zero_format(char *command)
{
	while (*command)
	{
		if (ft_isdigit(*command) && *command != '0')
			return (0);
		if (*command == '.')
			return (0);
		if (*command == '0')
			return (1);
		command++;
	}
	return (0);
}
