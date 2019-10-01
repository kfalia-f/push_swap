/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_cast.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 17:39:27 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/10/01 19:50:31 by kfalia-f         ###   ########.fr       */
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
	t_stack	*head;
	t_stack	*tmp;
	int		i;
	int		num;

	i = 1;
	head = ab->a;
	tmp = head;
	while (i < ac)
	{
		if ((num = ft_atoi(av[i])) < 0)
			return (ft_error());
		tmp->num = num;
		tmp->next = ft_new_node();
		tmp = tmp->next;
		i++;
	}
	ab->a = head;
	return (1);
}
