/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_ind.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 13:04:43 by jpinyot           #+#    #+#             */
/*   Updated: 2018/09/30 21:46:06 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

static int	ft_jmp_to_next(char *l, int i)
{
	while (l[i] && (l[i] == ' ' || l[i] == '\t'))
		i++;
	if (l[i] != SEPARATOR_CHAR && l[i] != 0 &&
			l[i] != COMMENT_CHAR && l[i] != END_LINE_CHAR)
		return (-1);
	if (l[i] == 0 || l[i] == COMMENT_CHAR || l[i] == END_LINE_CHAR)
		return (i);
	i++;
	while (l[i] && (l[i] == ' ' || l[i] == '\t'))
		i++;
	return (i);
}

static int	ft_set_ocp(int pos, int ocp)
{
	if (pos == 0)
		ocp = ocp | 0b11000000;
	else if (pos == 1)
		ocp = ocp | 0b00110000;
	else
		ocp = ocp | 0b00001100;
	return (ocp);
}

int			ft_extract_ind(t_line **line, int i, int n_line, int pos)
{
	if (line[0]->line[i] == 0 || line[0]->line[i] == SEPARATOR_CHAR)
		ft_error_par(n_line, 0, "indirect", "142,");
	line[0]->arg_size[pos] = IND_SIZE;
	line[0]->ocp = ft_set_ocp(pos, line[0]->ocp);
	i = ft_atoi_asm(line[0]->line, i, &line[0]->arg[pos]);
	if ((i = ft_jmp_to_next(line[0]->line, i)) == -1)
		ft_error_par(n_line, 0, "indirect", "142,");
	line[0]->w += IND_SIZE;
	return (i);
}
