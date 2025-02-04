
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 19:03:14 by ybounite          #+#    #+#             */
/*   Updated: 2025/02/03 17:44:37 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_list_size(t_stack_a **stack)
{
	t_stack_a	*list;
	int			i;
	if (!stack || !(*stack))
		return (0);
	list = *stack;
	i = 0;
	while (list)
	{
		list = list->next;
		i++;
	}
	return (i);
}

int	index_max_number(t_stack_b **stack_b, int max)
{
	t_stack_b *list;
	int	i;

	if (!stack_b || !(*stack_b))
		return (-1);
	i = 0;
	list = *stack_b;
	while (list)
	{
		if (list->data == max)
			break;
		i++;
		list = list->next;
	}
	return (i);
}

int	max_number_stack_b(t_stack_b **stack_b)
{
	t_stack_b *list;
	int 		nbr;

	if (!stack_b || !(*stack_b))
		return (0);
	list = *stack_b;
	nbr = list->data; 
	while (list)
	{
		if (nbr < list->data)
			nbr = list->data;
		list = list->next;
	}
	return (nbr);
}

void	push_to_stack_a(t_stack_a **stack_a, t_stack_b **stack_b)
{
	int	index_max_num_b;
	int	max_value_b;
	int	mid_stack_b;
	// printf("size stack_b  : %d\n", list_size_b(stack_b));
	while (list_size_b(stack_b))
	{
		max_value_b = max_number_stack_b(stack_b);
		index_max_num_b = index_max_number(stack_b, max_value_b);
		// printf("max num [%d]: %d\n", index_max_num_b, max_value_b);
		if ((*stack_b)->data == max_value_b)
			pa(stack_a, stack_b);
		else
		{
			mid_stack_b = list_size_b(stack_b) / 2;
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

int	list_size_b(t_stack_b **stack_b)
{
	t_stack_b *list;
	int	i;
	i = 0;
	if (!stack_b || !(*stack_b))
		return 0;
	list = *stack_b;
	while (list)
	{
		list = list->next;
		i++;
	}
	return (i);
}

void	algorithem(t_stack_a **stack_a, t_stack_b **stack_b, t_data *data)
{
	while (ft_list_size(stack_a))
	{
		// printf("index start : %d\nindex end : %d\n", data->start, data->end);
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
			if (data->start < data->end -1)
				data->start++;
			if (data->end < data->arc - 1)
				data->end++;
		}
		else 
			ra(stack_a);
	}
}

int	check_revers_sort(t_stack_a **stack_a)
{
	t_stack_a	*tmp;

	if (!stack_a || !(*stack_a))
		return (1);
	tmp = *stack_a;
	while (tmp->next)
	{
		if (cmp(tmp->data, tmp->next->data))
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
void	sort_all(t_stack_a **stack_a, t_stack_b **stack_b, t_data *data)
{
	data->start = 0;
	printf("arc : %d\n", data->arc);
	if (data->arc <= 100)
		data->end = data->arc / 5;
	else if (data->arc <= 500)
	{
		if (check_revers_sort(stack_a))
			data->end = 64;
		else
			data->end = 32;
	}
	// if (check_revers_sort(stack_a))
	// {
	// 	while (ft_list_size(stack_a))
	// 		pb(stack_a, stack_b);
	// }
	// else
	algorithem(stack_a, stack_b, data);
	push_to_stack_a(stack_a, stack_b);
}
