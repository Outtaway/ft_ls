/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpshenyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 16:58:31 by kpshenyc          #+#    #+#             */
/*   Updated: 2018/11/12 16:58:33 by kpshenyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			count_bytes(int symb_)
{
	int		bytes_;

	if (symb_ <= __7_BIT)
		bytes_ = 1;
	else if (symb_ <= __11_BIT)
		bytes_ = 2;
	else if (symb_ <= __16_BIT)
		bytes_ = 3;
	else
		bytes_ = 4;
	return (bytes_);
}

void		set_uni_mask(int bytes_, int bytes_iter_, int *uni_mask_)
{
	if (bytes_iter_ > 0)
		*uni_mask_ = __UTF_8_MASK_1;
	else
	{
		if (bytes_ == 1)
			*uni_mask_ = __UTF_8_MASK_0;
		else if (bytes_ == 2)
			*uni_mask_ = __UTF_8_MASK_2;
		else if (bytes_ == 3)
			*uni_mask_ = __UTF_8_MASK_3;
		else if (bytes_ == 4)
			*uni_mask_ = __UTF_8_MASK_4;
	}
}

void		set_user_mask(int bytes_, int bytes_iter_, int *user_mask_)
{
	if (bytes_iter_ > 0)
		*user_mask_ = __MASK_1;
	else
	{
		if (bytes_ == 1)
			*user_mask_ = __MASK_0;
		else if (bytes_ == 2)
			*user_mask_ = __MASK_2;
		else if (bytes_ == 3)
			*user_mask_ = __MASK_3;
		else if (bytes_ == 4)
			*user_mask_ = __MASK_4;
	}
}

__BYTE_SEQ	to_write__(int symb_, int *bytes_)
{
	int			uni_mask_;
	int			user_mask_;
	int			i;
	__BYTE_SEQ	to_write_;
	int			bytes_iter_;

	i = 0;
	*bytes_ = count_bytes(symb_);
	bytes_iter_ = *bytes_ - 1;
	to_write_ = (__BYTE_SEQ)malloc(sizeof(__BYTE) * (*bytes_));
	while (bytes_iter_ >= 0)
	{
		set_uni_mask(*bytes_, bytes_iter_, &uni_mask_);
		set_user_mask(*bytes_, bytes_iter_, &user_mask_);
		to_write_[bytes_iter_--] = uni_mask_ | ((symb_ >> i) & user_mask_);
		i += __SHIFT;
	}
	return (to_write_);
}

int			handle_char__(t_sequence *seq, va_list *va_list_)
{
	int				symb_;
	__BYTE_SEQ		to_write_;
	int				bytes_;
	int				readed;

	readed = 0;
	symb_ = va_arg(*va_list_, int);
	to_write_ = to_write__(symb_, &bytes_);
	seq->width = (ft_strchr(seq->flag, '-') != NULL) ?
		-(seq->width) : seq->width;
	if (seq->width > 0 && ft_strchr(seq->flag, '0'))
		readed += write_given_symb('0', seq->width - bytes_);
	else if (seq->width > 0 && ft_strchr(seq->flag, '0') == NULL)
		readed += write_given_symb(' ', seq->width - bytes_);
	if ((seq->specifier == 'C' || ft_strcmp(seq->length, "l") == 0)
		&& MB_CUR_MAX != 1)
		write(1, to_write_, bytes_);
	else
		write(1, &symb_, 1);
	readed += !ft_strcmp(seq->length, "l") || seq->specifier == 'C'
			? bytes_ : 1;
	if (seq->width < 0)
		readed += write_given_symb(' ', -(seq->width) - bytes_);
	free(to_write_);
	return (readed);
}
