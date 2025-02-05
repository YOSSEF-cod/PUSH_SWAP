/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 19:03:14 by ybounite          #+#    #+#             */
/*   Updated: 2025/02/05 16:31:00 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	index_max_number(t_stack **stack_b, int max)
{
	t_stack	*list;
	int		i;

	if (!stack_b || !(*stack_b))
		return (-1);
	i = 0;
	list = *stack_b;
	while (list)
	{
		if (list->data == max)
			break ;
		i++;
		list = list->next;
	}
	return (i);
}

void	push_to_stack_a(t_stack **stack_a, t_stack **stack_b)
{
	int (index_max_num_b), (max_value_b), (mid_stack_b);
	while (ft_list_size(stack_b))
	{
		max_value_b = max_number_stack_b(stack_b);
		index_max_num_b = index_max_number(stack_b, max_value_b);
		if ((*stack_b)->data == max_value_b)
			pa(stack_a, stack_b);
		else
		{
			mid_stack_b = ft_list_size(stack_b) / 2;
			if (index_max_num_b <= mid_stack_b)
			{
				while ((*stack_b)->data != max_value_b)
					rb(stack_b);
			}
			else
			{
				while ((*stack_b)->data != max_value_b)
					rrb(stack_b);
			}
		}
	}
}

void	algorithem(t_stack **stack_a, t_stack **stack_b, t_data *data)
{
	while (ft_list_size(stack_a))
	{
		if ((*stack_a)->data <= data->tap[data->start])
		{
			pb(stack_a, stack_b);
			rb(stack_b);
			if (data->start < data->end - 1)
				data->start++;
			if (data->end < data->arc - 1)
				data->end++;
		}
		else if ((*stack_a)->data <= data->tap[data->end])
		{
			pb(stack_a, stack_b);
			if (data->start < data->end - 1)
				data->start++;
			if (data->end < data->arc - 1)
				data->end++;
		}
		else
			ra(stack_a);

	}
}

int	check_revers_sort(t_stack **stack_a)
{
	t_stack	*tmp;

	if (!stack_a || !(*stack_a))
		return (0);
	tmp = *stack_a;
	while (tmp->next)
	{
		if (cmp(tmp->data, tmp->next->data))
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	sort_all(t_stack **stack_a, t_stack **stack_b, t_data *data)
{
	data->start = 0;
	if (data->arc <= 100)
		data->end = data->arc / 5;
	else if (data->arc <= 500)
	{
		if (check_revers_sort(stack_a))
			data->end = 64;
		else
			data->end = 32;
	}
	algorithem(stack_a, stack_b, data);
	push_to_stack_a(stack_a, stack_b);
}
