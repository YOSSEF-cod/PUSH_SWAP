/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_node_back.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 10:31:19 by ybounite          #+#    #+#             */
/*   Updated: 2025/02/04 15:08:17 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_stack	*ft_creat_node(int content)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->data = content;
	node->next = NULL;
	return (node);
}

void	lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*ptr;

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

int	ft_list_size(t_stack **stack)
{
	t_stack	*list;
	int		i;

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

int	max_number_stack_b(t_stack **stack_b)
{
	t_stack	*list;
	int		nbr;

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
