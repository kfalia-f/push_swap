/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 16:21:28 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/10/01 18:21:50 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <libft.h>

typedef struct		s_stack
{
	struct s_stack	*next;
	int				num;
}					t_stack;

typedef struct		s_ab
{
	struct s_stack	*a;
	struct s_stack	*b;
	int				a_len;
	int				b_len;
}					t_ab;

//general
int					ft_test();
int					ft_valid(int ac, char **av);
void				ft_new_ab(t_ab *head);
#endif
