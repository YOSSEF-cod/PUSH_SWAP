/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:49:49 by ybounite          #+#    #+#             */
/*   Updated: 2025/02/06 09:27:50 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate_stack_a(t_stack **stack_a)
{
	t_stack	*first;
	t_stack	*last;

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

int	rotate_stack_b(t_stack **stack_b)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack_b || !(*stack_b) || !(*stack_b)->next)
		return (0);
	last = *stack_b;
	first = *stack_b;
	while (last->next)
	{
		last = last->next;
	}
	last->next = first;
	*stack_b = first->next;
	first->next = NULL;
	return (1);
}

int	rb(t_stack **stack_b)
{
	if (!rotate_stack_b(stack_b))
		return (0);
	ft_putendl_fd("rb", 1);
	return (1);
}

int	ra(t_stack **stack_a)
{
	if (!rotate_stack_a(stack_a))
		return (0);
	ft_putendl_fd("ra", 1);
	return (1);
}

int	rr(t_stack **stack_a, t_stack **stack_b)
{
	if (!rotate_stack_a(stack_a) || !rotate_stack_b(stack_b))
		return (0);
	ft_putendl_fd("rr", 1);
	return (1);
}
