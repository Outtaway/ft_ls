/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpshenyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 11:05:01 by kpshenyc          #+#    #+#             */
/*   Updated: 2018/11/29 11:05:03 by kpshenyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_list_	*add_node(t_list_ *list, struct stat *data, char *path)
{
	t_list_	*head;

	head = list;
	if (list == NULL)
	{
		list = (t_list_ *)malloc(sizeof(t_list_));
		list->stat_obj = data;
		list->path_name = path;
		list->next = NULL;
	}
	else
	{
		while(list->next)
			list = list->next;
		list->next = (t_list_ *)malloc(sizeof(t_list_));
		list->next->stat_obj = data;
		list->next->path_name = path;
		list->next->next = NULL;
		list = list->next;
	}
	return (head ? head : list);
}

void	print_list(t_list_ *list)
{
	while (list)
	{
		ft_printf("%p\n", list);
		list = list->next;
	}
}

void	free_list(t_list_ **list)
{
	t_list_ *temp;

	while ((*list))
	{
		temp = (*list);
		(*list) = (*list)->next;
		temp->next = NULL;
		free(temp->path_name);
		temp->path_name = NULL;
		free(temp->stat_obj);
		temp->stat_obj = NULL;
		free(temp);
		temp = NULL;
	}
}

int		list_size(t_list_ *list)
{
	int		i;

	i = 0;
	while (list)
	{
		list = list->next;
		++i;
	}
	return (i);
}