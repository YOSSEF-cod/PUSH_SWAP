/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_argiment.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:18:49 by ybounite          #+#    #+#             */
/*   Updated: 2025/02/01 19:19:50 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isspace(char *str)
{
	int (i);
	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

void	check_emty_argement(int ac, char **av)
{
	int (i);
	i = 0;
	while (i < ac)
	{
		while (av[i][0] == '\0' || ft_isspace(av[i]))
		{
			ft_putendl_fd("Error", 1);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

int	cont_word(int len, char **av)
{
	int (i), (total);
	i = 1;
	total = 0;
	check_emty_argement(len, av);
	while (i < len)
	{
		total += word(av[i], ' ');
		i++;
	}
	return (total);
}

int	word(char *str, char space)
{
	int (i), (len);
	i = 0;
	len = 0;
	while (str[i])
	{
		while (str[i] && str[i] == space)
			i++;
		if (str[i])
			len++;
		while (str[i] && str[i] != space)
			i++;
	}
	return (len);
}

int	ft_split_argemenet(int ac, char **av, t_data *data)
{
	char (**str);
	int (i), (index), (j);

	i  = 1;
	index = 0;
	data->arc = cont_word(ac, av);
	data->arv = malloc(sizeof(char *) * (data->arc + 1));
	if (!data->arv)
		return (ft_putendl_fd("Erorr", 2), exit(1), 1);
	while (i < ac)
	{
		j = 0;
		str = ft_split(av[i], ' ');
		while (j < word(av[i], ' '))
		{
			data->arv[index] = str[j];
			index++;
			j++;
		}
		free(str);
		i++;
	}
	data->arv[index] = NULL;
	return (0);
}
