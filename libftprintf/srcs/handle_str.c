/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpshenyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 19:12:14 by kpshenyc          #+#    #+#             */
/*   Updated: 2018/11/13 19:12:38 by kpshenyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			handle_null__(t_sequence *seq)
{
	int		readed;

	readed = 0;
	if (seq->precision_dot == '.' && seq->precision < 6)
	{
		if (ft_strchr(seq->flag, '0') == NULL)
			readed += write_given_symb(' ', seq->width - seq->precision);
		else
			readed += write_given_symb('0', seq->width - seq->precision);
		readed += ft_putstrn("(null)", seq->precision);
		readed += write_given_symb(' ', -(seq->width) - seq->precision);
	}
	else
	{
		readed += write_given_symb(' ', seq->width > 6 ? seq->width - 6 : 0);
		readed += ft_putstrn("(null)", 6);
		seq->width = (seq->width < 0) ? -(seq->width) : seq->width;
		readed += write_given_symb(' ', seq->width > 6 ? -seq->width - 6 : 0);
	}
	return (readed);
}

int			write_uni_str(t_sequence *seq, int *uni_str)
{
	int			bytes_;
	int			bytes_acc;
	__BYTE_SEQ	to_write_;
	int			readed;

	readed = 0;
	bytes_acc = 0;
	while (*(uni_str + bytes_acc))
		++bytes_acc;
	if (seq->width > 0 && ft_strchr(seq->flag, '0'))
		readed += write_given_symb('0', seq->width - bytes_acc);
	else if (seq->width > 0 && ft_strchr(seq->flag, '0') == NULL)
		readed += write_given_symb(' ', seq->width - bytes_acc);
	while (*uni_str)
	{
		to_write_ = to_write__(*uni_str, &bytes_);
		write(1, to_write_, bytes_);
		readed += bytes_;
		free(to_write_);
		uni_str++;
	}
	if (seq->width < 0)
		readed += write_given_symb(' ', -(seq->width) - bytes_acc);
	return (readed);
}

int			write_basic_str(t_sequence *seq, char *str)
{
	int		s_len;
	int		readed;

	readed = 0;
	s_len = ft_strlen(str);
	seq->precision = (seq->precision < 0) ? ft_strlen(str) : seq->precision;
	if (seq->precision_dot != '.')
	{
		readed += (ft_strchr(seq->flag, '0') != NULL) ? write_given_symb('0',
			seq->width - s_len) : write_given_symb(' ', seq->width - s_len);
		readed += ft_putstrn(str, s_len);
		readed += write_given_symb(' ', -(seq->width) - s_len);
	}
	else
	{
		s_len = (seq->precision < s_len) ? seq->precision : s_len;
		readed += (ft_strchr(seq->flag, '0') != NULL) ? write_given_symb('0',
			seq->width - s_len) : write_given_symb(' ', seq->width - s_len);
		readed += ft_putstrn(str, s_len);
		readed += write_given_symb(' ', -(seq->width) - (s_len));
	}
	return (readed);
}

int			handle_str__(t_sequence *seq, va_list *va_list_)
{
	char			*str;
	int				*uni_str;
	int				readed;

	readed = 0;
	seq->width = (ft_strchr(seq->flag, '-') != NULL) ?
		-(seq->width) : seq->width;
	if (seq->specifier == 's' && ft_strcmp(seq->length, "l"))
	{
		str = va_arg(*va_list_, char *);
		if (str == NULL)
			readed = handle_null__(seq);
		else
			readed = (write_basic_str(seq, str));
	}
	else if ((seq->specifier == 'S' || !(ft_strcmp(seq->length, "l")))
		&& MB_CUR_MAX != 1)
	{
		uni_str = va_arg(*va_list_, int *);
		if (uni_str == NULL)
			readed = handle_null__(seq);
		else
			readed = (write_uni_str(seq, uni_str));
	}
	return (readed);
}
