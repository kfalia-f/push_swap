/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 17:14:13 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/10/07 20:27:30 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int main(int ac, char **av)
{
	t_ab	ab;
	if (!ft_valid(ac, av))
	{
		ft_putstr_base("Error\n", 2);
		return (0);
	}
	ft_new_ab(&ab);
	if (!ft_int_cast(ac, av, &ab))
	{
		ft_write(&ab);
		return (0);
	}
	if (!ft_valid_nums(&ab))
	{
		ft_free_ab(&ab);
		ft_putstr_base("Error\n", 2);
		return (0);
	}
	if (!ft_check_alg(&ab))
		ft_alg(&ab);
	ft_free_ab(&ab);
	return (0);
}
