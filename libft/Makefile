#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile_ini.mk                                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jagarcia <mrodrigu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/30 22:34:55 by jagarcia          #+#    #+#              #
#    Updated: 2018/07/01 21:38:10 by jagarcia         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

.PHONY : all clean fclean re

NAME = libft.a

OBJ_DIR := objects/

SRC =	ft_isascii.c \
		ft_lstdelone.c \
		ft_memchr.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_strcpy.c \
		ft_strjoin.c	\
		ft_strnjoin.c	\
		ft_strnjoinfree.c	\
		ft_strjoinfree.c	\
		ft_strncmp.c \
		ft_strsplit.c \
		ft_isdigit.c \
		ft_lstiter.c \
		ft_memcmp.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_strdel.c \
		ft_strlcat.c \
		ft_strncpy.c \
		ft_strstr.c \
		ft_atoi.c \
		ft_isprint.c \
		ft_lstmap.c \
		ft_memcpy.c \
		ft_putendl.c \
		ft_strcat.c \
		ft_strdup.c \
		ft_strlen.c \
		ft_strnequ.c \
		ft_strsub.c \
		ft_bzero.c \
		ft_itoa.c \
		ft_lstnew.c \
		ft_memdel.c \
		ft_putendl_fd.c \
		ft_strchr.c \
		ft_strequ.c \
		ft_strmap.c \
		ft_strnew.c \
		ft_strtrim.c \
		ft_isalnum.c \
		ft_lstadd.c \
		ft_memalloc.c \
		ft_memmove.c \
		ft_putnbr.c \
		ft_strclr.c \
		ft_striter.c \
		ft_strmapi.c \
		ft_strnstr.c \
		ft_tolower.c \
		ft_isalpha.c \
		ft_islower.c \
		ft_isupper.c \
		ft_lstdel.c \
		ft_memccpy.c \
		ft_memset.c \
		ft_putnbr_fd.c \
		ft_strcmp.c \
		ft_striteri.c \
		ft_strncat.c \
		ft_strrchr.c \
		ft_toupper.c \
		ft_lstsplit.c \
		ft_lstnext.c \
		ft_swap.c \
		ft_pow.c \
		ft_sort_pos_int.c \
		ft_debug.c \
		ft_debug_num.c \
		ft_putbytes.c \
		ft_wstrlen.c \
		ft_strlen_free.c \
		ft_issdigit.c \
		ft_memjoinfree.c \
		ft_abs.c \
		ft_strinsert.c \
		ft_strinsertfree.c \
		ft_strcut.c \
		ft_strcutfree.c \
		ft_strinvert.c \
		ft_error.c \
		get_next_line.c \
		ft_numint.c \
		ft_printf.c \
		ft_asprintf.c \
		ft_dprintf.c \
		ft_field_format.c \
		ft_space_format.c \
		ft_plus_format.c \
		ft_hash_format.c \
		ft_apostrophe_format.c \
		ft_zero_format.c \
		ft_search_zero_format.c \
		ft_asterisc_format.c \
		ft_minus_format.c \
		ft_l_mod.c \
		ft_mods.c \
		ft_h_mod.c \
		ft_ll_mod.c \
		ft_hh_mod.c \
		ft_j_mod.c \
		ft_z_mod.c \
		ft_none_mod.c \
		ft_wchar.c \
		ft_utf8.c \
		ft_locate_pointer.c \
		ft_locate_date.c \
		ft_dectobin.c \
		ft_dectooct.c \
		ft_dectohex.c \
		ft_printmemory.c \
		ft_colors.c \
		ft_ajust_params.c \
		ft_ultoa_base.c \
		ft_ltoa_base.c \
		ft_findend.c \
		ft_choose_power.c \
		ft_dtomyd.c \
		ft_grisu.c \
		ft_sige.c \
		ft_take_power.c \
		ft_multiply.c \
		ft_round.c \
		ft_putthepoint.c \
		ft_sls_type.c \
		ft_clc_type.c \
		ft_ilidld_type.c \
		ft_xlx_type.c \
		ft_p_type.c \
		ft_oloulu_type.c \
		ft_n_type.c \
		ft_b_type.c \
		ft_r_type.c \
		ft_percent_type.c \
		ft_feleglg_type.c \
		ft_m_type.c \
		ft_error_type.c \
		ft_min.c

HEADERS =	includes/libft.h \
			includes/get_next_line.h \
			includes/formats.h \
			includes/mods.h \
			includes/ten_power.h \
			includes/types.h \
			includes/utils.h

OBJ = $(patsubst %.c, $(OBJ_DIR)%.o, $(SRC))

FT_PRINTF_DIR = ft_printf/

MODE = 1

ifeq ($(MODE), 0)
.PHONY: $(FT_PRINTF_DIR) compiling

all: $(NAME)

$(NAME): $(OBJ)
	@ranlib $(NAME)

$(OBJ_DIR)%.o : %.c
	@gcc -Wall -Wextra -Werror -Iincludes -c $<
	@mkdir -p $(OBJ_DIR)
	@mv -f $(@F) $(OBJ_DIR)
	@ar rc $(NAME) $@

else
all: $(OBJ)

$(OBJ_DIR)%.o : %.c
	@printf "\033[92mCompiling libft...\n\033[0m"
	@$(MAKE)  MODE=0
	@printf "\033[92mDone libft[\xE2\x9C\x94]\n\033[0m"

endif

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -rf $(OBJ_DIR)
	@rm -f $(NAME)

re:	fclean
	@$(MAKE) 
