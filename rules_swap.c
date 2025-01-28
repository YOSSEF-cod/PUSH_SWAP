/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:56:24 by ybounite          #+#    #+#             */
/*   Updated: 2025/01/28 13:39:04 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lstadd_back(t_stack_a **lst, t_stack_a *new)
{
	t_stack_a	*ptr;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	ptr = *lst;
	while (ptr->next != NULL)
	{
		ptr = ptr->next;
	}
	ptr->next = new;
}

int swap_stack_a(t_stack_a **stack_a)
{
	t_stack_a *second;
	t_stack_a *ptr;
	if (!stack_a || !(*stack_a) || !(*stack_a)->next)
		return (0);
	second = (*stack_a);
	ptr = (*stack_a)->next;
	(*stack_a) = ptr;
	ptr->next = second->next;
	second->next = ptr;
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