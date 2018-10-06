/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_ld.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 12:47:39 by jpinyot           #+#    #+#             */
/*   Updated: 2018/10/06 15:33:59 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

static void	intern_error(int l, int sel)
{
	ft_puterr("\x1B[91mInvalid ld parameters at line ");
	ft_putnerr(l);
	if (sel == 0)
		ft_puterr(":\n\t\x1B[97m-At first parameter.");
	else
		ft_puterr(":\n\t\x1B[97m-At second parameter.");
	ft_puterr("\n\t\x1B[92mUsage:\x1B[97m");
	ft_puterr("\n\t-The first parameter must be direct or indirect.");
	ft_puterr("\n\t-The second parameter must be a register.");
	ft_puterr("\n\t\x1B[92mExample:\x1B[97m\n\t");
	ft_puterr("ld\t%12, r11");
	ft_puterr("\n\e[0m");
	exit(-1);
}

t_line		*ft_add_ld(char *l, int j, int n_line)
{
	t_line	*line;
	int		i;

	if ((i = ft_strcmp_index_jmp(&l[j], "ld")) == -1 || l[i] == 0)
		ft_error_order(n_line, 0, "ld", "ld\t%12, r11");
	i += j;
	line = ft_newline(NULL, 2, l, 2);
	if (l[i] == DIRECT_CHAR)
		i = ft_extract_dir(&line, i + 1, n_line, 0);
	else if (ft_isdigit(l[i]) || l[i] == '-' || l[i] == '+')
		i = ft_extract_ind(&line, i, n_line, 0);
	else if (l[i] == LABEL_CHAR)
		i = ft_extract_ind_label(&line, i, n_line, 0);
	else
		intern_error(n_line, 0);
	if (l[i] == 'r')
		i = ft_extract_reg(&line, i + 1, n_line, 1);
	else
		intern_error(n_line, 1);
	ft_check_for_coments(l, i, n_line);
	return (line);
}