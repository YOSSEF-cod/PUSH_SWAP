/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:48:56 by ybounite          #+#    #+#             */
/*   Updated: 2025/02/04 10:12:45 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_stack_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*ptr;

	if (!stack_a || !(*stack_a))
		return (0);
	ptr = *stack_a;
	while (ptr)
	{
		*stack_a = (*stack_a)->next;
		ptr->next = *stack_b;
		*stack_b = ptr;
		break ;
	}
	return (1);
}

int	pb(t_stack **stack_a, t_stack **stack_b)
{
	if (!push_stack_b(stack_a, stack_b))
		return (1);
	ft_putendl_fd("pb", 1);
	return (0);
}

int	push_stack_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	if (!stack_b || !(*stack_b))
		return (0);
	temp = *stack_b;
	while (temp)
	{
		*stack_b = (*stack_b)->next;
		temp->next = *stack_a;
		*stack_a = temp;
		break ;
	}
	return (1);
}

int	pa(t_stack **stack_a, t_stack **stack_b)
{
	if (!push_stack_a(stack_a, stack_b))
		return (1);
	ft_putendl_fd("pa", 1);
	return (0);
}

int	cmp(int a, int b)
{
	return (a < b);
}
