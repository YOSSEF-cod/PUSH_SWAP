/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:56:24 by ybounite          #+#    #+#             */
/*   Updated: 2025/01/28 16:33:12 by ybounite         ###   ########.fr       */
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

void swap_b(int *a, int *b)
{
	int tmp;
	tmp =  *a;
	*a = *b;
	*b = tmp;
}

int	sa(t_stack_a	**stack_a)
{
	if (!swap_stack_a(stack_a))
		return (-1);
	ft_putendl_fd("sa", 1);
	return 1;
}

// int	sb(t_stack_b **stack_b)
// {
// 	if (!swap_stack_b(stack_b))
// 		return (-1);
// 	ft_putendl_fd("sb", 1);
// 	return (1);
// }
