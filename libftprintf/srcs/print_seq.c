/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_seq.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpshenyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 15:44:00 by kpshenyc          #+#    #+#             */
/*   Updated: 2018/11/12 15:44:01 by kpshenyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		print_seq__(t_sequence *seq, va_list *va_list_)
{
	int		readed;

	(seq->specifier == '%') ? readed = handle_procent__(seq) : 0;
	(seq->specifier == 'p') ? readed = handle_addr__(seq, va_list_) : 0;
	(seq->specifier == 'b') ? readed = handle_binary__(seq, va_list_) : 0;
	if (seq->specifier == 'C' || seq->specifier == 'c')
		readed = handle_char__(seq, va_list_);
	else if (seq->specifier == 'S' || seq->specifier == 's')
		readed = handle_str__(seq, va_list_);
	else if (seq->specifier == 'd' || seq->specifier == 'i' ||
		seq->specifier == 'D')
		readed = handle_decimal__(seq, va_list_);
	else if (seq->specifier == 'u' || seq->specifier == 'U')
		readed = handle_unsigned__(seq, va_list_);
	else if (seq->specifier == 'o' || seq->specifier == 'O')
		readed = handle_octal__(seq, va_list_);
	else if (seq->specifier == 'x' || seq->specifier == 'X')
		readed = handle_hex__(seq, va_list_);
	else if (seq->specifier == 'f' || seq->specifier == 'F')
		readed = handle_float__(seq, va_list_);
	else if (seq->specifier == 'Q')
		readed = handle_arr__(seq, va_list_);
	else if (!seq->specifier)
		readed = write_given_symb(' ', seq->width - 1);
	return (readed);
}
