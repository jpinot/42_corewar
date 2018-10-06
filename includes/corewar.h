/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 21:49:08 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/10/05 16:53:23 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
#define COREWAR_H

/*
******************************INCLUDES******************************************
*/

#include <pthread.h>
#include "op.h"
#include "../libft/includes/libft.h"

/*
******************************DEFINITIONS***************************************
*/

# define MAX(A, B) ((A > B) ? A : B)
# define MAX_ARG_LEN MAX(IND_SIZE, MAX(REG_SIZE, DIR_SIZE))
# define NB_INSTRUCTIONS 16
# define MAGIC_LEN 4

# if IDX_MOD < 100
#  error IDX_MOD too small
# endif

# if MAX_ARG_LEN == 1
#  define MAX_CAST int8_t
# elif MAX_ARG_LEN == 2
# define MAX_CAST int16_t
# elif MAX_ARG_LEN == 4
# define MAX_CAST int32_t
# elif MAX_ARG_LEN == 8
# define MAX_CAST int64_t
# endif

/*
**# if IND_SIZE == 1
**#  define IND_CAST int8_t
*/
# if IND_SIZE == 2
# define IND_CAST int16_t
/*
**# elif IND_SIZE == 4
**# define IND_CAST int32_t
**# elif IND_SIZE == 8
**# define IND_CAST int64_t
*/
# else
#error Wrong size of indirect, expected: 2
# endif

/*
# if DIR_SIZE == 1
#  define DIR_CAST int8_t
# elif DIR_SIZE == 2
# define DIR_CAST int16_t
*/
# if DIR_SIZE == 4
# define DIR_CAST int32_t
/*
# elif DIR_SIZE == 8
# define DIR_CAST int64_t
*/
# else
#error Wrong size of indirect, expected: 4
# endif

/*
# if REG_SIZE == 1
#  define REG_CAST int8_t
# elif REG_SIZE == 2
# define REG_CAST int16_t
*/
# if REG_SIZE == 4
# define REG_CAST int32_t
/*
# elif REG_SIZE == 8
# define REG_CAST int64_t
*/
# else
#error Wrong size of registre, expected: 4
# endif

/*
******************************STRUCTURES****************************************
*/

typedef struct 		s_player
{
	char			*name;
	char			*comment;
	int32_t			player_nb;
	uint32_t		prog_size;
	unsigned int  	last_live;
	unsigned int 	live_counter;
}					t_player;

/*
******************************GLOBAL********************************************
*/

extern unsigned char	g_winner;
extern unsigned char	g_n_players;
extern t_player			g_players[MAX_PLAYERS];


#endif
