/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_label.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 12:35:49 by jpinyot           #+#    #+#             */
/*   Updated: 2018/10/01 16:02:04 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

static void	ft_putstr_dot(char *s)
{
	int i;

	i = -1;
	while (s[++i] && s[i] != LABEL_CHAR && s[i] != ' '
			&& s[i] != '\t' && s[i] != SEPARATOR_CHAR)
		write(1, &s[i], 1);
}

static void	label_copy(char *s)
{
	ft_putstr("\x1B[91mInvalid label identifier:");
	ft_putstr("\n\t\x1B[92mUsage:\x1B[97m");
	ft_putstr("\n\t-Each label identifier must be unique.");
	ft_putstr("\n\t-Identifier \"");
	ft_putstr_dot(s);
	ft_putstr("\" is repeated.");
}

static void	label_not_found(char *s)
{
	ft_putstr("\x1B[91mInvalid label identifier:");
	ft_putstr("\n\t\x1B[92mUsage:\x1B[97m");
	ft_putstr("\n\t-Label identifier \"");
	ft_putstr_dot(&s[1]);
	ft_putstr("\" have not been found.");
}

static void	label_invalid_char(char *s)
{
	ft_putstr("\x1B[91mInvalid label identifier:");
	ft_putstr("\n\t\x1B[92mUsage:\x1B[97m");
	ft_putstr("\n\t-Label identifier \"");
	ft_putstr_dot(&s[1]);
	ft_putstr("\" have non valid characters.\n\t-Valid characters are: \"");
	ft_putstr(LABEL_CHARS);
	ft_putstr("\".");
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
