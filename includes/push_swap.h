/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 16:21:28 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/10/01 22:53:32 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
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
int					ft_int_cast(int ac, char **av, t_ab *ab);
void				ft_new_ab(t_ab *head);
t_stack				*ft_new_node();
void				ft_free_ab(t_ab *ab);
int					ft_lstlen(t_stack *head);

//checker
void				ft_read_commands(t_ab *ab);
void				ft_swap(char bf[1000], t_ab *ab);
void				ft_push(char bf[1000], t_ab *ab);
void				ft_rotate(char bf[1000], t_ab *ab);
void				ft_reverse_rotate(char bf[1000], t_ab *ab);
#endif
