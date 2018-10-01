/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 12:40:31 by jpinyot           #+#    #+#             */
/*   Updated: 2018/09/30 23:07:37 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

static char	*namedotcor(char *av)
{
	char	*r;
	int		len;

	len = ft_strlen(av);
	if (av[len - 1] != 's' || av[len - 2] != '.')
	{
		ft_invalidargv(1, av);
		return (NULL);
	}
	if (!(r = ft_strnew(len + 2)))
		return (NULL);
	r = ft_strcpy(r, av);
	r[len - 1] = 'c';
	r[len] = 'o';
	r[len + 1] = 'r';
	return (r);
}

int			main(int ac, char **av)
{
	int		fd;
	int		sel;
	char	*filename;

	sel = 1;
	if (ac == 1)
		return (ft_invalidargv(0, NULL));
	if (ft_strcmp(av[1], "-a") == 0)
		sel = 2;
	if ((fd = open(av[sel], O_RDONLY)) == -1)
		return (ft_invalidargv(1, av[1]));
	if (!(filename = namedotcor(av[sel])))
		exit(-1);
	if (assembler(fd, filename, sel) == -1)
		exit(-1);
	ft_strdel(&filename);
	close(fd);
	return (0);
}
