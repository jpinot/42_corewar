/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 13:08:50 by jpinyot           #+#    #+#             */
/*   Updated: 2018/10/03 15:15:39 by jpinyot          ###   ########.fr       */
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

char	*ft_strjoin_n(char *s1, char *s2, int j, char *l)
{
	char	*new;
	int		len1;

	if (s1 && s2)
	{
		len1 = ft_strlen(s1);
		if (!(new = ft_strnew(len1 + j + 2)))
			exit(1);
		ft_memcpy(new, s1, len1);
		ft_strcat(new, s2);
		if (s2[j] != '\"')
			new[len1 + j] = '\n';
		ft_strdel(&s1);
	}
	else
	{
		len1 = ft_strlen(s2);
		if (!(new = ft_strnew(len1 + 2)))
			exit(1);
		ft_memcpy(new, s2, len1);
		if (s2[j] != '\"')
			new[len1] = '\n';
	}
	ft_strdel(&l);
	return (new);
}
