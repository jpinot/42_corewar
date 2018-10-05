/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_label.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 17:43:38 by jpinyot           #+#    #+#             */
/*   Updated: 2018/10/05 17:43:40 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

static void	ft_puterr_dot(char *s)
{
	int i;

	i = -1;
	while (s[++i] && s[i] != LABEL_CHAR && s[i] != ' '
			&& s[i] != '\t' && s[i] != SEPARATOR_CHAR &&
			s[i] != END_LINE_CHAR && s[i] != COMMENT_CHAR)
		write(2, &s[i], 1);
}

static void	label_copy(char *s)
{
	ft_puterr("\x1B[91mInvalid label identifier:");
	ft_puterr("\n\t\x1B[92mUsage:\x1B[97m");
	ft_puterr("\n\t-Each label identifier must be unique.");
	ft_puterr("\n\t-Identifier \"");
	ft_puterr_dot(s);
	ft_puterr("\" is repeated.");
}

static void	label_not_found(char *s)
{
	ft_puterr("\x1B[91mInvalid label identifier:");
	ft_puterr("\n\t\x1B[92mUsage:\x1B[97m");
	ft_puterr("\n\t-Label identifier \"");
	ft_puterr_dot(&s[1]);
	ft_puterr("\" have not been found.");
}

static void	label_invalid_char(char *s)
{
	ft_puterr("\x1B[91mInvalid label identifier:");
	ft_puterr("\n\t\x1B[92mUsage:\x1B[97m");
	ft_puterr("\n\t-Label identifier \"");
	ft_puterr_dot(&s[1]);
	ft_puterr("\" have non valid characters.\n\t-Valid characters are: \"");
	ft_puterr(LABEL_CHARS);
	ft_puterr("\".");
}

void		ft_error_label(int l, int sel, char *s)
{
	l++;
	if (sel == 0)
		label_copy(s);
	if (sel == 1)
		label_not_found(s);
	if (sel == 2)
		label_invalid_char(s);
	exit(-1);
}
