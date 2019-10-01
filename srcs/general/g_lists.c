/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_lists.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 17:53:43 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/10/01 19:50:30 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ft_new_ab(t_ab *head)
{
	head->a = (t_stack *)malloc(sizeof(t_stack));
	head->a->next = NULL;
	head->a->num = -1;
	head->b = (t_stack *)malloc(sizeof(t_stack));
	head->b->next = NULL;
	head->b->num = -1;
	head->a_len = 0;
	head->b_len = 0;
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
