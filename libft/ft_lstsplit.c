/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 20:32:35 by jagarcia          #+#    #+#             */
/*   Updated: 2017/11/18 08:09:11 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		func_while2(const char **s, char c)
{
	int cont;
	int i;

	i = 0;
	cont = 0;
	while (**s == c && ((*(*s + 1) == c) || (*(*s + 1) != '\0')))
		(*s)++;
	while (s[0][i] != c && s[0][i++] != '\0')
		cont++;
	return (cont);
}

static t_list	*func_while(const char *s, int j, char c)
{
	int		cont;
	t_list	*mylist;
	t_list	*tmp;

	mylist = NULL;
	while (j--)
	{
		cont = func_while2(&s, c);
		if (!mylist)
		{
			if (!(mylist = ft_lstnew(ft_strsub(s, 0, cont), cont)))
				return (NULL);
			tmp = mylist;
		}
		else
		{
			if (!(tmp = ft_lstnext(tmp, tmp, ft_strsub(s, 0, cont), cont)))
				return (NULL);
		}
		while (cont-- > 0)
			s++;
	}
	return (mylist);
}

t_list			*ft_lstsplit(char const *s, char c)
{
	t_list	*mylist;
	int		cuant;
	int		i;

	if (s == NULL)
		return (ft_lstnew(NULL, 0));
	cuant = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			cuant++;
		i++;
	}
	if (cuant == 0)
	{
		if (!(mylist = ft_lstnew("", 0)))
			return (NULL);
		return (mylist);
	}
	mylist = func_while(s, cuant, c);
	return (mylist);
}
