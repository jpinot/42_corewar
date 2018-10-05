/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 14:14:30 by jpinyot           #+#    #+#             */
/*   Updated: 2018/10/05 17:40:43 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H
# include "../libft/includes/libft.h"
# include "corewar.h"
# include "op.h"
# include <fcntl.h>
# define HASH_SIZE 100
# define REG_ASM_SIZE 1
# define END_LINE_CHAR ';'

typedef struct	s_header
{
	char			*prog_name;
	char			*comment;
	int				name_size;
	char			flag_n;
	char			flag_c;
	int				comment_size;
	int				line_n;
}				t_header;

typedef struct	s_label
{
	char			*name;
	int				id;
	int				pos;
	int				color;
	struct s_label	*copy;
}				t_label;

typedef	struct	s_line
{
	char			order_n;
	MAX_CAST		arg[3];
	char			*arg_lab[3];
	int				lab_color[3];
	char			arg_size[3];
	unsigned char	ocp;
	char			*line;
	unsigned int	pos;
	int				w;
	t_label			*label;
	struct s_line	*next;
}				t_line;
/*
**SRCS
*/
int				assembler(int fd, char *filename, int sel);
/*
**FUNC
*/
t_header		ft_getname(char *line, int n_line, t_header h);
int				ft_strcmp_index(char *s1, char *s2);
int				ft_strcmp_index_jmp(char *s1, char *s2);
int				ft_strcmp_to(char *s1, char *s2);
t_label			*ft_newlabel(char *name, int id);
t_line			*ft_newline(t_label *l, int ord_n, char *line, int w);
t_line			*ft_getorders(char *l, t_label **label, int j, int n_line);
t_label			**ft_add_new_label(t_label **label, int id, char *l, int i);
t_line			*ft_add_new_line(char *l, int cnt, int i, int n_line);
MAX_CAST		ft_atoi_asm(const char *str, int pos, MAX_CAST *val);
int				ft_jmp_s_t(char *s, int i);
int				ft_hash_it(int id, int max);
MAX_CAST		ft_extract_label_line(t_line *line, t_label *label, int pos);
void			ft_invert_bytes(void *arr, const size_t size);
void			ft_delstruct(t_label **label, t_line *line);
char			*ft_strjoin_n(char *s1, char *s2, int sel, char *l);
t_line			*ft_label_to_num(t_line *line, t_label **label);
/*
**PRINT TO FILE FUNC
*/
void			ft_line_to_file(t_line *bgn, t_label **label, int fd);
void			ft_header_to_file(t_header header, int fd, unsigned int size);
/*
**FUNC CONV
*/
int				ft_extract_dir(t_line **line, int i, int n_line, int pos);
int				ft_extract_dir_2(t_line **line, int i, int n_line, int pos);
int				ft_extract_ind(t_line **line, int i, int n_line, int pos);
int				ft_extract_ind_label(t_line **line, int i, int n_line, int pos);
int				ft_extract_reg(t_line **line, int i, int n_line, int pos);
/*
**FUNC ORDERS
*/
t_line			*ft_add_ld(char *l, int i, int n_line);
t_line			*ft_add_lld(char *l, int j, int n_line);
t_line			*ft_add_or(char *l, int j, int n_line);
t_line			*ft_add_st(char *l, int j, int n_line);
t_line			*ft_add_add(char *l, int j, int n_line);
t_line			*ft_add_aff(char *l, int j, int n_line);
t_line			*ft_add_and(char *l, int j, int n_line);
t_line			*ft_add_ldi(char *l, int j, int n_line);
t_line			*ft_add_sub(char *l, int j, int n_line);
t_line			*ft_add_sti(char *l, int j, int n_line);
t_line			*ft_add_xor(char *l, int j, int n_line);
t_line			*ft_add_lldi(char *l, int j, int n_line);
t_line			*ft_add_fork(char *l, int j, int n_line);
t_line			*ft_add_zjmp(char *l, int j, int n_line);
t_line			*ft_add_lfork(char *l, int j, int n_line);
t_line			*ft_add_live(char *l, int j, int n_line);
/*
**PRINT
*/
void			ft_print_asm(t_header header, t_line *line, t_label **label, int size);
t_line			*ft_label_to_pos(t_line *bgn, t_label **label);
int				ft_print_label(t_line *line);
void			ft_print_order(t_line *l);
void			ft_print_info(t_line *l);
/*
**ERROR
*/
int				ft_invalidargv(int sel, char *s);
void			ft_error_getname(int n_line, int sel);
void			ft_error_order(int l, int sel, char *s, char *ex);
void			ft_error_par(int l, int sel, char *s, char *ex);
void			ft_error_label(int l, int sel, char *s);
void			ft_check_for_coments(char *l, int i, int n_line);
void			ft_error_getorders(int l, int sel);
void			ft_puterr(char *s);
void			ft_putnerr(int n);
#endif
