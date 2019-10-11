/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 17:13:39 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/10/11 17:08:58 by kfalia-f         ###   ########.fr       */
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
	if (!ft_int_cast(ac, av, &ab))
		return (0);
	if (!ft_valid_nums(&ab))
	{
		ft_free_ab(&ab);
		ft_putstr_base("Error\n", 2);
		return (0);
	}
	if (!ft_check_stack_a(&ab))
	{
		ft_read_commands(&ab);
		ft_check_stack(&ab, 2);
	}
	ft_free_ab(&ab);
	return (0);
}
