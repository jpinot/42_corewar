/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 18:46:04 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/10/05 17:25:26 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "basic_corewar.h"

static unsigned char	take_player_nb(const unsigned int n_player, const char *str, t_flag_value *f_value)
{
	int32_t				num;

	if (ft_issdigit((char *)str))
		num = ft_atoi(str);
	else
		ft_error("Error: number player is not only numbers\n");
	if (n_player < MAX_PLAYERS)
		f_value->player_nb[n_player] = num;
	return (2);
}

int						set_flags(const unsigned int n_player, const char **av, unsigned int *flags, t_flag_value *f_value)
{
	unsigned char i;
	unsigned char ret;

	i = 1;
	ret = 1;
	while (av[0][i])
	{
		if (av[0][i] == 'v')//visualicer
			*flags |= 0x1;
		else if (av[0][i] == 'f')//fullscreen
			*flags |= 0x2;
		else if (av[0][i] == 'i')//instructions
			*flags |= 0x4;
		else if (av[0][i] == 'd')//deaths
			*flags |= 0x8;
		else if (av[0][i] == 'n')//number
			ret = take_player_nb(n_player, av[1], f_value);
		else
			ft_error("Error: invalid flag.\n");
		i++;
	}
	return (ret);
}
