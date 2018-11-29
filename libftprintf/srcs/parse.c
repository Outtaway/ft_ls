/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpshenyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 13:18:11 by kpshenyc          #+#    #+#             */
/*   Updated: 2018/11/10 13:18:39 by kpshenyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		specifier__(char *format, int *i, t_sequence *seq)
{
	char	*valid_specifiers;
	char	*temp;

	valid_specifiers = ft_strdup("cCsSdDiuUoOxXpFbfQ\%");
	temp = valid_specifiers;
	if (format[*i])
	{
		while (*valid_specifiers)
		{
			if (format[*i] == *valid_specifiers)
			{
				seq->specifier = format[(*i)++];
				break ;
			}
			++valid_specifiers;
		}
	}
	free(temp);
	return (0);
}

int		length__(char *format, int *i, t_sequence *seq)
{
	if (format[*i])
	{
		if (format[*i] == 'h')
			seq->length[0] = 'h';
		else if (format[*i] == 'l')
			seq->length[0] = 'l';
		else if (format[*i] == 'L')
			seq->length[0] = 'L';
		else if (format[*i] == 'j')
			seq->length[0] = 'j';
		else if (format[*i] == 'z')
			seq->length[0] = 'z';
		seq->length[1] = ((format[*i + 1] == 'h' || format[*i + 1] == 'l')
			&& seq->length[0]) ? format[*i + 1] : '\0';
		(seq->length[0]) ? ++(*i) : 0;
		(seq->length[1]) ? ++(*i) : 0;
		__ERR_STATE(specifier__(format, i, seq));
	}
	return (0);
}

int		precision__(char *format, int *i, t_sequence *seq, va_list *va_list_)
{
	if (format[*i])
	{
		if (format[*i] == '.')
		{
			seq->precision_dot = '.';
			++(*i);
			if (format[*i] == '*')
			{
				seq->precision = va_arg(*va_list_, int);
				++(*i);
			}
			else
			{
				seq->precision = ft_atoi(format + *i);
				while (((format[*i] >= '0' && format[*i] <= '9') ||
				format[*i] == '-') && format[*i])
					++(*i);
			}
		}
		__ERR_STATE(length__(format, i, seq));
	}
	return (0);
}

int		width__(char *format, int *i, t_sequence *seq, va_list *va_list_)
{
	char	*temp;

	if (format[*i])
	{
		seq->width = ft_atoi(format + *i);
		while (((format[*i] >= '0' && format[*i] <= '9') ||
		format[*i] == '-') && format[*i])
			++(*i);
	}
	if (format[*i] == '*')
	{
		seq->width = va_arg(*va_list_, int);
		if (seq->width < 0)
		{
			seq->width *= -1;
			temp = ft_strnew(1 + ft_strlen(seq->flag));
			ft_strcpy(temp, "-");
			ft_strcat(temp, seq->flag);
			free(seq->flag);
			seq->flag = temp;
		}
		++(*i);
	}
	__ERR_STATE(precision__(format, i, seq, va_list_));
	return (0);
}

int		flags__(char *format, int *i, t_sequence *seq, va_list *va_list_)
{
	int		j;

	if (format[*i])
	{
		j = *i;
		while ((format[j] == '#' || format[j] == '0' || format[j] == '-' ||
			format[j] == ' ' || format[j] == '+') && format[j])
			++j;
		seq->flag = ft_strnew(j - *i);
		seq->flag = ft_strncpy(seq->flag, format + *i, j - *i);
		*i = j;
		__ERR_STATE(width__(format, i, seq, va_list_));
	}
	return (0);
}
