/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_reverse_rotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 09:46:55 by ybounite          #+#    #+#             */
/*   Updated: 2025/02/04 18:15:05 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	reverse_rotate_stack_a(t_stack **stack_a)
{
	t_stack	*last;
	t_stack	*second_last;

	if (!stack_a || !(*stack_a))
		return (0);
	last = *stack_a;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = *stack_a;
	*stack_a = last;
	return (1);
}

int	reverse_rotate_stack_b(t_stack **stack_b)
{
	t_stack	*last;
	t_stack	*second_last;

	if (!stack_b || !(*stack_b))
		return (0);
	last = *stack_b;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = *stack_b;
	*stack_b = last;
	return (1);
}

int	rra(t_stack **stack_a)
{
	return (reverse_rotate_stack_a(stack_a));
}

int	rrb(t_stack **stack_b)
{
	return (reverse_rotate_stack_b(stack_b));
}

int	rrr(t_stack **stack_a, t_stack **stack_b)
{
	return (rra(stack_a) && rrb(stack_b));
}
