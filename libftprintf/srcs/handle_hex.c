/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpshenyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 15:56:13 by kpshenyc          #+#    #+#             */
/*   Updated: 2018/11/20 15:56:15 by kpshenyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	hh_0__(t_sequence *seq, int value_width,
					char *value_str)
{
	int readed;

	readed = 0;
	if (seq->precision <= value_width)
	{
		if (ft_strchr(seq->flag, '#') != NULL)
		{
			value_width += 2;
			readed += ft_putstrn("0x", 2);
		}
		readed += ft_putstrn(value_str, ft_strlen(value_str));
		readed += write_given_symb(' ', seq->width - value_width);
	}
	else
	{
		if (ft_strchr(seq->flag, '#') != NULL)
		{
			seq->width -= 2;
			readed += ft_putstrn(seq->specifier == 'X' ? "0X" : "0x", 2);
		}
		readed += write_given_symb('0', seq->precision - value_width);
		readed += ft_putstrn(value_str, ft_strlen(value_str));
		readed += write_given_symb(' ', seq->width - seq->precision);
	}
	return (readed);
}

static int	hh_1__(t_sequence *seq, int value_width,
					char *value_str)
{
	int readed;

	readed = 0;
	if (ft_strchr(seq->flag, '#') != NULL && value_width > 0)
		seq->width -= 2;
	if (seq->precision_dot != '.' && ft_strchr(seq->flag, '0') != NULL)
		seq->precision = seq->width;
	if (seq->precision > value_width)
		readed += write_given_symb(' ', seq->width - value_width -
		(seq->precision - value_width));
	else
		readed += write_given_symb(' ', seq->width - value_width);
	if (ft_strchr(seq->flag, '#') != NULL && value_width > 0)
		readed += ft_putstrn(seq->specifier == 'X' ? "0X" : "0x", 2);
	if (seq->precision <= value_width && value_width > 0)
		readed += ft_putstrn(value_str, ft_strlen(value_str));
	else if (value_width > 0)
	{
		readed += write_given_symb('0', seq->precision - value_width);
		readed += ft_putstrn(value_str, ft_strlen(value_str));
	}
	return (readed);
}

static int	hh_2__(t_sequence *seq, int value_width,
					char *value_str)
{
	int readed;

	readed = 0;
	if (seq->precision <= value_width)
	{
		if (ft_strchr(seq->flag, '#') != NULL)
			readed += ft_putstrn(seq->specifier == 'X' ? "0X" : "0x", 2);
		readed += ft_putstrn(value_str, ft_strlen(value_str));
	}
	else
	{
		if (ft_strchr(seq->flag, '#') != NULL)
			readed += ft_putstrn(seq->specifier == 'X' ? "0X" : "0x", 2);
		readed += write_given_symb('0', seq->precision - value_width);
		readed += ft_putstrn(value_str, ft_strlen(value_str));
	}
	return (readed);
}

int			handle_hex__(t_sequence *seq, va_list *va_list_)
{
	unsigned long long	value;
	int					value_width;
	char				*value_str;
	int					readed;

	readed = 0;
	choose_u_type__(&value, seq, va_list_);
	value_width = (value == 0 && seq->precision_dot == '.' &&
		seq->precision == 0) ? 0 : ft_value_width__(value, 16);
	value_str = ft_uitoa_base(value, (seq->specifier == 'X' ? HB : H));
	if (seq->width > seq->precision && seq->width > value_width)
		if (ft_strchr(seq->flag, '-') != NULL)
			readed += hh_0__(seq, value_width, value_str);
		else
			readed += hh_1__(seq, value_width, value_str);
	else if (seq->precision >= seq->width && seq->precision > value_width)
		readed += hh_2__(seq, value_width, value_str);
	else if (value_width > 0)
	{
		if (ft_strchr(seq->flag, '#') != NULL && value > 0)
			readed += ft_putstrn(seq->specifier == 'X' ? "0X" : "0x", 2);
		readed += ft_putstrn(value_str, ft_strlen(value_str));
	}
	free(value_str);
	return (readed);
}
