/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_content.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:55:18 by ybounite          #+#    #+#             */
/*   Updated: 2025/01/28 13:39:19 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	free_content(void *data)
// {
// 	free(data);
// 	data = NULL;
// }

void	ft_nodeclear(t_stack_a **lst)
{
	t_stack_a	*ptr;

	ptr = *lst;
	if (!lst)
		return ;
	while (*lst != NULL)
	{
		*lst = (*lst)->next;
		free(ptr);
		ptr = *lst;
	}
}

void	print_list(t_stack_a *list)
{
	while (list)
	{
		printf("%d   ", list->data);
		list = list->next;
	}
}
