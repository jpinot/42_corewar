/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_usage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 21:56:33 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/10/03 22:15:49 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "basic_corewar.h"

void	print_usage(void)
{
	ft_putstr("Usage: ./corewar [-n N | -i -v -f -d][foo_1.cor ... foo_n.cor]\n\
-n N		Enter the players numbres, will be read by order.\n\
======> INFORMATION FLAGS <==================================================\n\
-i		Shows the operations.\n-d		Shows the deaths.\n\
======> SDL FLAGS <==========================================================\n\
-v		Visual mode.\n-f		Fullscreen mode.\n\
| (• ◡•)| (❍ᴥ❍ʋ)(ノಠ益ಠ)ノ彡┻━┻¯\\_(ツ)_/¯༼ つ ◕_◕ ༽つರ_ರ(°,,°)┬─┬ノ( º _ ºノ)\
ಠoಠ\n");
}
