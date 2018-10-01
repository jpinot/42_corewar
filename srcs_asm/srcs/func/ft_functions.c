/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 13:08:50 by jpinyot           #+#    #+#             */
/*   Updated: 2018/09/25 17:43:14 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

void	ft_check_for_coments(char *l, int i, int n_line)
{
	while (l[i] && (l[i] == ' ' || l[i] == '\t'))
		i++;
	if (l[i] != 0 && l[i] != COMMENT_CHAR && l[i] != END_LINE_CHAR)
		ft_error_order(n_line, 1, NULL, NULL);
}

int		ft_jmp_s_t(char *s, int i)
{
	while (s[i] == ' ' || s[i] == '\t')
		i++;
	return (i);
}

int		ft_hash_it(int id, int range)
{
	id = id % range;
	return (id);
}
