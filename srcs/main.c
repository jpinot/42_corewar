/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 17:53:30 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/09/30 23:19:25 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "basic_corewar.h"

unsigned char	g_winner;
size_t			g_lives;
int				g_cycle_to_die;
unsigned char	g_n_players;
unsigned char	g_mem[MEM_SIZE];
size_t 			g_nb_cycles;
unsigned int 	g_nb_pc;
unsigned int 	g_nb_pc_total;
t_pc 			*g_pc;
t_player		g_players[MAX_PLAYERS];

static void	select_mode(const unsigned int flags, const t_flag_value f_value)
{
	if (!flags)
		basic_launch();
	if (flags & 0x1)
		graphic_launch(flags);
	if (flags & 0x4)
		instruction_launch();
	if (flags & 0x8)
		deaths_launch();
}

static void	init_pc(const t_flag_value f_value)
{
	unsigned char 	i;
	t_pc 			*aux;

	i = 1;
	if (!(g_pc = (t_pc *)malloc(sizeof(t_pc))))
		ft_error("malloc failled in init_pc\n");
	*g_pc = (t_pc){0x0, 0, 0, {{0}}, 0, 0, 0, 0, NULL};
	if (f_value.player_nb[0])
		*((REG_CAST *)g_pc->reg[0]) = f_value.player_nb[i];
	else
		*((REG_CAST *)g_pc->reg[0]) = -1;
	invert_bytes(g_pc->reg, REG_SIZE);
	while (i < g_n_players)
	{
		if(!(aux = (t_pc *)malloc(sizeof(t_pc))))
			ft_error("malloc failled in init_pc\n");
		*aux = (t_pc){0x0, i * (MEM_SIZE / g_n_players), 0, {{0}}, i, 0, 0, i, g_pc};
		if (f_value.player_nb[i])
			*((REG_CAST *)aux->reg[0]) = f_value.player_nb[i];
		else
			*((REG_CAST *)aux->reg[0]) = -(i + 1);
		invert_bytes(aux->reg, REG_SIZE);
		g_pc = aux;
		i++;
	}
}

static void	present_players (void)
{
	unsigned char i;

	ft_printf("Introducing contestants...\n");
	i = 0;
	while (i < g_n_players && i < MAX_PLAYERS)
	{
		ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n", i + 1, g_players[i].prog_size,g_players[i].name, g_players[i].comment);
		i++;
	}
}

static void	show_winner(void)
{
	if (g_winner < g_n_players && g_winner < MAX_PLAYERS)
		ft_printf("Contestant %d, \"%s\", has won !\n", g_winner + 1, g_players[g_winner].name);
	else
		ft_error("Error in show_winner\n");
}

int			main(int ac, char **av)
{
	unsigned int flags;
	t_flag_value f_value;

	g_lives = 0;
	flags = 0;
	f_value  = (t_flag_value){0, {0}};
	g_cycle_to_die = CYCLE_TO_DIE;
	ft_memset(g_mem, 0, MEM_SIZE);
	g_nb_cycles = 0;
	ft_memset(g_players, 0, MAX_PLAYERS * sizeof(t_player));
	take_input(ac, (const char **)av, &flags, &f_value);
	g_winner = g_n_players - 1;
	g_nb_pc = g_n_players;
	g_nb_pc_total = g_n_players;
	g_pc = NULL;
	init_pc(f_value);
	present_players();
	select_mode(flags, f_value);
	show_winner();
	return (0);
}
