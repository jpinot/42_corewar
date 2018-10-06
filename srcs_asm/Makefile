# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/14 22:43:59 by jpinyot           #+#    #+#              #
#    Updated: 2018/10/06 03:50:01 by jagarcia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ../asm

CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = ../libft/

SRC_DIR = srcs/

INC_DIR = ../includes/

CC = gcc

INC = $(wildcard $(INC_DIR)*.h)

SRC = asm_main.c\
      asm.c\
    ft_invalidargv.c\
	ft_error_getname.c\
	ft_error_getorders.c\
	ft_error_order.c\
	ft_error_par.c\
	ft_error_label.c\
	ft_puterr.c\
      ft_print_asm.c\
	  ft_label_to_pos.c\
	  ft_print_label.c\
	  ft_print_order.c\
	  ft_print_info.c\
       ft_getname.c\
       ft_getorders.c\
       ft_strcmp_index.c\
       ft_newline.c\
       ft_newlabel.c\
       ft_add_new_label.c\
       ft_add_new_line.c\
       ft_add_ld.c\
       ft_add_or.c\
       ft_add_st.c\
       ft_add_add.c\
       ft_add_aff.c\
       ft_add_and.c\
       ft_add_ldi.c\
       ft_add_lld.c\
       ft_add_sub.c\
       ft_add_sti.c\
       ft_add_xor.c\
       ft_add_lldi.c\
       ft_add_fork.c\
       ft_add_zjmp.c\
       ft_add_lfork.c\
       ft_add_live.c\
       ft_extract_dir.c\
       ft_extract_dir_2.c\
       ft_extract_reg.c\
       ft_extract_ind.c\
	   ft_extract_label.c\
       ft_extract_ind_label.c\
       ft_atoi_asm.c\
       ft_functions.c\
	   ft_line_to_file.c\
	   ft_header_to_file.c\
	   ft_invert_bytes.c\
	   ft_delstruct.c\
	   ft_label_to_num.c\

OBJ = $(patsubst %.c, $(OBJ_DIR)%.o, $(SRC))

OBJ_DIR = ../objects/

MODE = 0

ifeq ($(MODE), 1)
all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -L$(LIBFT_DIR) -lft -I$(INC_DIR) $(OBJ) -o $(NAME)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c $(INC) $(LIBFT_DIR)libft.a
	@mkdir -p $(OBJ_DIR)
	@printf "\033[92m--->Compiling $(@F)\033[0m"
	@$(CC) $(CFLAGS) -c $< -I$(INC_DIR) -I$(LIBFT_DIR)includes/ -o $@
	@printf "\033[92m   [OK]\n\033[0m"
else
$(NAME): | check_lib $(OBJ)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c $(INC) $(LIBFT_DIR)libft.a
	@printf "\033[92mCreating asm\033[0m\n"
	@$(MAKE) MODE=1
	@printf "\033[92mDone asm [OK]\n\033[0m"
endif

check_lib:
	@$(MAKE) -sC $(LIBFT_DIR)

clean:
	@$(MAKE) -C ../libft clean
	@/bin/rm -f $(OBJ)

fclean: clean
	@$(MAKE) -C ../libft fclean
	@/bin/rm -f $(NAME)

re: fclean
	make

.PHONY: all clean fclean re
