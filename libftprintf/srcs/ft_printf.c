/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpshenyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:08:10 by kpshenyc          #+#    #+#             */
/*   Updated: 2018/11/07 16:08:11 by kpshenyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		parse__(char *format, int *i, va_list *va_list_)
{
	t_sequence	seq;
	int			readed;

	seq.flag = NO_FLAG;
	seq.width = NO_WIDTH;
	seq.precision = NO_PRECISION;
	seq.precision_dot = NO_PRECISION;
	ft_bzero(&(seq.length), 3);
	seq.specifier = NO_SPECIFIER;
	readed = 0;
	if (format[*i] == '%')
	{
		++(*i);
		readed = flags__(format, i, &seq, va_list_);
		__ERR_STATE_FREE(readed, seq.flag);
		readed = print_seq__(&seq, va_list_);
		__ERR_STATE_FREE(readed, seq.flag);
		free(seq.flag);
	}
	return (readed);
}

int		print_str_part__(char *format, int *i)
{
	int		j;

	j = 0;
	while (format[*i] != '%' && format[*i])
	{
		++j;
		++(*i);
	}
	ft_putstrn(format + *i - j, j);
	return (j);
}

int		ft_printf(const char *format, ...)
{
	va_list		va_list_;
	int			readed;
	int			i;

	va_start(va_list_, format);
	i = 0;
	readed = 0;
	while (format[i])
	{
		readed += print_str_part__((char *)format, &i);
		readed += parse__((char *)format, &i, &va_list_);
	}
	va_end(va_list_);
	return (readed);
}
