/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 19:12:49 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/10/05 17:21:41 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "basic_corewar.h"

static char				check_file(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	if (i < 4 || str[i - 4] != '.' || str[i - 3] != 'c' || str[i - 2] != 'o' || str[i - 1] != 'r')
		return (0);
	return(1);
}
static uint32_t			count_players(const int ac, const char **av, unsigned int *flags, t_flag_value *f_value)
{
	unsigned char	i;
	uint32_t	rtn;

	i = 1;
	rtn = 0;
	while (i < ac && i < 25)
	{
		if (av[i][0] == '-' && av[i][1] == 'n' && (ac - i) > 1)
			i += set_flags(0xFF & rtn, av + i, flags, f_value);
		else if (av[i][0] == '-' && av[i][1] != 'n')
			i += set_flags(0, av + i, flags, f_value);
		else if (check_file(av[i]))
		{
			rtn = rtn | (0x80000000 >> (i - 1));
			rtn++;
			i++;
		}
		else
			ft_error("Corewar: \033[38;5;208mInvalid input.\033[0m\n");
	}
	if ((rtn & 0xFF) > MAX_PLAYERS)
		ft_error("Error: Too much players\n");
	return(rtn);
}
void					take_input(const int ac, const char **av, unsigned int *flags, t_flag_value *f_value)
{
	unsigned char 	i;
	uint32_t		player_pos;

	i = 1;
	if (!(player_pos = count_players(ac, av, flags, f_value)))
		ft_error("Error: No players found\n");
	g_n_players = player_pos & 0xFF;
	while (i < ac && i < 25)
	{
		if (player_pos & (0x80000000 >> (i - 1)))
			init_player(av[i], f_value);
		i++;
	}
}
