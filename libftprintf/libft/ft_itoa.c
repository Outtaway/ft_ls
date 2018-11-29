/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpshenyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 17:17:54 by kpshenyc          #+#    #+#             */
/*   Updated: 2018/10/26 17:17:56 by kpshenyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	num_size(long long int n)
{
	int		i;

	i = 0;
	if (n < 0)
		++i;
	while (1)
	{
		++i;
		if (n / 10 == 0)
			break ;
		n /= 10;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	int				i;
	long long int	un;
	char			*str;

	i = 0;
	un = n;
	str = (char *)malloc(num_size(un) + 1);
	if (!str)
		return (NULL);
	str[num_size(un)] = '\0';
	str[0] = (un < 0) ? '-' : 0;
	i = num_size(un) - 1;
	un = (un < 0) ? un * (-1) : un;
	while (i >= 0)
	{
		str[i] = un % 10 + 48;
		if (un / 10 == 0)
			break ;
		un /= 10;
		--i;
	}
	return (str);
}
