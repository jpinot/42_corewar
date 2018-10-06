/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_header_to_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 13:31:39 by jpinyot           #+#    #+#             */
/*   Updated: 2018/10/06 15:53:24 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

static void	ft_write_empty(int i, int fd)
{
	char a;

	a = 0;
	if (i > 0)
		while (--i > -1)
			write(fd, &a, 1);
}

static void	ft_warning(int l, int sel)
{
	if (sel == 1)
	{
		ft_putstr("\x1B[91mWarning:\033[0m Champions max size exceeded (");
		ft_putnbr(l);
		ft_putstr(" > ");
		ft_putnbr(CHAMP_MAX_SIZE);
		ft_putstr(").\n");
	}
	if (sel == 2)
		ft_putstr("\x1B[91mWarning:\033[0m No champions name.\n");
	if (sel == 3)
		ft_putstr("\x1B[91mWarning:\033[0m No champions comment.\n");
}

void		ft_header_to_file(t_header header, int fd, unsigned int size)
{
	uint32_t a;

	if (size > CHAMP_MAX_SIZE)
		ft_warning(size, 1);
	if (header.prog_name[0] == '"')
		ft_warning(0, 2);
	if (header.comment[0] == '"')
		ft_warning(0, 3);
	a = COREWAR_EXEC_MAGIC;
	ft_invert_bytes(&a, sizeof(uint32_t));
	write(fd, &a, sizeof(uint32_t));
	write(fd, header.prog_name, header.name_size);
	ft_write_empty((PROG_NAME_LENGTH - header.name_size) + 4, fd);
	ft_invert_bytes(&size, 4);
	write(fd, &size, 4);
	write(fd, header.comment, header.comment_size);
	ft_write_empty((COMMENT_LENGTH - header.comment_size) + 4, fd);
	ft_strdel(&header.prog_name);
	ft_strdel(&header.comment);
}
