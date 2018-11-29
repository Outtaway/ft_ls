/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_128itoa_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpshenyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 12:03:50 by kpshenyc          #+#    #+#             */
/*   Updated: 2018/11/24 12:03:51 by kpshenyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_128itoa_base(__uint128_t value, char *base)
{
	char	*str;
	int		value_width;
	int		denominator;

	denominator = ft_strlen(base);
	value_width = ft_128value_width(value, denominator);
	str = ft_strnew(value_width);
	while (value_width--)
	{
		str[value_width] = base[value % denominator];
		value /= denominator;
	}
	return (str);
}
