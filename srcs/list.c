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

#include "list.h"

t_list_	*add_node(t_list_ *list, struct stat *data)
{
	t_list_	*head;

	head = list;
	if (list == NULL)
	{
		list = (t_list_ *)malloc(sizeof(t_list_));
		list->stat_obj = data;
		list->next = NULL;
		list->prev = NULL;
	}
	else
	{
		while(list->next)
			list = list->next;
		list->next = (t_list_ *)malloc(sizeof(t_list_));
		list->next->prev = list;
		list->next->next = NULL;
		list->next->stat_obj = data;
		list = list->next;
	}
	return (head ? head : list);
}

void	print_list(t_list_ *list)
{
	while (list)
		list = list->next;
}