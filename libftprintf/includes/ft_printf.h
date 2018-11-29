/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpshenyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 14:42:15 by kpshenyc          #+#    #+#             */
/*   Updated: 2018/11/07 14:48:22 by kpshenyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>

# define PROC 0
# define CHAR 1
# define STR 2
# define DEC 3
# define ADDR 4
# define UINT 5
# define OCT 6
# define HEX 7
# define FLOAT 8
# define BIN 9
# define ARR 10

# define NO_FLAG NULL
# define NO_WIDTH 0
# define NO_PRECISION 0
# define NO_LENGTH 0
# define NO_SPECIFIER 0

# define HB "0123456789ABCDEF"
# define H "0123456789abcdef"

# define __BYTE t_byte
# define __BYTE_SEQ t_byte_seq
# define __7_BIT 127
# define __11_BIT 2047
# define __16_BIT 65535

# define __SHIFT 6
# define __UTF_8_MASK_0 0b00000000
# define __UTF_8_MASK_1 0b10000000
# define __UTF_8_MASK_2 0b11000000
# define __UTF_8_MASK_3 0b11100000
# define __UTF_8_MASK_4 0b11110000

# define __MASK_0 0b01111111
# define __MASK_1 0b00111111
# define __MASK_2 0b00011111
# define __MASK_3 0b00001111
# define __MASK_4 0b00000111

# define __ERR_MSG(msg) ft_putendl(msg);
# define __ERR_STATE(st) if(st == -1) { return (-1); }
# define __ERR_STATE_CL(st, i) if(st == -1) { *i = 0; return (-1); }
# define __ERR_STATE_FREE(st, it) if (st == -1) { free(it); return (-1); }

typedef char	t_byte;
typedef t_byte*	t_byte_seq;
typedef struct	s_sequence
{
	char		*flag;
	int			width;
	int			precision;
	char		precision_dot;
	char		length[3];
	char		specifier;
}				t_sequence;

int				count_bytes(int symb_);
void			set_uni_mask(int bytes_, int bytes_iter_, int *uni_mask_);
void			set_user_mask(int bytes_, int bytes_iter_, int *user_mask_);
__BYTE_SEQ		to_write__(int symb_, int *bytes_);
int				write_given_symb(char c, int num);
void			choose_type__(long long *value, t_sequence *seq,
				va_list *va_list_);
void			choose_u_type__(unsigned long long *value, t_sequence *seq,
				va_list *va_list_);

int				handle_arr__(t_sequence *seq, va_list *va_list_);
int				handle_procent__(t_sequence *seq);
int				handle_float__(t_sequence *seq, va_list *va_list_);
int				handle_binary__(t_sequence *seq, va_list *va_list_);
int				handle_hex__(t_sequence *seq, va_list *va_list_);
int				handle_octal__(t_sequence *seq, va_list *va_list_);
int				handle_unsigned__(t_sequence *seq, va_list *va_list_);
int				handle_addr__(t_sequence *seq, va_list *va_list_);
int				handle_decimal__(t_sequence *seq, va_list *va_list_);
int				handle_str__(t_sequence *seq, va_list *va_list_);
int				handle_char__(t_sequence *seq, va_list *va_list_);
int				print_seq__(t_sequence *seq, va_list *va_list_);
int				flags__(char *format, int *i, t_sequence *seq,
				va_list *va_list_);
int				print_str_part__(char *format, int *i);
int				ft_printf(const char *format, ...);

#endif
