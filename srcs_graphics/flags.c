/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 05:26:38 by jagarcia          #+#    #+#             */
/*   Updated: 2018/09/10 15:07:32 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

static void		check_player_nb(int argn, char **argv, t_data *data, int *i)
{
	if (argv[i[0]][1] == 'n')
	{
		i[0]++;
		if (i[0] < argn)
		{
			if (!(data->dump = ft_atoi(argv[i[0]])))
				ft_error("Can't read source file -n\n");
		}
		else
			ft_error("Can't read source file -n\n");
		// i[0]++;
	}
}

static void		check_dump(int argn, char **argv, t_data *data, int *i)
{
	if (argv[i[0]][1] == 'd')
	{
		i[0]++;
		if (i[0] < argn)
		{
			if (!(data->mods->dump_cuant = ft_atoi(argv[i[0]])))
				ft_error("Can't read source file -d\n");
		}
		else
			ft_error("Can't read source file -d\n");
		// i[0]++;
	}
	else
		check_player_nb(argn, argv, data, i);
}

int				ft_set_flags(int argn, char **argv, t_data *data)
{
	int	i[2];
	int	flag;

	flag = 0;
	i[0] = 1;
	if (!(data->mods = (t_mods *)ft_memalloc(sizeof(t_mods))))
		ft_error("Error malloc ini_mods\n");
	while (i[0] < argn)
	{
		i[1] = 0;
		if (argv[i[0]][i[1]] == '-')
		{
			if (!argv[i[0]][i[1] + 1])
				ft_error("No input after '-'\n");
			while (argv[i[0]][++i[1]])
			{
				if (argv[i[0]][i[1]] >= 97 && argv[i[0]][i[1]] <= 122)
					flag = flag | (1 << (argv[i[0]][i[1]] - 97));
			}
			check_dump(argn, argv, data, i);
		}
		else
			data->n_players++;
		i[0]++;
	}
	ft_printf("NUMBER OF PLAYERS: %d\n", data->n_players);
	return (flag);
}

int 			ft_check_flags(int flags, char flag)
{
	if (flags & (1 << (flag - 97))) 
		return (1);
	return (0);
}
