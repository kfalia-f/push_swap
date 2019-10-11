/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_cast.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 17:39:27 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/10/11 16:15:24 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int		ft_error()
{
	ft_putstr_base("Error\n", 2);
	return (0);
}

int		ft_cast_str(char *str, t_ab *ab, t_stack *head, t_stack *tmp)
{
	char		**arr;
	int			i;
	long long	num;

	i = 0;
	arr = ft_strsplit(str, ' ');
	while (arr[i])
	{
		num = ft_atoil(arr[i]);
		i++;
		if (num < -2147483648 || num > 2147483647)
			return (ft_error());
		tmp->num = (int)num;
		if (arr[i])
			tmp->next = ft_new_node();
		tmp = tmp->next;
	}
	ft_mass2del(&arr);
	ab->a = head;
	ab->a_len = ft_lstlen(ab->a);
	return (1);
}

int		ft_int_cast(int ac, char **av, t_ab *ab)
{
	t_stack		*head;
	t_stack		*tmp;
	int			i;
	long long	num;

	i = 1;
	head = ft_new_node();
	tmp = head;
	if (ac == 2)
		return (ft_cast_str(av[1], ab, head, tmp));
	while (i < ac)
	{
		num = ft_atoil(av[i]);
		i++;
		if (num < -2147483648 || num > 2147483647)
			return (ft_error());
		tmp->num = (int)num;
		if (i < ac)
			tmp->next = ft_new_node();
		tmp = tmp->next;
	}
	ab->a = head;
	ab->a_len = ft_lstlen(ab->a);
	return (1);
}
