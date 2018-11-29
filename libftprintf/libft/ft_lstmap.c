/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpshenyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 12:05:45 by kpshenyc          #+#    #+#             */
/*   Updated: 2018/10/28 15:46:49 by kpshenyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_list;
	t_list	*start;

	if (!lst || !f)
		return (NULL);
	new_list = ft_lstnew((f(lst))->content, (f(lst))->content_size);
	if (!new_list)
		return (NULL);
	start = new_list;
	lst = lst->next;
	while (lst)
	{
		new_list->next = ft_lstnew((f(lst))->content, (f(lst))->content_size);
		if (!(new_list->next))
			return (NULL);
		new_list = new_list->next;
		lst = lst->next;
	}
	return (start);
}
