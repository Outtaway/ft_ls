/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpshenyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 16:29:28 by kpshenyc          #+#    #+#             */
/*   Updated: 2018/10/23 16:29:29 by kpshenyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	conv;
	size_t			i;

	i = 0;
	conv = (unsigned char)c;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == conv)
			return ((unsigned char *)s + i);
		++i;
	}
	return (NULL);
}
