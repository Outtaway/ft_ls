/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_binary.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpshenyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 16:44:54 by kpshenyc          #+#    #+#             */
/*   Updated: 2018/11/20 16:46:33 by kpshenyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			handle_binary__(t_sequence *seq, va_list *va_list_)
{
	unsigned long long		value;
	char					*value_str;
	int						readed;

	readed = 0;
	choose_u_type__(&value, seq, va_list_);
	value_str = ft_uitoa_base(value, "01");
	if ((size_t)seq->width > ft_strlen(value_str) && ft_strchr(seq->flag, '-')
	== NULL)
		readed += write_given_symb(' ', seq->width - (int)ft_strlen(value_str));
	readed += ft_putstrn(value_str, ft_strlen(value_str));
	if ((size_t)seq->width > ft_strlen(value_str) && ft_strchr(seq->flag, '-')
	!= NULL)
		write_given_symb(' ', seq->width - (int)ft_strlen(value_str));
	free(value_str);
	return (readed);
}
