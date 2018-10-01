/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 12:53:43 by jagarcia          #+#    #+#             */
/*   Updated: 2018/06/06 02:12:47 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int					cheker(char *tmp, char **m, char **line)
{
	int		i;
	char	*nw;
	char	*tl;

	i = 0;
	if ((nw = ft_strchr(tmp, LINE_SIMBOL)))
	{
		ft_strdel(m);
		if (*(nw + 1))
			*m = ft_strncpy(NEW(ft_strlen(nw) - 1), nw + 1, ft_strlen(nw) - 1);
		i = 1;
	}
	if (*line)
	{
		if (!(tl = NEW(ft_strlen(*line) + ft_strlen(tmp) - ft_strlen(nw) + 1)))
			return (-1);
		ft_strcpy(tl, *line);
	}
	else if (!(tl = ft_strnew(ft_strlen(tmp) - ft_strlen(nw) + 1)))
		return (-1);
	ft_strncat(tl, tmp, ft_strlen(tmp) - ft_strlen(nw));
	ft_strdel(line);
	*line = tl;
	return (i);
}

static int					mikeler(char **mikel, char **line)
{
	char		*mateo;
	int			josep;

	josep = 0;
	mateo = ft_strnew(ft_strlen(*mikel));
	ft_strcpy(mateo, *mikel);
	ft_strdel(mikel);
	if ((josep = cheker(mateo, mikel, line)) < 0)
		return (-1);
	ft_strdel(&mateo);
	return (josep);
}

static int					reader(char *tmp, int fd, char **line, char **mikel)
{
	int		gonz;

	ft_memset(tmp, '\0', BUFF_SIZE + 1);
	gonz = read(fd, tmp, BUFF_SIZE);
	if (!gonz)
	{
		if (!*line)
			return (0);
		else
			return (1);
	}
	else if (gonz < 0)
		return (-1);
	if ((gonz = cheker(tmp, mikel, line)) < 0)
		return (-1);
	return (gonz);
}

static void					newmikel(int fd, t_fd **mikel, t_fd **aux)
{
	if (!*mikel)
	{
		*mikel = (t_fd *)ft_memalloc(sizeof(t_fd));
		(*mikel)->fd = fd;
		(*mikel)->buffer = NULL;
		(*mikel)->next = NULL;
	}
	*aux = *mikel;
	while ((*mikel)->next && (*mikel)->fd != fd)
		*mikel = (*mikel)->next;
	if (!((*mikel)->next) && (*mikel)->fd != fd)
	{
		(*mikel)->next = (t_fd *)ft_memalloc(sizeof(t_fd));
		*mikel = (*mikel)->next;
		(*mikel)->fd = fd;
		(*mikel)->buffer = NULL;
		(*mikel)->next = NULL;
	}
}

int							get_next_line(const int fd, char **line)
{
	char			tmp[BUFF_SIZE + 1];
	int				gonz;
	static t_fd		*mikel = NULL;
	t_fd			*aux;

	if (fd < 0 || !line)
		return (-1);
	newmikel(fd, &mikel, &aux);
	gonz = 0;
	*line = NULL;
	if (mikel->buffer)
		if ((gonz = mikeler(&(mikel->buffer), line)) < 0)
			return (-1);
	while (!gonz)
	{
		gonz = reader(tmp, mikel->fd, line, &(mikel->buffer));
		if (gonz < 0)
			return (gonz);
		if (gonz == 0 && !*line)
			return (gonz);
	}
	mikel = aux;
	return (1);
}
