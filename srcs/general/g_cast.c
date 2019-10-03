/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_cast.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 17:39:27 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/10/03 21:05:30 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int		ft_error()
{
	ft_putstr_base("Error\n", 2);
	return (0);
}

int		ft_int_cast(int ac, char **av, t_ab *ab)
{
	t_stack		*head;
	t_stack		*tmp;
	int			i;
	long long	num;

	i = 1;
	head = ft_new_node();
	tmp = head;
	while (i < ac)
	{
		num = ft_atoil(av[i]);
		i++;
		if (num < -2147483648 || num > 2147483647)
			return (ft_error());
		tmp->num = (int)num;
		if (i < ac)
			tmp->next = ft_new_node();
		tmp = tmp->next;
	}
	ab->a = head;
	ab->a_len = ft_lstlen(ab->a);
	return (1);
}
