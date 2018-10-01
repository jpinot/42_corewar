#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/04 20:25:41 by mrodrigu          #+#    #+#              #
#    Updated: 2018/10/01 00:22:36 by mrodrigu         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

.PHONY: all clean fclean re check_lib

NAME = prueba

CFLAGS = -pthread  #-g3 #-fsanitize=address #-Wall -Wextra -Werror -g3

SDLFLAGS = `sdl2-config --cflags` `sdl2-config --libs` -lSDL2_ttf -lSDL2_image

CC = gcc

FUNCS =	main.c \
		init_player.c \
		invert_bytes.c \
		read_alloc.c \
		invert_bytes_ret.c \
		set_flags.c \
		take_input.c \
		check_cycle_to_die.c \
		check_cycle_to_die_deaths.c \
		ft_mod.c \
		get_size_arg.c \
		get_arg.c \
		get_arg_value.c \
		basic_launch.c \
		graphic_launch.c \
		instruction_launch.c \
		deaths_launch.c \
		core_live.c \
		core_ld.c \
		core_st.c \
		core_add.c \
		core_sub.c \
		core_and.c \
		core_or.c \
		core_xor.c \
		core_zjmp.c \
		core_ldi.c \
		core_sti.c \
		core_fork.c \
		core_lld.c \
		core_lldi.c \
		core_lfork.c \
		core_aff.c \
		graphics_core_sti.c \
		graphics_core_st.c \
		graphic_thread.c \
		instruc_core_live.c \
		instruc_core_ld.c \
		instruc_core_st.c \
		instruc_core_add.c \
		instruc_core_sub.c \
		instruc_core_and.c \
		instruc_core_or.c \
		instruc_core_xor.c \
		instruc_core_zjmp.c \
		instruc_core_ldi.c \
		instruc_core_sti.c \
		instruc_core_fork.c \
		instruc_core_lldi.c \
		instruc_core_lfork.c

GRAPH = ft_ini_graphics.c \
		ft_quit_graphics.c \
		ft_sdl_error.c \
		ft_ini_interface.c \
		ft_ini_font.c \
		ft_board_to_screen.c \
		ft_pcs_to_rack.c \
		ft_set_back_to_front.c \
		ft_ini_information.c \
		ft_ini_material.c \
		ft_update_info.c \
		ft_put_general_info.c \
		ft_put_player_info.c \
		writer.c \
		colors.c \
		ft_ini_pcs.c \
		ft_ini_images.c \
		ft_ini_sprites.c \
		new_frame.c \
		ft_surf_to_text.c \
		ft_reset_health.c \
		ft_check_health.c

SRCS_DIR = srcs/

GRAPH_DIR = srcs_graphics/

INC_DIR = includes/

LIBFT_DIR = libft/

LIBFT_NAME = libft.a

OBJ_DIR = objects/

OBJ_FUNCS = $(patsubst %.c, $(OBJ_DIR)%.o,$(FUNCS))

OBJ_GRAPH = $(patsubst %.c, $(OBJ_DIR)%.o, $(GRAPH))

INC = $(wildcard $(INC_DIR)*.h)

OBJ = $(OBJ_FUNCS) $(OBJ_GRAPH)

MODE = 0

ifeq ($(MODE), 1)
all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(SDLFLAGS) -L$(LIBFT_DIR) -lft -o $(NAME)

$(OBJ_DIR)%.o: $(SRCS_DIR)%.c $(INC) $(LIBFT_DIR)$(LIBFT_NAME)
	@mkdir -p $(OBJ_DIR)
	@printf "\033[92m--->Compiling $(@F)\033[0m"
	@$(CC) $(CFLAGS) -c $< -I $(INC_DIR) -I$(LIBFT_DIR)includes/ -o $@
	@printf "\033[92m   [OK]\n\033[0m"

$(OBJ_DIR)%.o: $(GRAPH_DIR)%.c $(INC) $(LIBFT_DIR)$(LIBFT_NAME)
	@mkdir -p $(OBJ_DIR)
	@printf "\033[92m--->Compiling $(@F)\033[0m"
	@$(CC) $(CFLAGS) -c $< -I $(INC_DIR) -I$(LIBFT_DIR)includes/ -o $@
	@printf "\033[92m   [OK]\n\033[0m"
else
$(NAME) : |check_lib $(OBJ)

$(OBJ_DIR)%.o : $(SRCS_DIR)%.c $(INC) $(LIBFT_DIR)$(LIBFT_NAME)
	@printf "\033[92mCreating $(NAME)\033[0m\n"
	@$(MAKE) MODE=1
	@printf "\033[92mDone $(NAME) [OK]\n\033[0m"
$(OBJ_DIR)%.o : $(GRAPH_DIR)%.c $(INC) $(LIBFT_DIR)$(LIBFT_NAME)
	@printf "\033[92mCreating $(NAME)\033[0m\n"
	@$(MAKE) MODE=1
	@printf "\033[92mDone $(NAME) [OK]\n\033[0m"
endif
check_lib:
	@$(MAKE) -sC $(LIBFT_DIR)

clean:
	@printf "\033[92m***Cleaning Objects***\033[0m\n"
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@printf "\033[92m***Cleaning Executables & Libraries***\033[0m\n"
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean
	@make
