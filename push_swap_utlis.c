/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utlis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:52:56 by ybounite          #+#    #+#             */
/*   Updated: 2025/01/30 16:02:39 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi_max_int(char *str, t_data *data, t_stack_a **stack_a)
{
	int (i), (r);
	long (nbr);
	i = 0;
	r = 1;
	nbr = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			r *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + (str[i] - 48);
		if ((r * nbr > 2147483647) || (r * nbr < -2147483648))
			exit_failure(data, stack_a);
		i++;
	}
	return (nbr * r);
}
void	check_is_repetition(t_data *data, t_stack_a **stack_a)
{
	t_stack_a *ptr;
	t_stack_a *tmp;

	if (!stack_a || !(*stack_a))
		exit_failure(data, stack_a);
	ptr = *stack_a;
	while (ptr->next)
	{
		tmp = ptr->next;
		while (tmp)
		{
			if (ptr->data == tmp->data)
			{
				ft_putendl_fd("repetition for number !", 2);
				exit_failure(data, stack_a);
			}
			tmp = tmp->next;
		}
		ptr = ptr->next;
	}
}
void	full_stack(t_data *data, t_stack_a **stack_a)
{
	int	(i), (value);
	i = 0;
	check_isdigit(data, stack_a);
	while (i < data->arc)
	{
		
		value = ft_atoi_max_int(data->arv[i], data, stack_a);
		lstadd_back(stack_a, ft_creat_node(value));
		i++;
	}
	check_is_repetition(data, stack_a);
}

void	check_isdigit(t_data	*data, t_stack_a **stack_a)
{
	int (i);
	i = 0;
	while (i < data->arc)
	{
		if (!check_digit(data->arv[i]))
			exit_failure(data, stack_a);
		i++;
	}
}

int	check_digit(char *str)
{
	int (i);
	i = 0;
	if ((str[i] == '-' || str[i] == '+' ) && str[i + 1])
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}
