/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpshenyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 15:32:46 by kpshenyc          #+#    #+#             */
/*   Updated: 2018/10/23 15:32:47 by kpshenyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src,
	int c, size_t n)
{
	size_t			i;
	unsigned char	conv;

	conv = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (((unsigned char *)src)[i] == conv)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			return (dst + i + 1);
		}
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		++i;
	}
	return (NULL);
}
