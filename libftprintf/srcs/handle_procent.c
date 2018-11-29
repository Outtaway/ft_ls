/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_procent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpshenyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 16:09:52 by kpshenyc          #+#    #+#             */
/*   Updated: 2018/11/20 16:09:53 by kpshenyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		handle_procent__(t_sequence *seq)
{
	int readed;

	readed = 0;
	seq->width = ft_strchr(seq->flag, '-') != NULL ? -(seq->width) : seq->width;
	if (ft_strchr(seq->flag, '0') != NULL)
		readed += write_given_symb('0', seq->width - 1);
	else
		readed += write_given_symb(' ', seq->width - 1);
	readed += 1;
	ft_putchar('%');
	readed += write_given_symb(' ', -(seq->width) - 1);
	return (readed);
}
