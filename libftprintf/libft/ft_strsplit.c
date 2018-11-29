/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpshenyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 14:46:30 by kpshenyc          #+#    #+#             */
/*   Updated: 2018/10/26 14:46:31 by kpshenyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	words(char const *s, char c)
{
	size_t i;
	size_t words;

	words = 0;
	i = 0;
	while (1)
	{
		while (s[i] == c)
			++i;
		if (s[i] == '\0')
			break ;
		words++;
		while (s[i] != c && s[i] != '\0')
			++i;
		if (s[i] == '\0')
			break ;
	}
	return (words);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**arr;
	int		i;
	size_t	temp;
	size_t	j;

	if (!s)
		return (NULL);
	if (!(arr = (char **)malloc((words(s, c) + 1) * sizeof(char *))))
		return (NULL);
	j = 0;
	i = -1;
	while (++i >= 0)
	{
		while (s[j] == c && s[j] != '\0')
			++j;
		if (s[j] == '\0')
			break ;
		temp = j;
		while (s[j] != c && s[j] != '\0')
			++j;
		arr[i] = ft_strnew(j - temp);
		arr[i] = ft_strncpy(arr[i], s + temp, j - temp);
	}
	arr[i] = (NULL);
	return (arr);
}
