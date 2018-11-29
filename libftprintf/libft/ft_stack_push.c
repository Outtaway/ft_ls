/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpshenyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 18:30:40 by kpshenyc          #+#    #+#             */
/*   Updated: 2018/10/27 18:30:41 by kpshenyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_stack	*ft_stack_push(t_stack **stack, void *data, size_t data_size)
{
	t_stack	*temp;

	if (!*stack)
	{
		*stack = (t_stack *)malloc(sizeof(t_stack));
		if (!*stack)
			return (NULL);
		(*stack)->content = malloc(data_size);
		(*stack)->content = ft_memcpy((*stack)->content, data, data_size);
		(*stack)->content_size = data_size;
		(*stack)->next = NULL;
		(*stack)->previous = NULL;
	}
	else
	{
		temp = (t_stack *)malloc(sizeof(t_stack));
		temp->content = malloc(data_size);
		temp->content = ft_memcpy(temp->content, data, data_size);
		temp->content_size = data_size;
		temp->next = NULL;
		temp->previous = (*stack);
		(*stack) = temp;
	}
	return (*stack);
}
