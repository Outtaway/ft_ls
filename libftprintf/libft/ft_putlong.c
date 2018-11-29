/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlong.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpshenyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 11:11:13 by kpshenyc          #+#    #+#             */
/*   Updated: 2018/11/15 11:11:14 by kpshenyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putlong(long long nb)
{
	unsigned long long nb_copy;

	if (nb < 0)
		ft_putchar('-');
	nb_copy = (nb < 0) ? (unsigned long long)(-nb) : (unsigned long long)nb;
	if (nb_copy < 10 && nb > -10)
		ft_putchar((nb_copy % 10) + 48);
	else
	{
		ft_putlong((long long)nb_copy / 10);
		ft_putlong((long long)nb_copy % 10);
	}
}
