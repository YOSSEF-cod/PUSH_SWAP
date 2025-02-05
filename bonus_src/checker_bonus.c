/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 13:52:11 by ybounite          #+#    #+#             */
/*   Updated: 2025/02/05 15:30:29 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_strcmp(char *str1, char *str2)
{
	int (i);
	i = 0;
	if (!str1 || !str2)
		return (0);
	while (str1[i])
	{
		if (str1[i] != str2[i])
			return (0);
		i++;
	}
	return (1);
}

int	ft_aplecation_sort(t_data *data, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strcmp(data->line, "sa\n"))
		return (sa(stack_a), 1);
	else if (ft_strcmp(data->line, "sb\n"))
		return (sb(stack_b), 1);
	else if (ft_strcmp(data->line, "ss\n"))
		return (ss(stack_a, stack_b), 1);
	else if (ft_strcmp(data->line, "pa\n"))
		return (pa(stack_a, stack_b), 1);
	else if (ft_strcmp(data->line, "pb\n"))
		return (pb(stack_a, stack_b), 1);
	else if (ft_strcmp(data->line, "ra\n"))
		return (ra(stack_a), 1);
	else if (ft_strcmp(data->line, "rb\n"))
		return (rb(stack_b), 1);
	else if (ft_strcmp(data->line, "rr\n"))
		return (rr(stack_a, stack_b), 1);
	else if (ft_strcmp(data->line, "rra\n"))
		return (rra(stack_a), 1);
	else if (ft_strcmp(data->line, "rrb\n"))
		return (rrb(stack_b), 1);
	else if (ft_strcmp(data->line, "rrr\n"))
		return (rrr(stack_a, stack_b));
	else
		return (ft_free_all(stack_a, stack_b, data), 0);
	return (1);
}

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

void	ft_checker(t_stack **stack_a, t_stack **stack_b, t_data *data)
{
	data->line = get_next_line(0);
	while ((data->line))
	{
		if (!ft_aplecation_sort(data, stack_a, stack_b))
		{
			ft_putendl_fd("Error", 1);
			exit(EXIT_FAILURE);
		}
		free(data->line);
		data->line = NULL;
		data->line = get_next_line(0);
	}
}
