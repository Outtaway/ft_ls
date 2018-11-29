/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_clear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpshenyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 11:22:41 by kpshenyc          #+#    #+#             */
/*   Updated: 2018/10/28 11:22:43 by kpshenyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_stack	*ft_stack_clear(t_stack **stack)
{
	t_stack *temp;

	while (*stack)
	{
		temp = (*stack);
		(*stack) = (*stack)->previous;
		(*stack)->next = NULL;
		free(temp->content);
		temp->content = NULL;
		temp->content_size = 0;
		temp->previous = NULL;
		temp->next = NULL;
		free(temp);
		*stack = NULL;
	}
	return (*stack);
}
