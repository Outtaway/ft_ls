/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpshenyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 14:14:48 by kpshenyc          #+#    #+#             */
/*   Updated: 2018/10/24 14:14:49 by kpshenyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	conv;
	size_t	i;

	i = 0;
	conv = (char)c;
	while (s[i])
	{
		if (conv == s[i])
			return ((char *)(s + i));
		++i;
	}
	if (conv == '\0')
		return (char *)(s + i);
	return (NULL);
}
