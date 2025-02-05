/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 21:15:30 by ybounite          #+#    #+#             */
/*   Updated: 2025/02/05 13:41:40 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_data
{
	char	**arv;
	int		*tap;
	int		index;
	int		arc;
	int		start;
	int		end;
}	t_data;

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
}	t_stack;

void		sort_table(t_data *dtat);
int			check_if_sort(t_stack *stack_a);
// sprit_argiment
int			word(char *str, char space);
int			cont_word(int len, char **av);
int			ft_split_argemenet(int ac, char **av, t_data *data);
// add_node_back
t_stack		*ft_creat_node(int content);
int			ft_list_size(t_stack **stack);
int			max_number_stack_b(t_stack **stack_b);
void		lstadd_back(t_stack **lst, t_stack *new);
// 	
int			check_position_min(t_stack **stack_a);
void		sort_three_argument(t_stack **stack_a);
void		sort_four_argument(t_stack **stack_a, t_stack **stack_b);
void		sort_five_argumenet(t_stack **stack_a, t_stack **stack_b);
void		sort_argiment(t_stack **stack_a, t_stack **stack_b,
				t_data *data);
// ush_swap_utils
int			check_digit(char *str);
void		full_stack(t_data *data, t_stack **stack_a);
void		check_isdigit(t_data	*data, t_stack **stack_a);
int			ft_atoi_max_int(char *str, t_data *data, t_stack **stack_a);
// exit_and_free.c
void		ft_nodeclear(t_stack **lst);
void		ft_free_arge(t_data	*data);
int			exit_failure(t_data *data, t_stack **stack_a);
void		print_list(t_stack *list);//
// rules_swap.c
int			sa(t_stack	**stack_a);
int			sb(t_stack **stack_b);
int			swap_stack_a(t_stack **stack_a);
int			swap_stack_b(t_stack **stack_b);
int			ss(t_stack **stack_a, t_stack **stack_b);
// rulse_push
int			cmp(int a, int b);
int			pa(t_stack **stack_a, t_stack **stack_b);
int			pb(t_stack **stack_a, t_stack **stack_b);
int			push_stack_a(t_stack **stack_a, t_stack **stack_b);
int			push_stack_b(t_stack **stack_a, t_stack **stack_b);
// rules_rotate
int			ra(t_stack **stack_a);
int			rb(t_stack **stack_b);
int			rotate_stack_a(t_stack **stack_a);
int			rotate_stack_b(t_stack **stack_b);
int			rr(t_stack **stack_a, t_stack **stack_b);
// rules_reverse_rotate
int			rra(t_stack **stack_a);
int			rrb(t_stack **stack_b);
int			reverse_rotate_stack_a(t_stack **stack_a);
int			reverse_rotate_stack_b(t_stack **stack_b);
int			rrr(t_stack **stack_a, t_stack **stack_b);
// algorithem
int			check_revers_sort(t_stack **stack_a);
int			index_max_number(t_stack **stack_b, int max);
void		push_to_stack_a(t_stack **stack_a, t_stack **stack_b);
void		algorithem(t_stack **stack_a, t_stack **stack_b, t_data *data);
void		sort_all(t_stack **stack_a, t_stack **stack_b, t_data *data);

#endif