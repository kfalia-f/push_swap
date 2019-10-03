/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_check.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 19:17:49 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/10/03 23:23:42 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int		ft_check_stack(t_ab *ab, int flag)
{
	t_stack *tmp;

	tmp = ab->a;
	if (flag == 2)
		if (ab->b != NULL)
		{
			ft_putstr("KO\n");
			return (0);
		}
	while (tmp->next)
	{
		if (tmp->num > tmp->next->num)
		{
			if (flag != 0)
				ft_putstr("KO\n");
			return (0);
		}
		tmp = tmp->next;
	}
	ft_putstr("OK\n");
	return (1);
}

int		ft_check_stack_a(t_ab *ab)
{
	if (ab->a_len <= 1)
	{
		ft_putstr("OK\n");
		return (1);
	}
	if (ft_check_stack(ab, 0))
		return (1);
	return (0);
}
