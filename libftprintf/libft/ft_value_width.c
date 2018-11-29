/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_value_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpshenyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 15:22:01 by kpshenyc          #+#    #+#             */
/*   Updated: 2018/11/16 15:22:03 by kpshenyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_value_width__(unsigned long long int value, int base)
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
