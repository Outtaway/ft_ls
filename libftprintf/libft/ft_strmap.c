/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpshenyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 16:16:44 by kpshenyc          #+#    #+#             */
/*   Updated: 2018/10/28 15:44:44 by kpshenyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	size_t	i;

	if (s && f)
	{
		i = 0;
		str = (char *)malloc(ft_strlen(s) + 1);
		if (str)
		{
			while (s[i])
			{
				str[i] = f(s[i]);
				++i;
			}
			str[i] = '\0';
			return (str);
		}
	}
	return (NULL);
}
