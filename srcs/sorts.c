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



// t_list_	*sort_list(t_list_ **list, int length)
// {
// 	t_list_ *left;
// 	t_list_ *right;
// 	int		i;

// 	if (length == 1)
// 		return (*list);
// 	i = -1;
// 	left = *list;
// 	right = *list;
// 	while (++i < length / 2)
// 		*right = *right->next;
// 	sort_list(&left, length / 2);
// 	sort_list(&right, length - length / 2);
// 	*list = merge_list(left, right);
// }

// void	sort_list_ascii(t_list_ *list)
// {

// }
