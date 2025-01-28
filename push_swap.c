/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 21:16:48 by ybounite          #+#    #+#             */
/*   Updated: 2025/01/28 14:35:48 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_a	*ft_creat_node(int content)
{
	t_stack_a *node;

	node = malloc(sizeof(t_stack_a));
	if (!node)
		return (NULL);
	node->data = content;
	node->next = NULL;
	return (node);
}

void	cpm(t_stack_a *list)
{
	if (!list && !list->next)
		return perror("Error\n");
	if (list->data > list->next->data)
		sa(&list);
	else 
		ft_putendl_fd("is sort", 1);
}

int	main(int ac, char **av)
{
	t_stack_a	*stack_a;
	// t_stack_b	*stack_b;
	int		(value), (x);
	x = 1;
	stack_a = NULL;
	if (ac != 1)
	{
		while (x < ac)
		{
			value = ft_atoi(av[x]);
			lstadd_back(&stack_a ,ft_creat_node(value));
			x++;
		}
		if (ac == 3)
			cpm(stack_a);
		// if (ac == 4)
		// 	sort3(head);
		// if (ac == 5)
		// 	sort4(head);
		// if (ac == 6)
		// 	sort5(head);
	}
	print_list(stack_a);
	// printf("%d\n", stack_a->data);
	// printf("%d\n", stack_a->next->data);
	
	ft_nodeclear(&stack_a);
}
