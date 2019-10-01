/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_cast.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 17:39:27 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/10/01 18:15:39 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ft_int_cats(int ac, char **av, t_ab *ab)
{
	t_stack	*head;
	t_stack	*tmp;
	int		i;

	i = 1;
	head = ab->a;
	ft_new_node(&head);
	tmp = head;
	ab->a = head;
}
