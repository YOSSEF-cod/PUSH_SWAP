/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:56:24 by ybounite          #+#    #+#             */
/*   Updated: 2025/02/06 09:32:56 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	swap_stack_a(t_stack **stack_a)
{
	t_stack	*second;
	t_stack	*ptr;

	if (!stack_a || !(*stack_a) || !(*stack_a)->next)
		return (0);
	second = (*stack_a);
	ptr = (*stack_a)->next;
	(*stack_a) = ptr;
	second->next = ptr->next;
	ptr->next = second;
	return (1);
}

int	swap_stack_b(t_stack **stack_b)
{
	t_stack	*ptr;
	t_stack	*second;

	if (!stack_b || !(*stack_b) || !(*stack_b)->next)
		return (0);
	second = *stack_b;
	ptr = (*stack_b)->next;
	(*stack_b) = ptr;
	second->next = ptr->next;
	ptr->next = second;
	return (1);
}

int	sa(t_stack	**stack_a)
{
	if (!swap_stack_a(stack_a))
		return (0);
	return (1);
}

int	sb(t_stack **stack_b)
{
	if (!swap_stack_b(stack_b))
		return (0);
	return (1);
}

int	ss(t_stack **stack_a, t_stack **stack_b)
{
	return (sa(stack_a) && sb(stack_b));
}
