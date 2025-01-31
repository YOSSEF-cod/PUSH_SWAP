/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 21:15:30 by ybounite          #+#    #+#             */
/*   Updated: 2025/01/31 15:57:17 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H


# include <stdio.h>
# include <stdlib.h>
# include "./libft/libft.h"
typedef struct s_data
{
	char	**arv;
	int		arc;
	int		start;
	int		end;
}	t_data;

typedef struct s_stack_a
{
	int data;
	struct  s_stack_a *next;
}	t_stack_a;

typedef struct s_stack_b
{
	int data;
	struct s_stack_b *next;
}	t_stack_b;
t_stack_a	*ft_creat_node(int content);

// sprit_argiment
int	word(char *str, char space);
int	cont_word(int len, char **av);
void	ft_split_argemenet(int len, char **av, t_data *data);
//
void 	lstadd_back(t_stack_a **lst, t_stack_a *new);

// ush_swap_utils.c
int		check_digit(char *str);
void	full_stack(t_data *data, t_stack_a **stack_a);
void	check_isdigit(t_data	*data, t_stack_a **stack_a);
int		ft_atoi_max_int(char *str, t_data *data, t_stack_a **stack_a);
// exit_and_free.c
void	ft_nodeclear(t_stack_a **lst);
void	ft_nodeclear_b(t_stack_b **lst);
void	ft_free_arge(t_data	*data);
int		exit_failure(t_data *data, t_stack_a **stack_a);
void	print_list(t_stack_a *list);//
void	print_list_b(t_stack_b *list);
// rules_swap.c
int		sa(t_stack_a	**stack_a);
int		sb(t_stack_b **stack_b);
int		swap_stack_a(t_stack_a **stack_a);
int		swap_stack_b(t_stack_b **stack_b);
int		ss(t_stack_a **stack_a, t_stack_b **stack_b);
// rulse_push
int		pa(t_stack_a **stack_a, t_stack_b **stack_b);
int		pb(t_stack_a **stack_a, t_stack_b **stack_b);
int		push_stack_a(t_stack_a **stack_a, t_stack_b **stack_b);
int		push_stack_b(t_stack_a **stack_a, t_stack_b **stack_b);
// rules_rotate
int		ra(t_stack_a **stack_a);
int		rb(t_stack_b **stack_b);
int		rotate_stack_a(t_stack_a **stack_a);
int		rotate_stack_b(t_stack_b **stack_b);
int		rr(t_stack_a **stack_a, t_stack_b **stack_b);
// rules_reverse_rotate
int		rra(t_stack_a **stack_a);
int		rrb(t_stack_b **stack_b);
int		reverse_rotate_stack_a(t_stack_a **stack_a);
int		reverse_rotate_stack_b(t_stack_b **stack_b);
int		rrr(t_stack_a **stack_a, t_stack_b **stack_b);

#endif