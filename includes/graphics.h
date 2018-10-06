/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 17:03:13 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/10/06 04:05:46 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_H
# define GRAPHICS_H

/*
******************************INCLUDES******************************************
*/
# include "../SDL2_files/SDL2_srcs/include/SDL.h"
# include "../SDL2_files/SDL2_TTF_srcs/SDL_ttf.h"
# include "../SDL2_files/SDL2_image_srcs/SDL_image.h"
# include "corewar.h"

/*
******************************DEFINITIONS***************************************
*/
# define NEW_DUR 69
# define MODE_SDL 1
# define MODE_TTF 0
# define MODE_IMG -1
# define FIELD_FONT 0
# define TMP_FONT 1
# define GENERAL_NBR_FONT 2
# define PLAYER_NBR_FONT 3
# define SCREEN_W 1280
# define SCREEN_H 800
# define SCREEN_SCALE 1.2
# define SCREEN_NAME "Corewar"
# define LEFT_BORDER 0.434
# define BOTTOM_BORDER 0.055
# define UPPER_BORDER 0.055
# define RIGHT_BORDER 0.04
# define NEW_COLOR_CYCLES 70
# define NONE_COLOR 89, 89, 75, SDL_ALPHA_OPAQUE
# define PLAYER_ONE_COLORA 51, 255, 51, SDL_ALPHA_OPAQUE
# define PLAYER_ONE_COLORB 153, 255, 153, SDL_ALPHA_OPAQUE
# define PLAYER_ONE_COLORC 0, 153, 0, SDL_ALPHA_OPAQUE
# define PLAYER_TWO_COLORA 255, 204, 0, SDL_ALPHA_OPAQUE
# define PLAYER_TWO_COLORB 255, 229, 127, SDL_ALPHA_OPAQUE
# define PLAYER_TWO_COLORC 127, 102, 0, SDL_ALPHA_OPAQUE
# define PLAYER_THREE_COLORB 255, 242, 207, SDL_ALPHA_OPAQUE
# define PLAYER_THREE_COLORA 217, 204, 169, SDL_ALPHA_OPAQUE
# define PLAYER_THREE_COLORC 168, 154, 117, SDL_ALPHA_OPAQUE
# define PLAYER_FOUR_COLORA 252, 102, 92, SDL_ALPHA_OPAQUE
# define PLAYER_FOUR_COLORB 253, 178, 173, SDL_ALPHA_OPAQUE
# define PLAYER_FOUR_COLORC 176, 4, 0, SDL_ALPHA_OPAQUE
# define BACK_COLOR 0, 0, 0, SDL_ALPHA_OPAQUE
# define FIELD_COLOR 61, 61, 51, SDL_ALPHA_OPAQUE

/*
******************************STRUCTURES****************************************
*/

typedef struct			s_font
{
	TTF_Font			*font;
	int					font_size;
	int					w;
	int					h;
	SDL_Color			color;
}						t_font;

typedef	struct			s_info
{
	SDL_Rect			*cicles_gen;
	SDL_Rect			*cicles_play;
	SDL_Rect			*lst_life;
	SDL_Rect			*cicle_to_die;
	SDL_Rect			*processos;
}						t_info;

typedef struct			s_sdl
{
	struct {
		int				w;
		int				h;
		const char		*name;
		SDL_Window		*window;
		SDL_Renderer	*renderer;
	}					screen;
	int					cuant_squares[2];
	t_font				font[4];
	SDL_Texture			*info_text;
	SDL_Texture			*marc_board;
	SDL_Texture			**pc;
	SDL_Texture			*end[2];
	SDL_Texture			***hexa_bytes;
	t_info				info;
	SDL_Surface			*general_nbr;
	SDL_Surface			*player_nbr;
	SDL_Surface			**heart;
	SDL_Surface			*pause[2];
	SDL_Surface			*plus_minus[4];
	SDL_Surface			*little_screen;
	SDL_Rect			*button_pos;
	SDL_Rect			*little_screen_pos;
	SDL_Rect			*heart_pos;
	SDL_Rect			*square;
	SDL_Rect			*big_square;
	SDL_Rect			*square_info;
	SDL_Rect			*info_marc;
}						t_sdl;

typedef struct			s_board
{
	unsigned char		mem;
	unsigned char		new;
	unsigned char		id;
}						t_board;

typedef struct			s_graphics
{
	t_board				board[MEM_SIZE];
	t_player			players[MAX_PLAYERS];
	int					cycle_to_die;
	int					cycle_pre_die;
	size_t				cycle;
	unsigned int		nb_pc;
	unsigned int		*pcs;
	unsigned int		prog_end : 1;
	struct s_graphics	*next;
}						t_graphics;

/*
******************************GLOBAL********************************************
*/

extern t_board			g_board[MEM_SIZE];
extern t_sdl			*g_graph;
extern t_graphics		*g_frame;
extern t_graphics		*g_graph_tail;
extern t_graphics		*g_aux;
extern pthread_mutex_t	g_lock;
extern int				g_cycle_cuant;
extern unsigned int		g_pause;
extern unsigned int		g_hexl;
extern unsigned int		g_step;

/*
******************************FUNCTIONS*****************************************
*/

void					ft_ini_graphics(const unsigned int flags);
void					ft_quit_graphics(void);
void					ft_sdl_error(char *str, int mode);
void					ft_ini_interface(void);
void					ft_ini_font(void);
void					ft_board_to_screen(const t_board *board);
void					ft_pcs_to_rack(const unsigned int nb_pc,
							const unsigned int *pcs, int stela);
void					ft_set_back_to_front(void);
void					ft_ini_information(void);
void					ft_ini_material(SDL_Surface *info_marc);
SDL_Surface				*ft_write_string(char *str, int pos[2], int name);
int						ft_write_number_fields(t_font *font, int pos[2],
							SDL_Surface *number);
void					ft_update_info(const t_player *players,
							const int cicle_pre_die);
void					ft_put_general_info(void);
void					ft_put_player_info(SDL_Surface *info_marc, int i);
SDL_Color				ft_sdl_color(int i);
Uint32					ft_maprgba(SDL_PixelFormat *format, int i, int alpha);
void					ft_ini_pcs(void);
void					ft_ini_images(void);
void					ft_ini_sprites(SDL_Rect *cicles_play,
							SDL_Rect *info_marc, SDL_Surface *player_nbr);
void					ft_reset_health(int player, SDL_Rect *heart_pos,
							SDL_Rect *info_marc, SDL_Surface *ini_heart);
void					ft_check_health(const int cycle_to_die, int player,
							int cicle_pre_die, const t_player *players);
void					new_frame(const int j);
void					ft_surf_to_text(SDL_Texture *dst, SDL_Surface *src,
							SDL_Rect *dst_rect);
void					ft_put_end_frame(void);
void					ft_surf_to_text2(SDL_Texture *dst, SDL_Surface *src,
							SDL_Rect *dst_rect);
void					ft_events(int *running);
int						ft_pause_button(unsigned int pause);
void					ft_back_forw_buttons(int mode);
void					ft_update_little_screen(void);
void					ft_blit_and_draw(SDL_Surface *hall);
#endif
