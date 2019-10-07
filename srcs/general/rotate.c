/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 21:31:44 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/10/07 14:35:35 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ft_rotate_a(t_ab *ab, int fl)
{
	t_stack	*a;
	t_stack	*tmp;

	if (ab->a_len <= 1)
		return ;
	tmp = ab->a;
	a = ab->a;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = a;
	ab->a = a->next;
	a->next = NULL;
	if (fl)
		write(1, "ra\n", 3);
}

void	ft_rotate_b(t_ab *ab, int fl)
{
	t_stack	*b;
	t_stack	*tmp;

	if (ab->b_len <= 1)
		return ;
	tmp = ab->b;
	b = ab->b;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = b;
	ab->b = b->next;
	b->next = NULL;
	if (fl)
		write(1, "rb\n", 3);
}

void	ft_rotate_ab(t_ab *ab, int fl)
{
	ft_rotate_b(ab, fl);
	ft_rotate_a(ab, fl);
	if (fl)
		write(1, "rr\n", 3);
}

void	ft_rotate(char bf[BUFF_SIZE], t_ab *ab)
{
	if (ft_strequ(bf, "ra\n"))
		ft_rotate_a(ab, 0);
	else if (ft_strequ(bf, "rb\n"))
		ft_rotate_b(ab, 0);
	else
		ft_rotate_ab(ab, 0);
}
