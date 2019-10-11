/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_valid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 17:13:13 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/10/11 19:53:03 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int		ft_valid_str(char *str)
{
	int		i;

	i = 0;
	if (ft_strlen(str) == 1 && !ft_isdigit(str[0]))
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != '-' && str[i] != ' ')
			return (0);
		if (str[i] == '-' && !ft_isdigit(str[i + 1]))
			return (0);
		i++;
	}
	return (1);
}

int		ft_valid(int ac, char **av)
{
	int		i;
	int		j;

	i = 1;
	if (ac == 2)
		return (ft_valid_str(av[1]));
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]) && av[i][j] != '-')
				return (0);
			if (av[i][j] == '-' && !ft_isdigit(av[i][j + 1]))
				return (0);
			j++;
		}
		i++;
	}
	if (i == 1)
		return (0);
	return (1);
}

int		ft_valid_nums(t_ab *ab)
{
	t_stack	*tmp;
	t_stack *check;

	if (ab->a_len <= 1)
		return (1);
	check = ab->a;
	while (check)
	{
		tmp = check->next;
		while (tmp)
		{
			if (check->num == tmp->num)
				return (0);
			tmp = tmp->next;
		}
		check = check->next;
	}
	return (1);
}
