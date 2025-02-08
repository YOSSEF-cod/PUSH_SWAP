/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:38:02 by ybounite          #+#    #+#             */
/*   Updated: 2025/02/06 11:07:18 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
	ft_checker(&stack_a, &stack_b, &data);
	// print_list(stack_a);
	// print_list(stack_b);
	if (check_if_sort(stack_a) && !stack_b)
		return (ft_putendl_fd("OK", 1),
			ft_free_all(&stack_a, &stack_b, &data), 0);
	else
		return (ft_putendl_fd("KO", 2),
			ft_free_all(&stack_a, &stack_b, &data), 1);
}
