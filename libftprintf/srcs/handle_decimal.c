/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_decimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpshenyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 13:55:22 by kpshenyc          #+#    #+#             */
/*   Updated: 2018/11/14 13:55:37 by kpshenyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		hd_0__(t_sequence *seq, long long value, int value_width)
{
	int		readed;

	readed = 0;
	if (ft_strchr(seq->flag, '+') != NULL && value >= 0)
		ft_putchar('+');
	else if (ft_strchr(seq->flag, ' ') != NULL && value >= 0)
		ft_putchar(' ');
	else if (value < 0)
		ft_putchar('-');
	if (value < 0 || (ft_strchr(seq->flag, '+') != NULL && value >= 0)
		|| (ft_strchr(seq->flag, ' ') != NULL && value >= 0))
		readed = ((seq->width)--) ? 1 : 1;
	if (seq->precision <= value_width)
	{
		readed += ft_putulong(value < 0 ? -value : value);
		readed += write_given_symb(' ', seq->width - value_width);
	}
	else
	{
		readed += write_given_symb('0', seq->precision - value_width);
		readed += ft_putulong(value < 0 ? -value : value);
		readed += write_given_symb(' ', seq->width - seq->precision);
	}
	return (readed);
}

static int		hd_1__(t_sequence *seq, long long value, int value_width)
{
	int		readed;

	readed = 0;
	if (((ft_strchr(seq->flag, '+') != NULL ||
		ft_strchr(seq->flag, ' ') != NULL) && value >= 0) || value < 0)
		readed = ((seq->width)--) ? 1 : 1;
	if (seq->precision_dot != '.' && ft_strchr(seq->flag, '0') != NULL)
		seq->precision = seq->width;
	if (seq->precision > value_width)
		readed += write_given_symb(' ', seq->width - value_width -
		(seq->precision - value_width));
	else
		readed += write_given_symb(' ', seq->width - value_width);
	if (ft_strchr(seq->flag, '+') != NULL && value >= 0)
		ft_putchar('+');
	else if (ft_strchr(seq->flag, ' ') != NULL && value >= 0)
		ft_putchar(' ');
	else if (value < 0)
		ft_putchar('-');
	if (!(seq->precision <= value_width))
		readed += write_given_symb('0', seq->precision - value_width);
	if (!(value == 0 && seq->precision_dot == '.' && seq->precision == 0))
		readed += ft_putulong(value < 0 ? -value : value);
	return (readed);
}

static int		hd_2__(t_sequence *seq, long long value, int value_width)
{
	int		readed;

	readed = 0;
	if (((ft_strchr(seq->flag, '+') != NULL ||
		ft_strchr(seq->flag, ' ') != NULL) && value >= 0) || value < 0)
		readed += ((seq->width)--) ? 1 : 1;
	if (ft_strchr(seq->flag, '+') != NULL && value >= 0)
		ft_putchar('+');
	else if (ft_strchr(seq->flag, ' ') != NULL && value >= 0)
		ft_putchar(' ');
	else if (value < 0)
		ft_putchar('-');
	if (seq->precision <= value_width)
		readed += ft_putulong(value < 0 ? -value : value);
	else
	{
		readed += write_given_symb('0', seq->precision - value_width);
		readed += ft_putulong(value < 0 ? -value : value);
	}
	return (readed);
}

static int		hd_3__(t_sequence *seq, long long value)
{
	int		readed;

	readed = 0;
	if (ft_strchr(seq->flag, '+') && value >= 0)
		ft_putchar('+');
	else if (ft_strchr(seq->flag, ' ') && value >= 0)
		ft_putchar(' ');
	else if (value < 0)
		ft_putchar('-');
	if (!(value == 0 && seq->precision_dot == '.' && seq->precision == 0))
		readed = ft_putulong(value < 0 ? -value : value) + (value < 0 ||
		((ft_strchr(seq->flag, '+') || ft_strchr(seq->flag, ' '))
		&& value >= 0) ? 1 : 0);
	return (readed);
}

int				handle_decimal__(t_sequence *seq, va_list *va_list_)
{
	long long	value;
	int			value_width;
	int			readed;

	readed = 0;
	choose_type__(&value, seq, va_list_);
	value_width = ft_value_width__(value < 0 ? -value : value, 10);
	value_width = value == 0 && seq->precision_dot == '.' &&
		seq->precision == 0 ? 0 : value_width;
	if (seq->width > seq->precision && seq->width > value_width)
		readed = (ft_strchr(seq->flag, '-') != NULL) ?
		hd_0__(seq, value, value_width) : hd_1__(seq, value, value_width);
	else if (seq->precision >= seq->width && seq->precision > value_width)
		readed = hd_2__(seq, value, value_width);
	else
		readed = hd_3__(seq, value);
	return (readed);
}
