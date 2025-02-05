/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 21:16:48 by ybounite          #+#    #+#             */
/*   Updated: 2025/02/05 09:06:12 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_if_sort(t_stack *stack_a)
{
	t_stack	*tmp;

	tmp = stack_a;
	if (!stack_a)
		return (1);
	while (tmp->next)
	{
		if (!cmp(tmp->data, tmp->next->data))
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	min_nber(t_stack **stack_a)
{
	t_stack	*list;
	int		min;

	if (!stack_a || !(*stack_a))
		return (exit(EXIT_FAILURE), 0);
	list = *stack_a;
	min = list->data;
	while (list)
	{
		if (min > list->data)
			min = list->data;
		list = list->next;
	}
	return (min);
}

void	sort_table(t_data *dtat)
{
	int (i), (j), (tmp);
	i = 0;
	while (i < dtat->arc)
	{
		j = 1 + i;
		while (j < dtat->arc)
		{
			if (!cmp(dtat->tap[i], dtat->tap[j]))
			{
				tmp = dtat->tap[i];
				dtat->tap[i] = dtat->tap[j];
				dtat->tap[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_data	data;

	ft_bzero(&stack_a, sizeof(t_stack));
	ft_bzero(&data, sizeof(t_data));
	if (ac == 1)
		exit(EXIT_SUCCESS);
	ft_split_argemenet(ac, av, &data);
	full_stack(&data, &stack_a);
	if (check_if_sort(stack_a))
		return (ft_nodeclear(&stack_a), ft_free_arge(&data), 0);
	sort_table(&data);
	sort_argiment(&stack_a, &stack_b, &data);
	ft_nodeclear(&stack_b);
	ft_nodeclear(&stack_a);
	ft_free_arge(&data);
}
