/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 14:24:32 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/10/07 14:24:49 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ft_write(t_ab *ab)
{
	t_stack	*a;
	t_stack	*b;

	a = ab->a;
	b = ab->b;
	printf("a_len = %d, b_len = %d\n", ab->a_len, ab->b_len);
	if (a)
	{
		printf("a: ");
		while (a)
		{
			printf("%d ", a->num);
			a = a->next;
		}
		printf("\n");
	}
	else
		printf("a is empty\n");
	if (b)
	{
		printf("b: ");
		while (b)
		{
			printf("%d ", b->num);
			b = b->next;
		}
		printf("\n");
	}
	else
		printf("b is empty\n");
}
