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

#include "list.h"


// void	merge(int *arr, int left_size, int right_size)
// {
// 	int		*temp;
// 	int		i;
// 	int 	j;
// 	int 	k;

// 	temp = (int *)malloc(sizeof(int) * (left_size + right_size));
// 	i = 0;
// 	j = left_size;
// 	k = 0;
// 	while (i < left_size && j < right_size + left_size)
// 	{
// 		if (arr[i] <= arr[j])
// 			temp[k] = arr[i++];
// 		else
// 			temp[k] = arr[j++];
// 		++k;
// 	}
// 	while (i < left_size) {
// 		temp[k] = arr[i++];
// 		++k;
// 	}
// 	while (j < right_size + left_size) {
// 		temp[k] = arr[j++];
// 		++k;
// 	}
// 	i = -1;
// 	while (++i < left_size + right_size)
// 		arr[i] = temp[i];
// }
// void	merge_sort(int *arr, int length)
// {
// 	if (length == 1)
// 		return ;
// 	merge_sort(arr, length / 2);
// 	merge_sort(arr + length / 2, length - length / 2);
// 	merge(arr, length / 2, length - length / 2);
// }


// t_list_ 	*merge_list(t_list_ *left, t_list_ *right, int left_size, int right_size)
// {
// 	int		i;
// 	int 	j;
// 	int 	k;
// 	t_list_ *temp;
// 	temp = (int *)malloc(sizeof(int) * (left_size + right_size));
// 	i = 0;
// 	j = left_size;
// 	k = 0;
// 	while (i < left_size && j < right_size + left_size)
// 	{
// 		if (left->stat_obj->st_mtimespec.tv_sec <= right->stat_obj->st_mtimespec.tv_sec)
// 		{
// 			temp = left->next;
// 			temp->next = 
// 		}
// 		else
// 			temp[k] = arr[j++];
// 		++k;
// 	}
// 	while (i < left_size) {
// 		temp[k] = arr[i++];
// 		++k;
// 	}
// 	while (j < right_size + left_size) {
// 		temp[k] = arr[j++];
// 		++k;
// 	}
// 	i = -1;
// 	while (++i < left_size + right_size)
// 		arr[i] = temp[i];
// }

int		name_cmp(t_list_ *a, t_list_ *b)
{
	return (ft_strcmp(b->path_name, a->path_name));
}

int		last_modification_cmp(t_list_ *a, t_list_ *b)
{
	return (b->stat_obj->st_mtimespec.tv_sec < a->stat_obj->st_mtimespec.tv_sec);
}

t_list_		*sorted_parts(t_list_ *left, t_list_ *right, int (*f)(t_list_ *, t_list_ *))
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
