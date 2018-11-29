/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpshenyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 14:21:46 by kpshenyc          #+#    #+#             */
/*   Updated: 2018/10/23 14:21:47 by kpshenyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	conv;
	size_t			i;
	char			*res;

	res = (char *)b;
	i = 0;
	conv = (unsigned char)c;
	while (i < len)
		res[i++] = conv;
	return ((void *)res);
}
