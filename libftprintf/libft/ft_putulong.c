/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putulong.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpshenyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 16:41:11 by kpshenyc          #+#    #+#             */
/*   Updated: 2018/11/19 16:41:15 by kpshenyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putulong(unsigned long long value)
{
	int		to_ret;

	to_ret = 1;
	if (value < 10)
		ft_putchar((value % 10) + 48);
	else
	{
		to_ret += ft_putulong(value / 10);
		ft_putulong(value % 10);
	}
	return (to_ret);
}
