/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_and_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 10:26:25 by ybounite          #+#    #+#             */
/*   Updated: 2025/02/03 09:31:36 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	exit_failure(t_data *data, t_stack_a **stack_a)
{
	ft_putendl_fd("Error", 1);
	ft_free_arge(data);
	ft_nodeclear(stack_a);
	exit(EXIT_FAILURE);
}

void	ft_nodeclear(t_stack_a **lst)
{
	t_stack_a *ptr;

	if (!lst || !(*lst))
		return ;
	while (*lst != NULL)
	{
		ptr = *lst;
		*lst = (*lst)->next;
		free(ptr);
	}
}
void	ft_nodeclear_b(t_stack_b **lst)
{
	t_stack_b *ptr;

	if (!lst || !(*lst))
		return ;
	while (*lst != NULL)
	{
		ptr = *lst;
		*lst = (*lst)->next;
		free(ptr);
	}
}
void	ft_free_arge(t_data	*data)
{
	int (i);
	i = 0;
	while (i < data->arc)
	{
		free(data->arv[i]);
		i++;
	}
	free(data->tap);
	data->tap = NULL;
	free(data->arv);
	data->arv = NULL;
}

void	print_list_b(t_stack_b *list)
{
	while (list)
	{
		printf("%d ", list->data);
		list = list->next;
	}
}
void	print_list(t_stack_a *list)
{
	while (list)
	{
		printf("%d ", list->data);
		list = list->next;
	}
}