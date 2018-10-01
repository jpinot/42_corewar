/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 19:48:58 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/09/29 22:21:58 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "basic_corewar.h"

static void		check_magic(const int fd)
{
	uint32_t magic;

	if (read(fd, &magic, sizeof(uint32_t)) < 0)
		ft_error("read failed in check_magic");
	if (magic != 0xF383EA00)
		ft_error("Magic number incorrect");
}

static uint32_t	get_prog_size(const int fd)
{
	uint32_t size;

	if ((read(fd, &size, sizeof(uint32_t))) < 0)
		ft_error("read failed in get_prog_size");
	invert_bytes(&size, sizeof(uint32_t));
	if (size > CHAMP_MAX_SIZE)
		ft_error("Error: player too big\n");
	return (size);
}

static void		load_prog(const int fd, const unsigned int player_nb, const uint32_t prog_size)
{
	if((read(fd, g_mem + (player_nb * (MEM_SIZE / g_n_players)), prog_size)) < 0)
		ft_error("read failed in load_prog");
}

void			init_player(const char *str, const t_flag_value *f_value)
{
	unsigned int	player_nb;
	int				fd;

	player_nb = 0;
	while (g_players[player_nb].name && player_nb < MAX_PLAYERS)
		player_nb++;
	if (player_nb == MAX_PLAYERS)
		ft_error("Too much players.");
	if ((fd = open(str, O_RDONLY)) < 0)
		ft_error("error opening the file");
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
