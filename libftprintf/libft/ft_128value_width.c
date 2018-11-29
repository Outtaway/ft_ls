/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_128value_width.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpshenyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 12:04:20 by kpshenyc          #+#    #+#             */
/*   Updated: 2018/11/24 12:04:21 by kpshenyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_128value_width(__uint128_t value, int base)
{
	int		out;

	out = 0;
	while (1)
	{
		++out;
		if (!(value / base))
			break ;
		value /= base;
	}
	return (out);
}
