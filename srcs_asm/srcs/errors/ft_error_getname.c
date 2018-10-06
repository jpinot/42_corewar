/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_getname.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 17:44:22 by jpinyot           #+#    #+#             */
/*   Updated: 2018/10/05 17:44:24 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

static void	none_name_comm(int l)
{
	ft_puterr("\x1B[91mSyntax error at line ");
	ft_putnerr(l);
	ft_puterr(":\n\t\x1B[92mUsage:\x1B[97m");
	ft_puterr("\n\t-The program name and the comment ");
	ft_puterr("must be placed at the beginning of the champions file.");
	ft_puterr("\n\t\x1B[92mExample:\x1B[97m\n\t");
	ft_puterr(NAME_CMD_STRING);
	ft_puterr(" \"Program name here\"\n\t");
	ft_puterr(COMMENT_CMD_STRING);
	ft_puterr(" \"Program comment here\"\n\x1B[37m");
}

static void	none_quatation_name(int l)
{
	ft_puterr("\x1B[91mSyntax error at line ");
	ft_putnerr(l);
	ft_puterr(".\n\t\x1B[92mUsage:\x1B[97m");
	ft_puterr("\n\t-The program name need to be between quatation marks [\"].");
	ft_puterr("\n\t\x1B[92mExample:\x1B[97m\n\t");
	ft_puterr(" \"HAL9000\"\n\n\x1B[37m");
}

static void	none_quatation_comm(int l)
{
	ft_puterr("\x1B[91mSyntax error at line ");
	ft_putnerr(l);
	ft_puterr(".\n\t\x1B[92mUsage:\x1B[97m");
	ft_puterr("\n\t-The comment need to be between quatation marks [\"].");
	ft_puterr("\n\t\x1B[92mExample:\x1B[97m\n\t");
	ft_puterr(" \"Dave, I'm afraid I can't let you do that...\"\n\n\x1B[37m");
}

static void	bigger_length(int l, int sel)
{
	ft_puterr("\x1B[91mError in line ");
	ft_putnerr(l);
	ft_putchar(':');
	if (sel == 1)
	{
		ft_puterr("\n\x1B[97mChampion name too long (Max length ");
		ft_putnerr(PROG_NAME_LENGTH);
		ft_puterr(")\n\x1B[37m");
	}
	if (sel == 2)
	{
		ft_puterr("\n\x1B[97mChampion comment too long (Max length ");
		ft_putnerr(COMMENT_LENGTH);
		ft_puterr(")\n\x1B[37m");
	}
}

void		ft_error_getname(int l, int sel)
{
	if (sel == 0)
		none_name_comm(l);
	else if (sel > 0)
	{
		if (sel == 1)
			none_quatation_name(l);
		if (sel == 2)
			bigger_length(l, 1);
	}
	else if (sel < 0)
	{
		if (sel == -1)
			none_quatation_comm(l);
		if (sel == -2)
			bigger_length(l, 2);
	}
	exit(-1);
}
