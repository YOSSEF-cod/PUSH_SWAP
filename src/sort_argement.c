/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_argement.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 18:37:33 by ybounite          #+#    #+#             */
/*   Updated: 2025/02/01 18:38:57 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_argument(t_stack **stack_a)
{
	int (n1), (n2), (n3);
	n1 = (*stack_a)->data;
	n2 = (*stack_a)->next->data;
	n3 = (*stack_a)->next->next->data;
	if (cmp(n1, n2) && cmp(n1, n3) && cmp(n3, n2))
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (cmp(n2, n1) && cmp(n2, n3) && cmp(n1, n3))
		sa(stack_a);
	else if (cmp(n3, n1) && cmp(n3, n2) && cmp(n1, n2))
		rra(stack_a);
	else if (cmp(n2, n1) && cmp(n2, n3) && cmp(n3, n1))
		ra(stack_a);
	else if (cmp(n3, n1) && cmp(n3, n2) && cmp(n2, n1))
	{
		sa(stack_a);
		rra(stack_a);
	}
}

void	sort_four_argument(t_stack **stack_a, t_stack **stack_b)
{
	int (n1), (n2), (n3), (n4);
	n1 = (*stack_a)->data;
	n2 = (*stack_a)->next->data;
	n3 = (*stack_a)->next->next->data;
	n4 = (*stack_a)->next->next->next->data;
	if (cmp(n1, n2) && cmp(n1, n3) && cmp(n1, n4))
		pb(stack_a, stack_b);
	else if (cmp(n2, n1) && cmp(n2, n3) && cmp(n2, n4))
	{
		sa(stack_a);
		pb(stack_a, stack_b);
	}
	else if (cmp(n3, n1) && cmp(n3, n2) && cmp(n3, n4))
	{
		ra(stack_a);
		ra(stack_a);
		pb(stack_a, stack_b);
	}
	else if (cmp(n4, n1) && cmp(n4, n2) && cmp(n4, n3))
	{
		rra(stack_a);
		pb(stack_a, stack_b);
	}
	sort_three_argument(stack_a);
	pa(stack_a, stack_b);
}

int	check_position_min(t_stack **stack_a)
{
	int (n1), (n2), (n3), (n4), (n5);
	n1 = (*stack_a)->data;
	n2 = (*stack_a)->next->data;
	n3 = (*stack_a)->next->next->data;
	n4 = (*stack_a)->next->next->next->data;
	n5 = (*stack_a)->next->next->next->next->data;
	if (cmp(n1, n2) && cmp(n1, n3) && cmp(n1, n4) && cmp(n1, n5))
		return (1);
	else if (cmp(n2, n1) && cmp(n2, n3) && cmp(n2, n4) && cmp(n2, n5))
		return (2);
	else if (cmp(n3, n1) && cmp(n3, n2) && cmp(n3, n4) && cmp(n3, n5))
		return (3);
	else if (cmp(n4, n1) && cmp(n4, n2) && cmp(n4, n3) && cmp(n4, n5))
		return (4);
	return (5);
}

void	sort_five_argumenet(t_stack **stack_a, t_stack **stack_b)
{
	if (check_position_min(stack_a) == 1)
		pb(stack_a, stack_b);
	else if (check_position_min(stack_a) == 2)
	{
		ra(stack_a);
		pb(stack_a, stack_b);
	}
	else if (check_position_min(stack_a) == 3)
	{
		ra(stack_a);
		ra(stack_a);
		pb(stack_a, stack_b);
	}
	else if (check_position_min(stack_a) == 4)
	{
		rra(stack_a);
		rra(stack_a);
		pb(stack_a, stack_b);
	}
	else if (check_position_min(stack_a) == 5)
	{
		rra(stack_a);
		pb(stack_a, stack_b);
	}
	sort_four_argument(stack_a, stack_b);
}

void	sort_argiment(t_stack **stack_a, t_stack **stack_b, t_data *data)
{
	if (data->arc == 2)
		sa(stack_a);
	else if (data->arc == 3)
		sort_three_argument(stack_a);
	else if (data->arc == 4)
		sort_four_argument(stack_a, stack_b);
	else if (data->arc == 5)
	{
		sort_five_argumenet(stack_a, stack_b);
		pa(stack_a, stack_b);
	}
	else
		sort_all(stack_a, stack_b, data);
}
