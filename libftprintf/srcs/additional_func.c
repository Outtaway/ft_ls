/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_func.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpshenyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 17:26:46 by kpshenyc          #+#    #+#             */
/*   Updated: 2018/11/13 17:27:11 by kpshenyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		write_given_symb(char c, int num)
{
	int		i;

	i = -1;
	while (++i < num)
		write(1, &c, 1);
	return (i);
}

void	choose_type__(long long *value, t_sequence *seq,
				va_list *va_list_)
{
	if (!ft_strcmp(seq->length, "l") || seq->specifier == 'D')
		*value = (long)va_arg(*va_list_, long long);
	else if (!ft_strcmp(seq->length, "ll"))
		*value = (long long)va_arg(*va_list_, long long);
	else if (!ft_strcmp(seq->length, "h"))
		*value = (short)va_arg(*va_list_, long long);
	else if (!ft_strcmp(seq->length, "hh"))
		*value = (signed char)va_arg(*va_list_, long long);
	else if (!ft_strcmp(seq->length, "j"))
		*value = (intmax_t)va_arg(*va_list_, unsigned long long);
	else if (!ft_strcmp(seq->length, "z"))
		*value = (size_t)va_arg(*va_list_, unsigned long long);
	else if (!ft_strcmp(seq->length, ""))
		*value = (int)va_arg(*va_list_, long long);
}

void	choose_u_type__(unsigned long long *value, t_sequence *seq,
							va_list *va_list_)
{
	if (!ft_strcmp(seq->length, "l") || seq->specifier == 'O' ||
		seq->specifier == 'U')
		*value = (unsigned long)va_arg(*va_list_, unsigned long long);
	else if (!ft_strcmp(seq->length, "ll"))
		*value = (unsigned long long)va_arg(*va_list_, unsigned long long);
	else if (!ft_strcmp(seq->length, "h"))
		*value = (unsigned short)va_arg(*va_list_, unsigned long long);
	else if (!ft_strcmp(seq->length, "hh"))
		*value = (unsigned char)va_arg(*va_list_, unsigned long long);
	else if (!ft_strcmp(seq->length, "j"))
		*value = (uintmax_t)va_arg(*va_list_, unsigned long long);
	else if (!ft_strcmp(seq->length, "z"))
		*value = (size_t)va_arg(*va_list_, unsigned long long);
	else
		*value = (unsigned)va_arg(*va_list_, unsigned long long);
}
