/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_float.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpshenyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 14:50:57 by kpshenyc          #+#    #+#             */
/*   Updated: 2018/11/26 18:43:13 by kpshenyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		value_size__(long double value, t_sequence *seq)
{
	int			width;

	width = ((value < 0) || (value >= 0 && ft_strchr(seq->flag, '+'))) ? 1 : 0;
	value = value < 0 ? -value : value;
	width += ft_128value_width((__uint128_t)value, 10);
	if (seq->precision_dot == '.' && seq->precision > 0)
		width = width + seq->precision + 1;
	else if (seq->precision_dot != '.')
	{
		seq->precision = 6;
		seq->precision_dot = '.';
		width += 7;
	}
	else if (ft_strchr(seq->flag, '#') != NULL)
		width += 1;
	return (width);
}

void	get_round_value(long double *value, int precision)
{
	long double temp;
	long double b;
	int			i;

	b = 1;
	i = 0;
	*value = (*value < 0) ? -(*value) : *value;
	temp = (*value - (__uint128_t)(*value)) * 10;
	while (i < precision)
	{
		temp = (temp - (__uint128_t)temp);
		temp = temp * 10;
		b /= 10.0;
		++i;
	}
	if (temp >= 5)
		*value += b;
}

int		hf_0__(t_sequence *seq, char *value_str)
{
	int		readed;
	int		i;

	i = 0;
	readed = 0;
	i = (value_str[0] == '-' || value_str[0] == '+') ? 1 : 0;
	if (ft_strchr(seq->flag, '0') != NULL)
	{
		readed += (i) ? ft_putchar(value_str[0]) : 0;
		readed += write_given_symb('0', seq->width - ft_strlen(value_str));
	}
	else
	{
		readed += write_given_symb(' ', seq->width - ft_strlen(value_str));
		readed += (i) ? ft_putchar(value_str[0]) : 0;
	}
	readed += ft_putstrn(value_str + i, ft_strlen(value_str + i));
	return (readed);
}

char	*value_str__(long double value, t_sequence *seq)
{
	char		*res;
	char		*int_part;
	int			i;
	int			j;

	i = 0;
	res = ft_strnew(value_size__(value, seq));
	if (value < 0)
		res[i++] = '-';
	else if (value >= 0 && ft_strchr(seq->flag, '+') != NULL)
		res[i++] = '+';
	get_round_value(&value, seq->precision);
	int_part = ft_128itoa_base(value, "0123456789");
	ft_strcpy(res + i--, int_part);
	j = ft_strlen(res);
	(seq->precision > 0 || !(ft_strchr(seq->flag, '#'))) ? res[j++] = '.' : 0;
	while (((res[0] == '-' || res[0] == '+') ? ++i - 1 : ++i) < seq->precision)
	{
		value = (value - (__uint128_t)value) * 10;
		res[j++] = ((__uint128_t)value) + 48;
	}
	free(int_part);
	return (res);
}

int		handle_float__(t_sequence *seq, va_list *va_list_)
{
	long double value;
	char		*value_str;
	int			readed;

	readed = 0;
	if (seq->length[0] == 'L')
		value = va_arg(*va_list_, long double);
	else
		value = (long double)va_arg(*va_list_, double);
	value_str = value_str__(value, seq);
	if (ft_strchr(seq->flag, '-') != NULL)
	{
		readed = ft_putstrn(value_str, ft_strlen(value_str));
		readed += write_given_symb(' ', seq->width - ft_strlen(value_str));
	}
	else
		readed += hf_0__(seq, value_str);
	free(value_str);
	return (readed);
}
