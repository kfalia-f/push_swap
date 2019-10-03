/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 21:31:44 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/10/03 23:38:17 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ft_rotate_a(t_ab *ab)
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
}

void	ft_rotate_b(t_ab *ab)
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
}

void	ft_rotate_ab(t_ab *ab)
{
	ft_rotate_b(ab);
	ft_rotate_a(ab);
}

void	ft_rotate(char bf[BUFF_SIZE], t_ab *ab)
{
	if (ft_strequ(bf, "ra\n"))
		ft_rotate_a(ab);
	else if (ft_strequ(bf, "rb\n"))
		ft_rotate_b(ab);
	else
	{
		ft_rotate_a(ab);
		ft_rotate_b(ab);
	}
}
