/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 21:16:48 by ybounite          #+#    #+#             */
/*   Updated: 2025/01/31 20:26:06 by ybounite         ###   ########.fr       */
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

void	sort_3_argement(t_stack_a **stack_a)
{
	int (n1), (n2), (n3);
	n1 = (*stack_a)->data;
	n2 = (*stack_a)->next->data;
	n3 = (*stack_a)->next->next->data;
	if (n1 > n2 && n2 > n3)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (n3 > n1 && n3 > n2)
		sa(stack_a);
	else if (n1 < n2 && n2 > n3)
	{
		sa(stack_a);
		ra(stack_a);
		if ((*stack_a)->data > (*stack_a)->next->data)
			sa(stack_a);
	}
	else
		ra(stack_a);
}
void	sort_4_argement(t_stack_a **stack_a)
{
	int (n1), (n2), (n3), (n4);
	n1 = (*stack_a)->data;
	n2 = (*stack_a)->next->data;
	n3 = (*stack_a)->next->next->data;
	n4 = (*stack_a)->next->next->next->data;
}
void	sort_argiment(t_stack_a **stack_a, t_stack_b **stack_b, t_data *data)
{
	(void)data;
	(void)stack_b;
	if(data->arc == 2)
		sa(stack_a);
	else if (data->arc == 3)
		sort_3_argement(stack_a);
	else if (data->arc == 4)
		sort_4_argement(stack_a);
	// else if (data->arc == 5)
	// {

	// }
	// sa(stack_a);
	// pb(stack_a, stack_b);
	// pb(stack_a, stack_b);
	// pb(stack_a, stack_b);
	// rr(stack_a, stack_b);
	// rrr(stack_a, stack_b);
	// sa(stack_a);
	// pa(stack_a, stack_b);
	// pa(stack_a, stack_b);
	// pa(stack_a, stack_b);
}
int	main(int ac, char **av)
{
	t_stack_a	*stack_a;
	t_stack_b	*stack_b;
	t_data		data;
	ft_bzero(&stack_a, sizeof(t_stack_a));
	ft_bzero(&data, sizeof(t_data));
	if (ac == 1)
		exit(EXIT_FAILURE);
	ft_split_argemenet(ac, av, &data);
	full_stack(&data, &stack_a);
	if (check_if_sort(stack_a))
		return (ft_nodeclear(&stack_a), ft_free_arge(&data), 0);
	sort_argiment(&stack_a, &stack_b, &data);
	printf("stack a : \n");
	print_list_b(stack_b);
	printf("\nstack a : \n");
	print_list(stack_a);//
	ft_nodeclear_b(&stack_b);
	ft_nodeclear(&stack_a);
	ft_free_arge(&data);
}
