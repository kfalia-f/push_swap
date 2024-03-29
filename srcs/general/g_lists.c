/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_lists.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 17:53:43 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/10/07 17:01:15 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ft_new_ab(t_ab *head)
{
	head->a = NULL;
	head->b = NULL;
	head->a_len = 0;
	head->b_len = 0;
	head->a_max = -2147483648;
	head->a_min = 2147483647;
}

t_stack		*ft_new_node()
{
	t_stack	*node;

	if (!(node = (t_stack *)malloc(sizeof(t_stack))))
	{
		ft_putstr_base("doesn't malloced for a new node\n", 2);
		return (NULL);
	}
	node->next = NULL;
	node->num = -1;
	return (node);
}

void	ft_free_stack(t_stack *head)
{
	t_stack *tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

void	ft_free_ab(t_ab *ab)
{
	ft_free_stack(ab->a);
	ft_free_stack(ab->b);
}

int		ft_lstlen(t_stack *head)
{
	int		count;

	count = 0;
	while (head)
	{
		head = head->next;
		count++;
	}
	return (count);
}
