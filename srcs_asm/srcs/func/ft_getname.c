/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getname.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 13:09:32 by jpinyot           #+#    #+#             */
/*   Updated: 2018/10/01 15:07:23 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

static char		*ft_strtabspace(char *s, int j)
{
	int i;

	i = j;
	while (s[i] && (s[i] == '\t' || s[i] == ' '))
		i++;
	if (s[i] != '"')
		return (NULL);
	return (&s[i + 1]);
}

static int		ft_check_for_comm(char *s)
{
	int i;
	int	ret;

	i = 0;
	while (s[i] && s[i] != '\"')
		i++;
	if (s[i] == 0)
		return (-1);
	i++;
	ret = i;
	while (s[i] && (s[i] == ' ' || s[i] == '\t'))
		i++;
	if (s[i] == 0 || s[i] == COMMENT_CHAR || s[i] == END_LINE_CHAR)
		return (ret);
	return (-1);
}

static t_header	ft_header_name(char *l, int n_l, int i, t_header h)
{
	char	*tmp;
	int		j;
	int		end;

	if (!(tmp = ft_strtabspace(l, i)))
		ft_error_getname(n_l, 1);
	if ((j = ft_check_for_comm(tmp)) > (PROG_NAME_LENGTH + 1) || j < 0)
		ft_error_getname(n_l, 2);
	h.prog_name = tmp;
	h.name_size = j - 1;
	h.name_line = l;
	return (h);
}

static t_header	ft_header_comment(char *l, int n_l, int i, t_header h)
{
	char	*tmp;
	int		j;

	if (!(tmp = ft_strtabspace(l, i)))
		ft_error_getname(n_l, -1);
	if ((j = ft_check_for_comm(tmp)) > (COMMENT_LENGTH + 1) || j < 0)
		ft_error_getname(n_l, -2);
	h.comment = tmp;
	h.comment_size = j - 1;
	h.comment_line = l;
	return (h);
}

t_header		ft_getname(char *line, int n_line, t_header h)
{
	int		i;
	int		j;

	j = 0;
	while (line[j] && (line[j] == ' ' || line[j] == '\t'))
		j++;
	if ((i = ft_strcmp_index(&line[j], NAME_CMD_STRING)) != -1)
		h = ft_header_name(line, n_line, i + j, h);
	else if ((i = ft_strcmp_index(&line[j], COMMENT_CMD_STRING)) != -1)
		h = ft_header_comment(line, n_line, i + j, h);
	else if (line[j] != COMMENT_CHAR && line[j] != END_LINE_CHAR)
		ft_error_getname(n_line, 0);
	else
		ft_strdel(&line);
	return (h);
}
