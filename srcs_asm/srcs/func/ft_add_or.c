/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_or.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 12:55:18 by jpinyot           #+#    #+#             */
/*   Updated: 2018/09/17 15:05:17 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

static void	intern_error(int l, int sel)
{
	ft_putstr("\x1B[91mInvalid or parameters at line ");
	ft_putnbr(l);
	if (sel == 0)
		ft_putstr(":\n\t\x1B[97m-At first parameter.");
	else if (sel == 1)
		ft_putstr(":\n\t\x1B[97m-At second parameter.");
	else
		ft_putstr(":\n\t\x1B[97m-At third parameter.");
	ft_putstr("\n\t\x1B[92mUsage:\x1B[97m");
	ft_putstr("\n\t-The first parameter must be direct, ");
	ft_putstr("indirect or reguister.");
	ft_putstr("\n\t-The second parameter must be direct, ");
	ft_putstr("indirect or reguister.");
	ft_putstr("\n\t-The third parameter must be a register.");
	ft_putstr("\n\t\x1B[92mExample:\x1B[97m\n\t");
	ft_putstr("or\tr2,r2,r2");
	exit(-1);
}

static int	extract_second_par(char *l, t_line **line, int i, int n_line)
{
	if (l[i] == DIRECT_CHAR)
		i = ft_extract_dir(line, i + 1, n_line, 1);
	else if (ft_isdigit(l[i]) || l[i] == '-' || l[i] == '+')
		i = ft_extract_ind(line, i, n_line, 1);
	else if (l[i] == LABEL_CHAR)
		i = ft_extract_ind_label(line, i, n_line, 1);
	else if (l[i] == 'r')
		i = ft_extract_reg(line, i + 1, n_line, 1);
	else
		intern_error(n_line, 1);
	return (i);
}

t_line		*ft_add_or(char *l, int j, int n_line)
{
	t_line	*line;
	int		i;

	if ((i = ft_strcmp_index_jmp(&l[j], "or")) == -1 || l[i] == 0)
		ft_error_order(n_line, 0, "or", "or\tr2,r2,r2");
	i += j;
	line = ft_newline(NULL, 7, l, 2);
	if (l[i] == DIRECT_CHAR)
		i = ft_extract_dir(&line, i + 1, n_line, 0);
	else if (ft_isdigit(l[i]) || l[i] == '-' || l[i] == '+')
		i = ft_extract_ind(&line, i, n_line, 0);
	else if (l[i] == LABEL_CHAR)
		i = ft_extract_ind_label(&line, i, n_line, 0);
	else if (l[i] == 'r')
		i = ft_extract_reg(&line, i + 1, n_line, 0);
	else
		intern_error(n_line, 0);
	i = extract_second_par(l, &line, i, n_line);
	if (l[i] == 'r')
		i = ft_extract_reg(&line, i + 1, n_line, 2);
	else
		intern_error(n_line, 2);
	ft_check_for_coments(l, i, n_line);
	return (line);
}
