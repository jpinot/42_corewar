/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apostrophe_format.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 01:35:25 by jagarcia          #+#    #+#             */
/*   Updated: 2018/02/12 14:58:49 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	cuantity(char *variable)
{
	size_t len;

	len = ft_strlen(variable);
	if (len % 3)
		return (len + len / 3 - 1);
	else
		return (len + len / 3 - 2);
}

static char	*add_comas(char *variable)
{
	int		j;
	int		i;
	char	*var_head;
	char	*new_variab;

	i = cuantity(variable);
	if (!(new_variab = ft_strnew(i)))
		return (NULL);
	var_head = variable;
	variable += ft_strlen(variable) - 1;
	j = 0;
	while (i >= 0)
	{
		new_variab[i--] = *variable--;
		if (variable < var_head)
			break ;
		j++;
		if (!(j % 3))
			new_variab[i--] = ',';
	}
	return (new_variab);
}

static char	*point(char *variable, int *siz_cuant)
{
	char	*new_variab;
	char	*varia_part;
	size_t	len;

	len = ft_strlen(new_variab);
	varia_part = ft_strsub(variable, 0, ft_strchr(variable, '.') - variable);
	varia_part = add_comas(varia_part);
	new_variab = ft_strjoin(varia_part, ft_strchr(variable, '.'));
	ft_strdel(&variable);
	ft_strdel(&varia_part);
	if ((unsigned long)siz_cuant[0] < len)
		siz_cuant[0] = len;
	return (new_variab);
}

char		*ft_apostrophe_format(char *comm, char *variable, int *siz_cuant)
{
	int t;

	t = ft_toupper(comm[ft_strlen(comm) - 1]);
	if (!(ft_strchr(comm, '\'')))
		return (variable);
	if (t == 'F' || t == 'G' || t == 'E')
		return (point(variable, siz_cuant));
	return (add_comas(variable));
}
