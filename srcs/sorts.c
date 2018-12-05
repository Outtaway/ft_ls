/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpshenyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 16:24:57 by kpshenyc          #+#    #+#             */
/*   Updated: 2018/11/29 16:24:58 by kpshenyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		name_cmp(t_list_ *a, t_list_ *b)
{
	return (ft_strcmp(b->path_name, a->path_name));
}

int		last_modification_cmp(t_list_ *a, t_list_ *b)
{
	return (b->stat_obj->st_mtimespec.tv_sec <=
				a->stat_obj->st_mtimespec.tv_sec);
}

t_list_		*sorted_parts(t_list_ *left, t_list_ *right, int (*f)(t_list_ *,
		t_list_ *))
{
	t_list_ *merged;
	
	merged = NULL;
	if (left == NULL)
		return (right);
	else if (right == NULL)
		return (left);
	if (f(left, right) > 0)
	{ 
		merged = left;
		merged->next = sorted_parts(left->next, right, f);
	} 
	else
	{
		merged = right;
		merged->next = sorted_parts(left, right->next, f);
	}
	return (merged);
}

void divide_list(t_list_ *list, t_list_ **left, t_list_ **right)
{ 
	t_list_ *fast;
	t_list_ *slow;

	slow = list;
	fast = list->next;
	while (fast != NULL)
	{
		fast = fast->next;
		if (fast != NULL)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}
	*left = list;
	*right = slow->next;
	slow->next = NULL;
} 

void	sort_list(t_list_ **list, int (*f)(t_list_ *, t_list_ *))
{
	t_list_ *list_;
	t_list_ *left;
	t_list_ *right;


	list_ = *list;
	if (list_ == NULL || list_->next == NULL) 
	{
		return;
	} 
	divide_list(list_, &left, &right);
	sort_list(&left, f);
	sort_list(&right, f);
	*list = sorted_parts(left, right, f);
}
