/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 21:15:30 by ybounite          #+#    #+#             */
/*   Updated: 2025/02/03 15:41:22 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include "./libft/libft.h"

typedef struct s_data
{
	char	**arv;
	int		*tap;
	// int		index;
	int		arc;
	int		start;
	int		end;
}	t_data;

typedef struct s_stack_a
{
	int					data;
	struct s_stack_a	*next;
}	t_stack_a;

typedef struct s_stack_b
{
	int					data;
	struct s_stack_b	*next;
}	t_stack_b;

void		sort_table(t_data *dtat);
t_stack_a	*ft_creat_node(int content);
int			check_if_sort(t_stack_a *stack_a);
int			check_revers_sort(t_stack_a **stack_a);
// sprit_argiment
int			word(char *str, char space);
int			cont_word(int len, char **av);
int			ft_split_argemenet(int ac, char **av, t_data *data);
//
void		lstadd_back(t_stack_a **lst, t_stack_a *new);
// 	
int			check_position_min(t_stack_a **stack_a);
void		sort_three_argument(t_stack_a **stack_a);
void		sort_four_argument(t_stack_a **stack_a, t_stack_b **stack_b);
void		sort_five_argumenet(t_stack_a **stack_a, t_stack_b **stack_b);
void		sort_argiment(t_stack_a **stack_a, t_stack_b **stack_b,
				t_data *data);
// ush_swap_utils
int			check_digit(char *str);
void		full_stack(t_data *data, t_stack_a **stack_a);
void		check_isdigit(t_data	*data, t_stack_a **stack_a);
int			ft_atoi_max_int(char *str, t_data *data, t_stack_a **stack_a);
// exit_and_free.c
void		ft_nodeclear(t_stack_a **lst);
void		ft_nodeclear_b(t_stack_b **lst);
void		ft_free_arge(t_data	*data);
int			exit_failure(t_data *data, t_stack_a **stack_a);
void		print_list(t_stack_a *list);//
void		print_list_b(t_stack_b *list);
// rules_swap.c
int			sa(t_stack_a	**stack_a);
int			sb(t_stack_b **stack_b);
int			swap_stack_a(t_stack_a **stack_a);
int			swap_stack_b(t_stack_b **stack_b);
int			ss(t_stack_a **stack_a, t_stack_b **stack_b);
// rulse_push
int			cmp(int a, int b);
int			pa(t_stack_a **stack_a, t_stack_b **stack_b);
int			pb(t_stack_a **stack_a, t_stack_b **stack_b);
int			push_stack_a(t_stack_a **stack_a, t_stack_b **stack_b);
int			push_stack_b(t_stack_a **stack_a, t_stack_b **stack_b);
// rules_rotate
int			ra(t_stack_a **stack_a);
int			rb(t_stack_b **stack_b);
int			rotate_stack_a(t_stack_a **stack_a);
int			rotate_stack_b(t_stack_b **stack_b);
int			rr(t_stack_a **stack_a, t_stack_b **stack_b);
// rules_reverse_rotate
int			rra(t_stack_a **stack_a);
int			rrb(t_stack_b **stack_b);
int			reverse_rotate_stack_a(t_stack_a **stack_a);
int			reverse_rotate_stack_b(t_stack_b **stack_b);
int			rrr(t_stack_a **stack_a, t_stack_b **stack_b);
// algorithem
int			ft_list_size(t_stack_a **stack);
int			list_size_b(t_stack_b **stack_b);
int			index_max_number(t_stack_b **stack_b, int max);
int			max_number_stack_b(t_stack_b **stack_b);
void		algorithem(t_stack_a **stack_a, t_stack_b **stack_b, t_data *data);
void		sort_all(t_stack_a **stack_a, t_stack_b **stack_b, t_data *data);
#endif