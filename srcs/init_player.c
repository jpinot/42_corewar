/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 19:48:58 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/10/05 23:58:23 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "basic_corewar.h"

static void		check_magic(const int fd)
{
	uint32_t	magic;
	int			rd;

	if ((rd = read(fd, &magic, sizeof(uint32_t))) < 0)
	{
		close(fd);
		ft_error("Error: read failed in check_magic\n");
	}
	if (rd != MAGIC_LEN)
	{
		close(fd);
		ft_error("Error: file is smaller than magic number lenght\n");
	}
	if (magic != 0xF383EA00)
	{
		close(fd);
		ft_error("Error: magic number incorrect\n");
	}
}

static uint32_t	get_prog_size(const int fd)
{
	uint32_t	size;
	int			rd;

	if ((rd = read(fd, &size, sizeof(uint32_t))) < 0)
	{
		close(fd);
		ft_error("Error: read failed in get_prog_size\n");
	}
	if ((unsigned long)rd != sizeof(uint32_t))
	{
		close(fd);
		ft_error("Error: file does not meet the standards\n");
	}
	invert_bytes(&size, sizeof(uint32_t));
	if (size > CHAMP_MAX_SIZE)
	{
		close(fd);
		ft_error("Error: player too big\n");
	}
	return (size);
}

static void		load_prog(const int fd, const unsigned int player_nb, const uint32_t prog_size)
{
	int		rd;
	if((rd = read(fd, g_mem + (player_nb * (MEM_SIZE / g_n_players)), prog_size)) < 0)
	{
		close(fd);
		ft_error("Error: read failed in load_prog\n");
	}
	if ((uint32_t)rd != prog_size)
	{
		close(fd);
		ft_error("Error: program size and real program size does not match\n");
	}
}

void			init_player(const char *str, const t_flag_value *f_value)
{
	unsigned int	player_nb;
	int				fd;

	player_nb = 0;
	while (g_players[player_nb].name && player_nb < MAX_PLAYERS)
		player_nb++;
	if (player_nb == MAX_PLAYERS)
		ft_error("Error: too much players.\n");
	if ((fd = open(str, O_RDONLY)) < 0)
		ft_error("Error: opening the file\n");
	check_magic(fd);
	g_players[player_nb].name = read_alloc(fd, PROG_NAME_LENGTH + 4);
	g_players[player_nb].prog_size = get_prog_size(fd);
	g_players[player_nb].comment = read_alloc(fd, COMMENT_LENGTH + 4);
	load_prog(fd, player_nb, g_players[player_nb].prog_size);
	close(fd);
	if (f_value->player_nb[player_nb])
		g_players[player_nb].player_nb = f_value->player_nb[player_nb];
	else
		g_players[player_nb].player_nb = -(player_nb + 1);
//	invert_bytes(&(g_players[player_nb].player_nb), sizeof(int32_t));
}
