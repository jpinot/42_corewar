/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_invalidargv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 12:38:26 by jpinyot           #+#    #+#             */
/*   Updated: 2018/09/17 12:38:32 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

int	ft_invalidargv(int sel, char *s)
{
	if (sel == 0)
	{
		write(1, "Usage: ./asm [-a] <sourcefile.s>\n", 33);
		write(1, "\t-a : Instead of creating a .cor file, ", 39);
		write(1, "outputs a stripped and annotated version ", 41);
		write(1, "of the code to the standard output", 34);
	}
	if (sel == 1)
	{
		write(1, "Can't read source file ", 23);
		ft_putstr(s);
	}
	return (0);
}
