/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_alg.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 23:28:23 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/10/07 18:16:03 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int		ft_check_a_sort(t_ab *ab)
{
	t_stack *tmp;

	tmp = ab->a;
	while (tmp->next)
	{
		if (tmp->num > tmp->next->num)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	ft_sort_a(t_ab *ab)
{
	ft_max_min(ab);
	printf("max = %d, min = %d\n", ab->a_max, ab->a_min);
	while (!ft_check_a_sort(ab))
	{
		if (ab->a->num == ab->a_max)
			ft_rotate_a(ab, 1);
		if (ab->a->next->num == ab->a_max || ab->a->next->num == ab->a_min)
			ft_swap_a(ab, 1);
	}
}

void	ft_minmax_spot(t_ab *ab)
{
	if (ab->b->num > ab->a_max)
	{
		while (ab->a->num != ab->a_max)
			ft_rotate_a(ab, 1);
		ft_rotate_a(ab, 1);
	}
	else if (ab->b->num < ab->a_min)
	{
		while (ab->a->num != ab->a_min)
			ft_rotate_a(ab, 1);
	//	ft_rev_rotate_a(ab, 1);
	}
	ft_push_a(ab, 1);
}

void	ft_find_spot(t_ab *ab, int flag)
{
	int		f;
	int		b;
	t_stack	*tmp;
	flag = 0;
	tmp = ab->a;
	f = 0;
	b = 0;
	//printf("min = %d, max = %d\n", ab->a_min, ab->a_max);
/*	if (ab->b->num > ab->a_max || ab->b->num < ab->a_min)
	{
		ft_minmax_spot(ab);
		return ;
	}
	while (ab->b->num < tmp->num && tmp)
	{
		b++;
		tmp = tmp->next;
	}
	tmp = ab->a;
	while (tmp && ab->b->num > tmp->num)
	{
		f++;
		tmp = tmp->next;
	}
	printf("f = %d, b = %d\n", f, b);
	if (f > b)
		while (f-- > 0)
			ft_rotate_a(ab, 1);
	else
		while (b-- >= 0)
			ft_rotate_a(ab, 1);
	else
	{
		while (ab->a->num > ab->b->num)
		{
			ft_rotate_a(ab, 1);
	//		ft_write(ab);
		}
		ft_write(ab);
		ft_rotate_a(ab, 1);
		ft_putstr("3\n");
	}*/
	ft_push_a(ab, 1);
}

void	ft_alg(t_ab *ab)
{
	if (ft_check_alg(ab))
		return ;
	while (ab->a_len > 3)
		ft_push_b(ab, 1);
	ft_sort_a(ab);
	ft_write(ab);
	while (ab->b_len > 0)
	{
		ft_max_min(ab);
		ft_find_spot(ab, ab->b_len > ab->a_len);
		ft_write(ab);
	}
	ft_write(ab);
	return ;
	while (ft_check_alg(ab) == 0)
	{
		ft_rotate_a(ab, 1);
//		ft_write(ab);
	}
//	ft_write(ab);
}
