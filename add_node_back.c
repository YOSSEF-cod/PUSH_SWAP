/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_node_back.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 10:31:19 by ybounite          #+#    #+#             */
/*   Updated: 2025/01/30 10:31:32 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_a   *ft_creat_node(int content)
{
	t_stack_a *node;

	node = malloc(sizeof(t_stack_a));
	if (!node)
		return (NULL);
	node->data = content;
	node->next = NULL;
	return (node);
}

void	lstadd_back(t_stack_a **lst, t_stack_a *new)
{
	t_stack_a	*ptr;

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
