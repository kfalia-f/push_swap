/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 21:28:37 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/10/01 22:55:16 by kfalia-f         ###   ########.fr       */
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
	printf("len a = %d, len b = %d\n", ab->a_len, ab->b_len);
	printf("BEFORE 1 = %d 2 = %d\n", ab->a->num, ab->a->next->num);
	if (ft_strequ(bf, "sa\n"))
		ft_swap_a(ab);
	else if (ft_strequ(bf, "sb\n"))
		ft_swap_b(ab);
	else
	{
		ft_swap_a(ab);
		ft_swap_b(ab);
	}
	printf("AFTER 1 = %d 2 = %d\n", ab->a->num, ab->a->next->num);
}
