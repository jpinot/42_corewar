# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/14 22:43:59 by jpinyot           #+#    #+#              #
#    Updated: 2018/09/18 16:06:28 by jpinyot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = asm

FLAG = -Wall -Wextra -Werror

SRC_DIR = srcs/

ERROR_DIR = srcs/errors/

FUNC_DIR = srcs/func/

VIS_DIR = srcs/vis/

SRC = main.c\
      asm.c\

ERROR = ft_invalidargv.c\
	ft_error_getname.c\
	ft_error_getorders.c\
	ft_error_order.c\
	ft_error_par.c\
	ft_error_label.c\

VIS = ft_print_asm.c\
	  ft_label_to_pos.c\
	  ft_print_label.c\
	  ft_print_order.c\
	  ft_print_info.c\

FUNC = ft_getname.c\
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

OBJ_SRC = $(patsubst %.c, $(SRC_DIR)%.o, $(SRC))
OBJ_VIS = $(patsubst %.c, $(VIS_DIR)%.o, $(VIS))
OBJ_ERROR = $(patsubst %.c, $(ERROR_DIR)%.o, $(ERROR))
OBJ_FUNC = $(patsubst %.c, $(FUNC_DIR)%.o, $(FUNC))

OBJ = $(SRC:.c=.o) $(FUNC:.c=.o) $(ERROR:.c=.o) $(VIS:.c=.o)

all: $(NAME)


$(NAME): $(OBJ_SRC) $(OBJ_FUNC) $(OBJ_ERROR) $(OBJ_VIS)
	@$(MAKE) -C ../libft
	@gcc $(FLAGS) -L../libft/ -lft -I../includes $(OBJ) -o $(NAME)
%.o : %.c
	@gcc $(FLAGS) -I../includes -c $<

clean:
	@$(MAKE) -C ../libft clean
	@/bin/rm -f $(OBJ)

fclean: clean
	@$(MAKE) -C ../libft fclean
	@/bin/rm -f $(NAME)

re: fclean
	make

.PHONY: all clean fclean re
