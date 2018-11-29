/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_pop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpshenyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 19:01:37 by kpshenyc          #+#    #+#             */
/*   Updated: 2018/10/27 19:01:38 by kpshenyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_stack_pop(t_stack **stack)
{
	t_stack		*temp;

	if (!stack)
		return ;
	else
	{
		temp = (*stack);
		(*stack) = (*stack)->previous;
		(*stack)->next = NULL;
		temp->next = NULL;
		temp->previous = NULL;
		temp->content_size = 0;
		free(temp->content);
		free(temp);
	}
}
