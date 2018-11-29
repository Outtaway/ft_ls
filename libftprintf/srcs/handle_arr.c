/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_arr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpshenyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 15:48:35 by kpshenyc          #+#    #+#             */
/*   Updated: 2018/11/23 15:48:36 by kpshenyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	print_sarr(char *arr, int rows, int columns)
{
	int		readed;
	int		cols;
	int		i;

	cols = 0;
	readed = 0;
	i = 0;
	while (i < rows)
	{
		readed += ft_putstrn(arr + cols, ft_strlen(arr + cols));
		readed += ft_putchar('\n');
		cols += columns + 1;
		++i;
	}
	return (readed);
}

static int	print_darr(int *arr, int rows, int columns)
{
	int		readed;
	int		damn;
	int		i;
	int		j;

	j = 0;
	i = -1;
	damn = 0;
	readed = 0;
	while (++i < rows)
	{
		j = 0;
		while (j < columns)
			ft_putlong(*(arr + damn + j++));
		readed += ft_putchar('\n');
		damn += columns;
	}
	return (readed);
}

int			handle_arr__(t_sequence *seq, va_list *va_list_)
{
	int		readed;
	int		*d_arr;
	char	*s_arr;
	int		rows;
	int		columns;

	rows = va_arg(*va_list_, int);
	columns = va_arg(*va_list_, int);
	if (ft_strcmp(seq->length, "z") == 0)
	{
		s_arr = va_arg(*va_list_, char *);
		readed = print_sarr(s_arr, rows, columns);
	}
	else
	{
		d_arr = va_arg(*va_list_, int *);
		readed = print_darr(d_arr, rows, columns);
	}
	return (readed);
}
