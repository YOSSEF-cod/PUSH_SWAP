/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 21:16:48 by ybounite          #+#    #+#             */
/*   Updated: 2025/01/30 16:17:59 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cmp(int a, int b)
{
	return (a < b);
}

int	check_if_sort(t_stack_a *stack_a)
{
	t_stack_a	*tmp;

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

int	main(int ac, char **av)
{
	t_stack_a	*stack_a;
	t_data		data;
	ft_bzero(&stack_a, sizeof(t_stack_a));
	ft_bzero(&data, sizeof(t_data));
	if (ac == 1)
		exit(EXIT_FAILURE);
	ft_split_argemenet(ac, av, &data);
	full_stack(&data, &stack_a);
	if (check_if_sort(stack_a))
		return (ft_nodeclear(&stack_a), ft_free_arge(&data), 0);
	printf("not sorting !\n");
	print_list(stack_a);//
	ft_nodeclear(&stack_a);
	ft_free_arge(&data);
}
