/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:56:24 by ybounite          #+#    #+#             */
/*   Updated: 2025/01/30 17:51:09 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int swap_stack_a(t_stack_a **stack_a)
{
	t_stack_a *second;
	t_stack_a *ptr;

	if (!stack_a || !(*stack_a) || !(*stack_a)->next)
		return (0);
	second = (*stack_a);
	ptr = (*stack_a)->next;
	(*stack_a) = ptr;
	second->next = ptr->next;
	ptr->next = second;
	return (1);
}

int swap_stack_b(t_stack_b **stack_b)
{
	t_stack_b	*ptr;
	t_stack_b	*second;

	if (!stack_b || !(*stack_b) || !(*stack_b)->next)
		return (0);
	second = *stack_b;
	ptr = (*stack_b)->next;
	(*stack_b) = ptr;
	second->next = ptr->next;
	ptr->next = second;
	return (1);
}

int	sa(t_stack_a	**stack_a)
{
	if (!swap_stack_a(stack_a))
		return (1);
	ft_putendl_fd("sa", 1);
	return 0;
}

int	sb(t_stack_b **stack_b)
{
	if (!swap_stack_b(stack_b))
		return (1);
	ft_putendl_fd("sb", 1);
	return (0);
}

int	ss(t_stack_a **stack_a, t_stack_b **stack_b)
{
	if (sa(stack_a) || sb(stack_b))
		return (1);
	return (0);
}
