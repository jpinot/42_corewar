/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getorders.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 13:10:29 by jpinyot           #+#    #+#             */
/*   Updated: 2018/10/05 21:17:24 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

static t_line	*get_line(char *l, t_label **label, int i, int n_line)
{
	int		cnt;
	int		j;
	t_line	*line;

	cnt = 0;
	i = ft_jmp_s_t(l, i);
	j = i - 1;
	line = NULL;
	while (l[++j] && l[j] != LABEL_CHAR && l[j] != DIRECT_CHAR && l[j] != ' '
			&& l[j] != '\t' && l[j] != COMMENT_CHAR && l[j] != END_LINE_CHAR)
		cnt += l[j];
	if (l[j] == DIRECT_CHAR || l[j] == ' ' || l[j] == '\t')
	{
		line = ft_add_new_line(l, cnt, i, n_line);
		line->label = label[HASH_SIZE - 1];
	}
	else if (l[j] == 0 || l[j] == COMMENT_CHAR || l[j] == END_LINE_CHAR)
		line = ft_newline(label[HASH_SIZE - 1], 0, l, 0);
	else
		ft_error_getorders(n_line, 0);
	label[HASH_SIZE - 1] = NULL;
	return (line);
}

t_line			*ft_getorders(char *l, t_label **label, int i, int n_line)
{
	int		cnt;
	int		j;

	cnt = 0;
	j = i - 1;
	while (l[++j] && l[j] != LABEL_CHAR &&
			l[j] != DIRECT_CHAR && l[j] != ' ' && l[j] != '\t')
	{
		if (!((l[j] >= 48 && l[j] <= 57) ||
					l[j] == 95 || (l[j] >= 97 && l[j] <= 122)))
			ft_error_label(n_line, 2, &l[i - 1]);
		cnt += l[j];
	}
	if (l[j] && l[j] == LABEL_CHAR)
	{
		label = ft_add_new_label(label, cnt, l, i);
		return (get_line(l, label, j + 1, n_line));
	}
	else if (l[j] && (l[j] == DIRECT_CHAR || l[j] == ' ' || l[j] == '\t'))
		return (ft_add_new_line(l, cnt, i, n_line));
	ft_error_getorders(n_line, 0);
	return (NULL);
}
