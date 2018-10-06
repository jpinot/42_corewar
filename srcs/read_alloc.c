/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_alloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 13:33:36 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/10/02 15:59:52 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "basic_corewar.h"

char	*read_alloc(int fd, const size_t size)
{
	char	*str;
	int		rd;

	if (!(str = (char *)malloc(sizeof(char) * size)))
	{
		close(fd);
		ft_error("Error: malloc failed in read_alloc.\n");
	}
	if ((rd = read(fd, str, size)) < 0)
	{
		close(fd);
		ft_error("Error: read failed in read_alloc.\n");
	}
	if ((size_t)rd != size)
	{
		close(fd);
		ft_error("Error: file does not meet the standards\n");
	}
	return (str);
}
