/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 21:31:14 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/10/07 14:32:57 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ft_push_b(t_ab *ab, int fl)
{
	t_stack	*tmp;
	t_stack	*tma;

	if (!ab->a)
		return ;
	tmp = ft_new_node();
	tmp->num = ab->a->num;
	tmp->next = ab->b;
	ab->b = tmp;
	tma = ab->a->next;
	free(ab->a);
	ab->a = tma;
	ab->b_len += 1;
	ab->a_len -= 1;
	if (fl)
		write(1, "pb\n", 3);
}

void	ft_push_a(t_ab *ab, int fl)
{
	t_stack	*tmp;
	t_stack	*tmb;

	if (!ab->b)
		return ;
	tmp = ft_new_node();
	tmp->num = ab->b->num;
	tmp->next = ab->a;
	ab->a = tmp;
	tmb = ab->b->next;
	free(ab->b);
	ab->b = tmb;
	ab->a_len += 1;
	ab->b_len -= 1;
	if (fl)
		write(1, "pa\n", 3);
}

void	ft_push(char bf[BUFF_SIZE], t_ab *ab)
{
	if (ft_strequ(bf, "pa\n"))
		ft_push_a(ab, 0);
	else
		ft_push_b(ab, 0);
}
