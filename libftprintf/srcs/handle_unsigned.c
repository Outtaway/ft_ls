/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpshenyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 16:46:38 by kpshenyc          #+#    #+#             */
/*   Updated: 2018/11/19 16:46:39 by kpshenyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	hu_0__(t_sequence *seq, unsigned long long value, int value_width)
{
	int		readed;

	readed = 0;
	if (seq->precision <= value_width)
	{
		if (value_width > 0)
			readed += ft_putulong(value);
		readed += write_given_symb(' ', seq->width - value_width);
	}
	else
	{
		readed += write_given_symb('0', seq->precision - value_width);
		if (value_width > 0)
			readed += ft_putulong((value));
		readed += write_given_symb(' ', seq->width - seq->precision);
	}
	return (readed);
}

static int	hu_1__(t_sequence *seq, unsigned long long value, int value_width)
{
	int		readed;

	readed = 0;
	if (seq->precision_dot != '.' && ft_strchr(seq->flag, '0') != NULL)
		seq->precision = seq->width;
	if (seq->precision > value_width)
		readed += write_given_symb(' ', seq->width - value_width -
		(seq->precision - value_width));
	else
		readed += write_given_symb(' ', seq->width - value_width);
	if (seq->precision <= value_width && value_width > 0)
		readed += ft_putulong(value);
	else
	{
		readed += write_given_symb('0', seq->precision - value_width);
		if (value_width > 0)
			readed += ft_putulong(value);
	}
	return (readed);
}

int			handle_unsigned__(t_sequence *seq, va_list *va_list_)
{
	unsigned long long		value;
	int						value_width;
	int						readed;

	readed = 0;
	choose_u_type__(&value, seq, va_list_);
	value_width = value == 0 && seq->precision_dot == '.'
	&& seq->precision == 0 ? 0 : ft_value_width__(value, 10);
	if (seq->width > seq->precision && seq->width > value_width)
		if (ft_strchr(seq->flag, '-') != NULL)
			readed = hu_0__(seq, value, value_width);
		else
			readed = hu_1__(seq, value, value_width);
	else if (seq->precision >= seq->width && seq->precision > value_width)
	{
		readed += write_given_symb('0', seq->precision - value_width);
		if (value_width > 0)
			readed += ft_putulong(value);
	}
	else if (value_width > 0)
		readed += ft_putulong(value);
	return (readed);
}
