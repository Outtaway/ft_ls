/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpshenyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 17:33:16 by kpshenyc          #+#    #+#             */
/*   Updated: 2018/10/25 17:33:19 by kpshenyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	end;
	char	*str;
	size_t	start;

	if (s)
	{
		start = 0;
		end = ft_strlen(s) - 1;
		while ((s[start] == ' ' || s[start] == '\t' ||
			s[start] == '\n') && s[start] != '\0')
			++start;
		if (start == end + 1)
			return (ft_strdup(""));
		while (s[end] == ' ' || s[end] == '\t' || s[end] == '\n')
			--end;
		str = ft_strnew(end - start + 1);
		if (str)
		{
			ft_strncpy(str, s + start, end - start + 1);
			return (str);
		}
	}
	return (NULL);
}
