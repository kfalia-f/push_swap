/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_lists.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 17:53:43 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/10/01 18:29:19 by kfalia-f         ###   ########.fr       */
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
/*
void	ft_new_node(t_stack **head)
{
	*head->next = NULL;

}*/
