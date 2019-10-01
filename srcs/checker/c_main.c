/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 17:13:39 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/10/01 18:29:21 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int		main(int ac, char **av)
{
	t_ab	ab;
	if (!ft_valid(ac, av))
	{
		ft_putstr_base("Error\n", 2);
		return (0);
	}
	ft_new_ab(&ab);
//	ft_int_cats(ac, av, &ab);
	return (0);
}
