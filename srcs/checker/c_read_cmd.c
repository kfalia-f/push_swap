/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_read_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 20:58:10 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/10/07 14:25:00 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ft_parser(char bf[BUFF_SIZE], t_ab *ab)
{
	ab->a_len = ft_lstlen(ab->a);
	ab->b_len = ft_lstlen(ab->b);
	if (ft_strequ(bf, "sa\n") || ft_strequ(bf, "sb\n") || ft_strequ(bf, "ss\n"))
		ft_swap(bf, ab);
	else if (ft_strequ(bf, "pa\n") || ft_strequ(bf, "pb\n"))
		ft_push(bf, ab);
	else if (ft_strequ(bf, "ra\n") || ft_strequ(bf, "rb\n")
			|| ft_strequ(bf, "rr\n"))
		ft_rotate(bf, ab);
	else if (ft_strequ(bf, "rra\n") || ft_strequ(bf, "rrb\n")
			|| ft_strequ(bf, "rrr\n"))
		ft_reverse_rotate(bf, ab);
	else
	{
		ft_putstr("Error\n");
		ft_free_ab(ab);
		exit(0);
	}
}

void	ft_read_commands(t_ab *ab)
{
	char	bf[BUFF_SIZE];
	int		ret;

	while ((ret = read(1, bf, BUFF_SIZE)) > 0)
	{
		bf[ret] = '\0';
		if (bf[0] == '\n')
			break ;
		ft_parser(bf, ab);
		ft_write(ab);
	}
}
