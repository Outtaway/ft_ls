/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpshenyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 17:22:25 by kpshenyc          #+#    #+#             */
/*   Updated: 2018/10/24 17:22:26 by kpshenyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	size_t					i;
	int						minus;
	unsigned long long int	res;

	res = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		++i;
	minus = (str[i] == '-') ? -1 : 1;
	i = (str[i] == '-' || str[i] == '+') ? ++i : i;
	while (str[i] >= 48 && str[i] <= 57 && str[i] != '\0')
	{
		if ((res > 922337203685477580 || (res == 922337203685477580
		&& (str[i] - '0') > 7)) && minus == 1)
			return (-1);
		else if ((res > 922337203685477580 || (res == 922337203685477580
			&& (str[i] - '0') > 8)) && minus == -1)
			return (0);
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (int)(res * minus);
}
