/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpshenyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 14:50:56 by kpshenyc          #+#    #+#             */
/*   Updated: 2018/10/24 14:50:59 by kpshenyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	conv;
	size_t	i;
	char	*found;

	found = NULL;
	i = 0;
	conv = (char)c;
	while (s[i])
	{
		if (conv == s[i])
			found = (char *)(s + i);
		++i;
	}
	if (conv == '\0')
		found = (char *)(s + i);
	if (found != NULL)
		return (found);
	return (NULL);
}
