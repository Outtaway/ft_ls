/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpshenyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 16:44:27 by kpshenyc          #+#    #+#             */
/*   Updated: 2018/10/23 16:44:28 by kpshenyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	size_t	size;
	char	*res;

	i = 0;
	size = ft_strlen(s1);
	res = (char *)ft_memalloc(size + 1);
	if (!res)
		return (NULL);
	while (i < size)
	{
		res[i] = s1[i];
		++i;
	}
	res[i] = '\0';
	return (res);
}
