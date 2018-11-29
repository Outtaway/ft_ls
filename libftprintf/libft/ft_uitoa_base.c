/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpshenyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 19:19:54 by kpshenyc          #+#    #+#             */
/*   Updated: 2018/11/16 19:19:55 by kpshenyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_uitoa_base(unsigned long long int value, char *base)
{
	char	*str;
	int		value_width;
	int		denominator;

	denominator = ft_strlen(base);
	value_width = ft_value_width__(value, denominator);
	str = ft_strnew(value_width);
	while (value_width--)
	{
		str[value_width] = base[value % denominator];
		value /= denominator;
	}
	return (str);
}
