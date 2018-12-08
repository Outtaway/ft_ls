/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpshenyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 15:19:41 by kpshenyc          #+#    #+#             */
/*   Updated: 2018/12/04 15:19:44 by kpshenyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*get_fact_name(char *full_path, enum e_obj_type type)
{
	if (type == __DIRECTORY)
	{
		if (ft_strrchr(full_path, '/') == NULL)
			return (full_path);
		return (ft_strrchr(full_path, '/') + 1);
	}
	return (full_path);
}

void	print_symbolic_link(t_list_ *list)
{
	char	buff[128];

	ft_bzero(buff, 128);
	write(1, " -> ", 4);
	readlink(list->path_name, buff, 128);
	write(1, buff, ft_strlen(buff));
}

char *create_name(char *prev, char *new)
{
	char *temp;

	temp = ft_strnew(ft_strlen(prev) + ft_strlen(new) + 1);
	temp = ft_strncpy(temp, prev, ft_strlen(prev));
	temp[ft_strlen(temp)] = '/';
	temp = ft_strncat(temp, new, ft_strlen(new));
	return (temp);
}
