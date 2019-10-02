/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 21:28:37 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/10/02 21:54:04 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ft_swap_a(t_ab *ab)
{
	int		c;

	if (ab->a_len <= 1)
		return ;
	c = ab->a->num;
	ab->a->num = ab->a->next->num;
	ab->a->next->num = c;
}

void	ft_swap_b(t_ab *ab)
{
	int		c;

	if (ab->b_len <= 1)
		return ;
	c = ab->b->num;
	ab->b->num = ab->b->next->num;
	ab->b->next->num = c;
}

void	ft_swap(char bf[1000], t_ab *ab)
{
	if (ft_strequ(bf, "sa\n"))
		ft_swap_a(ab);
	else if (ft_strequ(bf, "sb\n"))
		ft_swap_b(ab);
	else
	{
		ft_swap_a(ab);
		ft_swap_b(ab);
	}
}
