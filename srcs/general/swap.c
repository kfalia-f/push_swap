/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 21:28:37 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/10/07 14:34:35 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ft_swap_a(t_ab *ab, int fl)
{
	int		c;

	if (ab->a_len <= 1)
		return ;
	c = ab->a->num;
	ab->a->num = ab->a->next->num;
	ab->a->next->num = c;
	if (fl)
		write(1, "sa\n", 3);
}

void	ft_swap_b(t_ab *ab, int fl)
{
	int		c;

	if (ab->b_len <= 1)
		return ;
	c = ab->b->num;
	ab->b->num = ab->b->next->num;
	ab->b->next->num = c;
	if (fl)
		write(1, "sb\n", 3);
}

void	ft_swap(char bf[BUFF_SIZE], t_ab *ab)
{
	if (ft_strequ(bf, "sa\n"))
		ft_swap_a(ab, 0);
	else if (ft_strequ(bf, "sb\n"))
		ft_swap_b(ab, 0);
}
