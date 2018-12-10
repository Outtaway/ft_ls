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

int			name_cmp(t_list_ *a, t_list_ *b)
{
	return (ft_strcmp(b->path_name, a->path_name));
}

int			last_modification_cmp(t_list_ *a, t_list_ *b)
{
	return (b->stat_obj->st_mtimespec.tv_sec <=
				a->stat_obj->st_mtimespec.tv_sec);
}

t_list_		*sorted_parts(t_list_ *left, t_list_ *right, int (*f)(t_list_ *,
		t_list_ *), t_options *opt)
{
	t_list_ *merged;

	if (!left)
		return (right);
	if (!right)
		return (left);
	if ((f(left, right) > 0 && !opt->r) || (f(left, right) <= 0 && opt->r))
	{
		merged = left;
		merged->next = sorted_parts(left->next, right, f, opt);
	}
	else
	{
		merged = right;
		merged->next = sorted_parts(left, right->next, f, opt);
	}
	return (merged);
}

void		divide_list(t_list_ *list, t_list_ **left, t_list_ **right)
{
	t_list_ *x2;
	t_list_ *x;

	x = list;
	x2 = list->next;
	while (x2 != NULL)
	{
		x2 = x2->next;
		if (x2 != NULL)
		{
			x = x->next;
			x2 = x2->next;
		}
	}
	*right = x->next;
	x->next = NULL;
	*left = list;
}

void		sort_list(t_list_ **list, int (*f)(t_list_ *, t_list_ *),
						t_options *opt)
{
	t_list_ *temp;
	t_list_ *left;
	t_list_ *right;

	temp = *list;
	if (temp == NULL || temp->next == NULL)
		return ;
	divide_list(temp, &left, &right);
	sort_list(&left, f, opt);
	sort_list(&right, f, opt);
	*list = sorted_parts(left, right, f, opt);
}
