/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:49:49 by ybounite          #+#    #+#             */
/*   Updated: 2025/01/30 20:40:15 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate_stack_a(t_stack_a **stack_a)
{
	t_stack_a *first;
	t_stack_a *last;
	if (!stack_a || !(*stack_a))
		return (0);
	
	first = *stack_a;
	last = *stack_a;
	while (last->next)
		last = last->next;
	last->next = first;
	*stack_a = first->next;
	first->next = NULL;
	return (1);
}

int	rotate_stack_b(t_stack_b **stack_b)
{
	t_stack_b *first;
	t_stack_b *last;
	if (!stack_b || !(*stack_b))
		return (0);
	while (last->next)
	{
		last = last->next;
	}
	last->next = first;
	*stack_b = first->next;
	first->next = NULL;
	return (1);
}

int rb(t_stack_b **stack_b)
{
	if (!rotate_stack_b(stack_b))
		return (0);
	ft_putendl_fd("rb", 1);
	return (1);
}

int ra(t_stack_a **stack_a)
{
	if (!rotate_stack_a(stack_a))
		return (0);
	ft_putendl_fd("ra", 1);
	return (1);
}
