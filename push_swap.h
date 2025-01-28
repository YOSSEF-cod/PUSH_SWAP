/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 21:15:30 by ybounite          #+#    #+#             */
/*   Updated: 2025/01/28 14:47:58 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H


# include <stdio.h>
# include <stdlib.h>
# include "./libft/libft.h"

typedef struct s_stack_a
{
	int data;
	struct  s_stack_a *next;
}	t_stack_a;

typedef struct s_stack_b
{
	int data;
	struct push_swap *next;
}	t_stack_b;
t_stack_a	*ft_creat_node(int content);

int	sa(t_stack_a	**stack_a);
// int	swap_a(t_stack_a	**stack_a);
// free content
void	lstadd_back(t_stack_a **lst, t_stack_a *new);
void	ft_nodeclear(t_stack_a **lst);
void	print_list(t_stack_a *list);

#endif