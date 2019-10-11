/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_read_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 20:58:10 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/10/11 20:26:40 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ft_error_r(t_ab *ab)
{
	ft_putstr("Error\n");
	ft_free_ab(ab);
	exit(0);
}

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
		ft_error_r(ab);
}

void	ft_read_commands(t_ab *ab)
{
	char	bf;
	char	tmp[BUFF_SIZE];
	int		ret;
	int		i;

	ft_bzero(tmp, 5);
	bf = '\0';
	i = -1;
	while ((ret = read(0, &bf, 1)) > 0)
	{
		if (bf && i < 3)
			tmp[++i] = bf;
		if (tmp[i] == '\n')
		{
			tmp[++i] = '\0';
			if (ft_strlen(tmp) == 1)
				return ;
			ft_parser(tmp, ab);
			ft_bzero(tmp, 5);
			i = -1;
		}
		if (i == 3 && bf != '\n')
			ft_error_r(ab);
	//	ft_write(ab);
	}
	if (ft_strlen(tmp) > 1)
		ft_error_r(ab);
}
