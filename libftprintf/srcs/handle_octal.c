/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_octal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpshenyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 16:54:20 by kpshenyc          #+#    #+#             */
/*   Updated: 2018/11/19 16:54:22 by kpshenyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ho_0__(t_sequence *seq, unsigned long long value, int value_width,
					char *value_str)
{
	int		readed;

	readed = 0;
	if (seq->precision <= value_width)
	{
		if (ft_strchr(seq->flag, '#') != NULL && value > 0)
		{
			value_width++;
			ft_putchar('0');
			readed++;
		}
		readed += ft_putstrn(value_str, ft_strlen(value_str));
		readed += write_given_symb(' ', seq->width - value_width);
	}
	else
	{
		readed += write_given_symb('0', seq->precision - value_width);
		readed += ft_putstrn(value_str, ft_strlen(value_str));
		readed += write_given_symb(' ', seq->width - seq->precision);
	}
	return (readed);
}

static int	ho_1__(t_sequence *seq, unsigned long long value, int value_width,
					char *value_str)
{
	int		readed;

	readed = 0;
	(ft_strchr(seq->flag, '#') != NULL && value > 0) ? value_width++ : 0;
	seq->precision = (seq->precision_dot != '.' && ft_strchr(seq->flag, '0')
		!= NULL && value > 0) ? seq->width : seq->precision;
	if (seq->precision > value_width)
		readed += write_given_symb(' ', seq->width - value_width -
		(seq->precision - value_width));
	else
		readed += write_given_symb(' ', seq->width - value_width);
	if (ft_strchr(seq->flag, '#') != NULL && value > 0)
	{
		ft_putchar('0');
		readed++;
	}
	if (seq->precision <= value_width)
		readed += ft_putstrn(value_str, (value == 0 && seq->precision_dot == '.'
		&& seq->precision == 0 ? 0 : ft_strlen(value_str)));
	else
	{
		readed += write_given_symb('0', seq->precision - value_width);
		readed += ft_putstrn(value_str, ft_strlen(value_str));
	}
	return (readed);
}

static int	ho_2__(t_sequence *seq, unsigned long long value, char *value_str)
{
	int		readed;

	readed = 0;
	if (ft_strchr(seq->flag, '#') != NULL)
		ft_putchar('0');
	if (ft_strchr(seq->flag, '#') != NULL)
		readed++;
	if (!(value == 0 && ft_strchr(seq->flag, '#') != NULL))
		readed += ft_putstrn(value_str, value == 0 &&
			seq->precision_dot == '.' && seq->precision == 0 ? 0 :
			ft_strlen(value_str));
	return (readed);
}

int			handle_octal__(t_sequence *seq, va_list *va_list_)
{
	unsigned long long	value;
	int					value_width;
	char				*value_str;
	int					readed;

	readed = 0;
	choose_u_type__(&value, seq, va_list_);
	value_width = value == 0 && seq->precision_dot == '.' &&
		seq->precision == 0 ? 0 : ft_value_width__(value, 8);
	value_str = ft_uitoa_base(value, "01234567");
	if (seq->width > seq->precision && seq->width > value_width)
		readed = (ft_strchr(seq->flag, '-') != NULL) ?
		ho_0__(seq, value, value_width, value_str) :
		ho_1__(seq, value, value_width, value_str);
	else if (seq->precision >= seq->width && seq->precision > value_width)
	{
		readed += write_given_symb('0', seq->precision - value_width);
		readed += ft_putstrn(value_str, ft_strlen(value_str));
	}
	else
		readed = ho_2__(seq, value, value_str);
	free(value_str);
	return (readed);
}
