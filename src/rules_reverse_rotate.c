/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_reverse_rotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 09:46:55 by ybounite          #+#    #+#             */
/*   Updated: 2025/02/06 09:26:20 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (!reverse_rotate_stack_a(stack_a))
		return (0);
	ft_putendl_fd("rra", 1);
	return (1);
}

int	rrb(t_stack **stack_b)
{
	if (!reverse_rotate_stack_b(stack_b))
		return (0);
	ft_putendl_fd("rrb", 1);
	return (1);
}

int	rrr(t_stack **stack_a, t_stack **stack_b)
{
	if (!reverse_rotate_stack_a(stack_a) || !reverse_rotate_stack_b(stack_b))
		return (0);
	ft_putendl_fd("rrr", 1);
	return (1);
}
