/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_header_to_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 13:31:39 by jpinyot           #+#    #+#             */
/*   Updated: 2018/09/19 14:02:20 by jpinyot          ###   ########.fr       */
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

void		ft_header_to_file(t_header header, int fd, unsigned int size)
{
	uint32_t a;

	a = COREWAR_EXEC_MAGIC;
	ft_invert_bytes(&a, sizeof(uint32_t));
	write(fd, &a, sizeof(uint32_t));
	write(fd, header.prog_name, header.name_size);
	ft_write_empty((PROG_NAME_LENGTH - header.name_size) + 4, fd);
	ft_invert_bytes(&size, 4);
	write(fd, &size, 4);
	write(fd, header.comment, header.comment_size);
	ft_write_empty((COMMENT_LENGTH - header.comment_size) + 4, fd);
	ft_strdel(&header.name_line);
	ft_strdel(&header.comment_line);
}
