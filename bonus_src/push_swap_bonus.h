/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:30:19 by ybounite          #+#    #+#             */
/*   Updated: 2025/02/05 15:34:58 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "../libft/libft.h"
# include "get_next_line.h"
# include <stdio.h>
# include <stdlib.h>

typedef struct s_data
{
	char	**arv;
	char	*line;
	int		index;
	int		arc;
}	t_data;

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
}	t_stack;

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
// push_swap_utils
int			check_digit(char *str);
void		full_stack(t_data *data, t_stack **stack_a);
void		check_isdigit(t_data	*data, t_stack **stack_a);
void		check_is_repetition(t_data *data, t_stack **stack_a);
int			ft_atoi_max_int(char *str, t_data *data, t_stack **stack_a);
// exit_and_free.c
void		ft_nodeclear(t_stack **lst);
void		ft_free_arge(t_data	*data);
int			exit_failure(t_data *data, t_stack **stack_a);
void		ft_free_all(t_stack **stack_a, t_stack **stack_b, t_data *data);
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
// checker_bonus
int			ft_strcmp(char *str1, char *str2);
int			check_if_sort(t_stack *stack_a);
int			ft_aplecation_sort(t_data *data, t_stack **stack_a,
				t_stack **stack_b);
void		ft_checker(t_stack **stack_a, t_stack **stack_b, t_data *data);
#endif