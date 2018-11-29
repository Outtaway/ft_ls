/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpshenyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 14:28:00 by kpshenyc          #+#    #+#             */
/*   Updated: 2018/10/23 14:28:01 by kpshenyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	size_t	i;
	char	*res;

	res = (char *)malloc(size);
	if (!res)
		return (NULL);
	i = 0;
	while (i < size)
		res[i++] = 0;
	return ((void *)res);
}
