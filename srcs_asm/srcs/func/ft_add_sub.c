/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_sub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 12:59:11 by jpinyot           #+#    #+#             */
/*   Updated: 2018/09/17 15:05:59 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

static void	intern_error(int l, int sel)
{
	ft_putstr("\x1B[91mInvalid sub parameters at line ");
	ft_putnbr(l);
	if (sel == 0)
		ft_putstr(":\n\t\x1B[97m-At first parameter.");
	else if (sel == 1)
		ft_putstr(":\n\t\x1B[97m-At second parameter.");
	else if (sel == 2)
		ft_putstr(":\n\t\x1B[97m-At third parameter.");
	ft_putstr("\n\t\x1B[92mUsage:\x1B[97m");
	ft_putstr("\n\t-The first parameter must be register.");
	ft_putstr("\n\t-The second parameter must be register.");
	ft_putstr("\n\t-The third parameter must be register.");
	ft_putstr("\n\t\x1B[92mExample:\x1B[97m\n\t");
	ft_putstr("sub\tr12, r11, r3");
	exit(-1);
}

t_line		*ft_add_sub(char *l, int j, int n_line)
{
	t_line	*line;
	int		i;

	if ((i = ft_strcmp_index_jmp(&l[j], "sub")) == -1 || l[i] == 0)
		ft_error_order(n_line, 0, "sub", "sub\tr2, r11, r3");
	i += j;
	line = ft_newline(NULL, 5, l, 2);
	if (l[i] == 'r')
		i = ft_extract_reg(&line, i + 1, n_line, 0);
	else
		intern_error(n_line, 0);
	if (l[i] == 'r')
		i = ft_extract_reg(&line, i + 1, n_line, 1);
	else
		intern_error(n_line, 1);
	if (l[i] == 'r')
		i = ft_extract_reg(&line, i + 1, n_line, 2);
	else
		intern_error(n_line, 2);
	ft_check_for_coments(l, i, n_line);
	return (line);
}
