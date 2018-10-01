/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 20:32:35 by jagarcia          #+#    #+#             */
/*   Updated: 2017/11/21 01:58:48 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		func_while(const char *s, int j, char c, char ***new2)
{
	int		i[2];
	int		cont;

	i[1] = 0;
	while (j--)
	{
		i[0] = 0;
		cont = 0;
		while (*s == c && ((*(s + 1) == c) || (*(s + 1) != '\0')))
			s++;
		while (s[i[0]] != c && s[i[0]++] != '\0')
			cont++;
		if (!(new2[0][i[1]++] = ft_strsub(s, 0, cont)))
		{
			free(*new2);
			*new2 = NULL;
			return ;
		}
		while (cont-- > 0)
			s++;
	}
	new2[0][i[1]] = (void *)NULL;
}

char			**ft_strsplit(char const *s, char c)
{
	char	**new;
	int		cuant;
	int		i;

	if (s == NULL)
		return (NULL);
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
		if (!(new = (char **)malloc(sizeof(char *))))
			return (NULL);
		new[0] = NULL;
		return (new);
	}
	if (!(new = (char **)malloc(sizeof(char *) * (cuant + 1))))
		return (NULL);
	func_while(s, cuant, c, &new);
	return (new);
}
