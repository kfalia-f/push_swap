/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_helpers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 15:07:26 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/10/07 15:23:44 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ft_max_min(t_ab *ab)
{
	t_stack *tmp;

	tmp = ab->a;
	while (tmp)
	{
		if (tmp->num > ab->a_max)
			ab->a_max = tmp->num;
		if (tmp->num < ab->a_min)
			ab->a_min = tmp->num;
		tmp = tmp->next;
	}
}
