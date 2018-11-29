/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpshenyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 15:04:45 by kpshenyc          #+#    #+#             */
/*   Updated: 2018/10/28 15:50:17 by kpshenyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
				str[i] = f(i, s[i]);
				++i;
			}
			str[i] = '\0';
			return (str);
		}
	}
	return (NULL);
}
