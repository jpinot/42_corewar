/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_corewar.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 21:48:04 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/10/05 23:56:16 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASIC_COREWAR_H
#define BASIC_COREWAR_H

/*
******************************INCLUDES******************************************
*/

#include "corewar.h"

/*
******************************STRUCTURES****************************************
*/

/*
** 1st bit: interface
** 2st bit: fullscreen
** 3st vit: intrucctions
*/
typedef struct		s_flag_value
{
	size_t			dump_cycle;
	int32_t			player_nb[MAX_PLAYERS];
}					t_flag_value;

typedef struct 		s_pc
{
	unsigned int	carry : 1;
	unsigned int	pc;
	unsigned int	wait_cycles;
	char 			reg[REG_NUMBER][REG_SIZE];
	char 			id;
	unsigned char	op;
	unsigned int	live;
	unsigned int	pc_num;
	struct s_pc		*next;
}					t_pc;

typedef struct		s_arg
{
	unsigned char	n_arg;
	unsigned char	len;
	unsigned char	type;
	unsigned int	dir_size : 1; //1 for D4 0 for D2
	unsigned char	arg[MAX_ARG_LEN];
}					t_arg;

typedef struct		s_op
{
	void			(*func)(t_pc *);
	unsigned int	cycles_wait;
}					t_op;

/*
******************************GLOBAL********************************************
*/

extern size_t			g_lives;
extern int				g_cycle_to_die;
extern unsigned char	g_mem[MEM_SIZE];
extern size_t 			g_nb_cycles;
extern unsigned int 	g_nb_pc;
extern unsigned int 	g_nb_pc_total;
extern t_pc 			*g_pc;

/*
******************************FUNCTIONS*****************************************
*/

void			print_usage(void);
int				set_flags(const unsigned int n_player, const char **av, unsigned int *flags, t_flag_value *f_value);
void			init_player(const char *str, const t_flag_value *f_value);
char			*read_alloc(int fd, const size_t size);
void			invert_bytes(void *arr, const size_t size);
long			invert_bytes_ret(const long arr, const size_t size);
void			take_input(const int ac, const char **av, unsigned int *flags, t_flag_value *f_value);
void			check_cycle_to_die(void);
void			check_cycle_to_die_deaths(void);
int				ft_mod(const int nb, const unsigned int mod);
unsigned char	get_size_arg(const unsigned char ocp, const unsigned char n_arg, const unsigned int dir_size);
void			get_arg(const unsigned char ocp, const unsigned int pos, const unsigned char prev_siz, t_arg *arg);
char			get_arg_value(t_arg *arg, const t_pc *pc, const unsigned char restriction);
void			basic_launch(void);
void			graphic_launch(const unsigned int flags);
void			instruction_launch(void);
void			deaths_launch(void);
void			*graphic_thread(void *arg);
void			core_live(t_pc *pc);
void			core_ld(t_pc *pc);
void			core_st(t_pc *pc);
void			core_add(t_pc *pc);
void			core_sub(t_pc *pc);
void			core_and(t_pc *pc);
void			core_or(t_pc *pc);
void			core_xor(t_pc *pc);
void			core_zjmp(t_pc *pc);
void			core_ldi(t_pc *pc);
void			core_sti(t_pc *pc);
void			core_fork(t_pc *pc);
void			core_lld(t_pc *pc);
void			core_lldi(t_pc *pc);
void			core_lfork(t_pc *pc);
void			core_aff(t_pc *pc);


/*
******************************GRAPH_FUNCTIONS*****************************************
*/

void			graphics_core_sti(t_pc *pc);
void			graphics_core_st(t_pc *pc);

/*
******************************INSTRUC_FUNCTIONS*****************************************
*/

void			instruc_core_live(t_pc *pc);
void			instruc_core_ld(t_pc *pc);
void			instruc_core_st(t_pc *pc);
void			instruc_core_add(t_pc *pc);
void			instruc_core_sub(t_pc *pc);
void			instruc_core_and(t_pc *pc);
void			instruc_core_or(t_pc *pc);
void			instruc_core_xor(t_pc *pc);
void			instruc_core_zjmp(t_pc *pc);
void			instruc_core_ldi(t_pc *pc);
void			instruc_core_sti(t_pc *pc);
void			instruc_core_fork(t_pc *pc);
void			instruc_core_lldi(t_pc *pc);
void			instruc_core_lld(t_pc *pc);
void			instruc_core_lfork(t_pc *pc);

#endif
