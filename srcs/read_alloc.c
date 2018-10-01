/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_alloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 13:33:36 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/09/25 16:20:39 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "basic_corewar.h"

char	*read_alloc(int fd, const size_t size)
{
	char *str;

	if (!(str = (char *)malloc(sizeof(char) * size)))
		ft_error("malloc failed in read_alloc.");
	if ((read(fd, str, size)) < 0)
		ft_error("read failed in read_alloc.");
	return (str);
}
